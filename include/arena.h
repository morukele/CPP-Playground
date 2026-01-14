/*
* Created by Oghenemarho Orukele on 02/01/2026.
* Header file for the memory arena with all the functions
*/

#pragma once
#include <complex>
#include <cstddef>
#include <memory>

class Arena
{
public:
    // Constructor: allocate a raw memory block of a given size
    explicit Arena(std::size_t size)
        : buffer_(static_cast<char*>(::operator new(size)))
        , capacity_(size)
        , offset_(0)
    { }

    // Destructor: free the memory block
    ~Arena()
    {
        ::operator delete(this->buffer_);
    }

    // Allocate memory of `size` bytes with specified `alignment`
    void* allocate(std::size_t size, std::size_t alignment)
    {
        char* current_ptr = this->buffer_ + this->offset_;      // current pointer location i.e. start + offset
        std::size_t space = this->capacity_ - this->offset_;    // available space i.e. capacity - consumed
        void* aligned_ptr = current_ptr;

        // Align the pointer to the specified alignment
        if (std::align(alignment, size, aligned_ptr, space) == nullptr)
        {
            throw std::bad_alloc();
        }

        // Bump offset of the arena
        offset_  = static_cast<char*>(aligned_ptr) - buffer_ + size;

        return aligned_ptr;
    }

    // Reset arena to use the memory from the start
    void reset()
    {
        this->offset_ = 0;
    }

    // Non-copyable, non-moveable type
    Arena(const Arena&) = delete;
    Arena(Arena&&) = delete;

private:
    char* buffer_;          // Start of the allocated memory block
    std::size_t capacity_;  // Capacity of the memory arena
    std::size_t offset_;    // Current allocation offset
};

class ObjArena
{
public:
    explicit ObjArena(std::size_t size)
        : buffer_(static_cast<char*>(::operator new(size)))
        , capacity_(size)
        , offset_(0)
    { }

    ~ObjArena()
    {
        call_destructors();
        ::operator delete(this->buffer_);
    }

    template <typename T, typename... Args>
    T* create(Args&&... args)
    {
        // allocate space for obj
        auto [ptr, new_offset] = allocate(offset_, sizeof(T), alignof(T));

        if constexpr (std::is_trivially_destructible_v<T>)
        {
            // If T is trivially destructible, then just construct object as per normal
            T* obj = new (ptr) T(std::forward<Args>(args)...);
            this->offset_ = new_offset;
            return obj;
        } else
        {
            // Else we need to create a DestructNode, to store destructor to be called later

            // Allocate space for DestructNode
            auto [dnode_ptr, final_offset] = allocate(new_offset,
                sizeof(DestructNode), alignof(DestructNode));

            // Now construct T only after successful allocation
            T* obj = new (ptr) T(std::forward<Args>(args)...);

            auto dtor_call = [](void* p)
            {
                static_cast<T*>(p)->~T();
            };
            auto* new_node = new (dnode_ptr) DestructNode{dtor_call, this->tail_, obj};
            this->tail_ = new_node;

            // Commit offset after successful allocation and construction
            this->offset_ = final_offset;
            return obj;
        }
    }

    void reset()
    {
        call_destructors();
        this->offset_ = 0;
    }

    // Non-copyable, Non-movable type
    ObjArena(const ObjArena&) = delete;
    ObjArena(ObjArena&&) = delete;

private:
    char* buffer_;
    std::size_t capacity_;
    std::size_t offset_;

    struct DestructNode
    {
        void (*dtor)(void*);
        DestructNode* prev;
        void* obj;
    };

    DestructNode* tail_ = nullptr;

    void call_destructors()
    {
        while (this->tail_)
        {
            this->tail_->dtor(this->tail_->obj);
            this->tail_ = this->tail_->prev;
        }
    }

    // Check if we have memory of `size` bytes with specified `alignment`
    [[nodiscard]] std::pair<void*, std::size_t> allocate(std::size_t curr_offset, std::size_t size, std::size_t alignment) const
    {
        char* current_ptr = this->buffer_ + curr_offset;
        std::size_t space = this->capacity_ - curr_offset;
        void* aligned_ptr = current_ptr;

        // Align the ptr to the specified alignment
        if (std::align(alignment, size, aligned_ptr, space) == nullptr)
        {
            throw std::bad_alloc();
        }

        auto new_offset = static_cast<char*>(aligned_ptr) - this->buffer_ + size;

        return {aligned_ptr, new_offset};
    }
};
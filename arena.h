/*
* Created by Oghenemarho Orukele on 02/01/2026.
* Header file for the memory arena with all the functions
*/

#pragma once
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

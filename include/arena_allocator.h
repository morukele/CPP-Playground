/*
* Created by Oghenemarho Orukele on 02/01/2026.
* An exploration into memory arena for efficient memory management in C++ applications
*/
#pragma once
#include "arena.h"

// Implementing the requirements for a custom allocator class
template <typename T>
class ArenaAllocator
{
public:
    using value_type = T;

    explicit ArenaAllocator(Arena* arena) noexcept : arena_(arena) {}

    template <typename U>
    ArenaAllocator(const ArenaAllocator<U>& other) noexcept : arena_(other.arena_) {}

    template <typename U>
    friend class ArenaAllocator;

    T* allocate(std::size_t n)
    {
        return static_cast<T*>(arena_->allocate(n * sizeof(T), alignof(T)));
    }

    void deallocate(T* /*p*/, std::size_t /*n*/) noexcept
    {
        // No-op; arena manages memory lifetime
    }

    bool operator == (const ArenaAllocator& other) const noexcept
    {
        return arena_ == other.arena_;
    }

    bool operator != (const ArenaAllocator& other) const noexcept
    {
        return !(*this == other);
    }

private:
    Arena* arena_;
};
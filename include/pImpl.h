//
// Created by Oghenemarho Orukele on 16/12/2025.
//

#ifndef CPP_PLAYGROUND_PIMPL_H
#define CPP_PLAYGROUND_PIMPL_H

#include <memory>


class ptr_vector_base
{
    // recall that class is private by default.
    struct impl; // forward declaration of impl class & does not depend on T
    std::unique_ptr<impl> pImpl;
protected:
    void push_back_fwd(void*) const;
    void print() const;
public:
    ptr_vector_base();
    ~ptr_vector_base();
};

template <class T>
class ptr_vector : private ptr_vector_base
{
public:
    void push_back(T* p) {push_back_fwd(p);}
    void print() const {ptr_vector_base::print();}
};

#endif //CPP_PLAYGROUND_PIMPL_H
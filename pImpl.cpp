//
// Created by Oghenemarho Orukele on 16/12/2025.
//

#include "pImpl.h"
#include <iostream>
#include <vector>

// implementation of the private implementation class
struct ptr_vector_base::impl
{
    std::vector<void*> vp;

    void push_back(void* p)
    {
        vp.push_back(p);
    }

    void print() const
    {
        for (const auto* p : vp)
        {
            std::cout << p << std::endl;
        }
    }
};

// constructor
ptr_vector_base::ptr_vector_base()
    : pImpl(std::make_unique<impl>())
{

}

void ptr_vector_base::push_back_fwd(void* p) const
{
    pImpl->push_back(p);
}

ptr_vector_base::~ptr_vector_base()
{

}

void ptr_vector_base::print() const
{
    pImpl->print();
}


int main()
{
    int x{}, y{}, z{};
    ptr_vector<int> v;
    v.push_back(&x);
    v.push_back(&y);
    v.push_back(&z);
    v.print();
}
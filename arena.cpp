/*
* Created by Oghenemarho Orukele on 02/01/2026.
*/

#include "include/arena.h"
#include <iostream>

struct Bar
{
    Bar();
    ~Bar()
    {
        std::cout << "non-trivially destructed" << std::endl;
    }
};

int main()
{
    ObjArena arena(1024);
    Bar* bar = arena.create<Bar>();
    std::cout << "End of Scope" << std::endl;
}
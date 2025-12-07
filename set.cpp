//
// Created by Oghenemarho Orukele on 05/12/2025.
//
#include <iostream>
#include <set>

int main()
{
    std::set<int> s1 = {1, 2, 3, 2, 1};

    for (auto s : s1)
    {
        std::cout << s << std::endl;
    }

    int n = 10;
    if (s1.find(n) != s1.end())
    {
        std::cout << n << " is in the set" << std::endl;
    } else
    {
        std::cout << n << " is not in the set" << std::endl;
    }

    return 0;
}
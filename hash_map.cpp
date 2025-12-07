//
// Created by Oghenemarho Orukele on 05/12/2025.
//

/*
 * A hashmap is a data structure in C++ used to store key value pairs
 */
#include <iostream>
#include <unordered_map>

int main()
{
    // Create an unordered map
    std::unordered_map<std::string, int> umap;

    // Insert key-value pairs into the unordered_map
    umap["Apple"] = 10;
    umap["Mango"] = 20;
    umap["Cherry"] = 30;

    // Print the key-value pairs
    for (auto it : umap)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }

    if ( umap.find("Apple") != std::end(umap) )
    {
        std::cout << "There are " << umap["Apple"] << " apple(s) in the umap" << std::endl;
    }
}
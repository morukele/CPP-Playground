#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    for (int i{}; i < 10; i++)
    {
        std::cout << dist(gen) << std::endl;
    }
    

    return 0;
}
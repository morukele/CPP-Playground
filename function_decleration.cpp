//
// Created by Oghenemarho Orukele on 07/12/2025.
//

#include <iostream>

class A
{
public:
    A() {std::cout << "1" << std::endl;}
    A(const A &a) {std::cout << "2" << std::endl;}
    virtual void f() {std::cout << "3" << std::endl;}
    ~A() {std::cout << "4" << std::endl;}
};

class Fahrenheit
{
public:
    Fahrenheit() {std::cout << "A" << std::endl;}
    Fahrenheit(double) {std::cout << "B" << std::endl;} // converting constructor
};

class RoomTemperature
{
public:
    RoomTemperature() : _internal(2)
    {
        _external = 3;
    }

private:
    Fahrenheit _internal;
    Fahrenheit _external;
};

int main()
{
    RoomTemperature roomTemp;
    return 0;
}
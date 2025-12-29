/*
* Created by Oghenemarho Orukele on 29/12/2025.
* Experimentation on building software with CPP
*/

#include <iostream>

class Booking
{
public:
    void setBooking(int id, std::string from, std::string to, int guestNo)
    {
        this->id = id;
        this->from = from;
        this->to = to;
        this->guestNo = guestNo;
    }

    void getBooking()
    {
        std::cout << "Booking ID: " << id << std::endl;
        std::cout << "Date From: " << from << std::endl;
        std::cout << "Guest Number: " << guestNo << std::endl;
    }

    int id;
    std::string from;
    std::string to;
    int guestNo;
};

class Room : public Booking
{
public:
    void setRoom(int id, std::string roomType)
    {
        this->id = id;
        this->roomType = roomType;
    }

    void getRoom()
    {
        std::cout << "Room Id: " << id << std::endl;
        std::cout << "Room type: " << roomType << std::endl;
    }

    int id;
    std::string roomType;
};

class Guest : public Booking
{
public:
    void setGuest(std::string name, std::string surname, int age)
    {
        this->name = name;
        this->surname = surname;
        this->age = age;
    }

    void getGuest()
    {
        std::cout << "Guest Name: " << name << std::endl;
        std::cout << "Surname: " << surname << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

    std::string name;
    std::string surname;
    int age;
};

class Payment : public Booking
{
public:
    void setPayment(int amount, std::string cardNumber)
    {
        this->amount = amount;
        this->cardNumber = cardNumber;
    }

    void getPayment()
    {
        std::cout << "Amount: " << amount << std::endl;
        std::cout << "Card Number: " << cardNumber << std::endl;
    }

    int amount;
    std::string cardNumber;
};

int main()
{
    Guest guest;
    Room room;

    room.setBooking(1001, "29-Dec-2025", "06-01-2026", 2);
    room.setRoom(201, "The other room");
    room.getRoom();
    room.getBooking();
}
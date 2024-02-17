// Authot: Christian Jeune, ID: 40279265

#include "Passenger.h"
#include <iostream>
using namespace std;

int Passenger::passengerCount = 0;

// Default constructor
Passenger::Passenger() 
{
    name = "N/A";
    address = "N/A";
    phone = "N/A";
    id = "###";
    passengerCount++;
}

// Parameterized constructor
Passenger::Passenger(string name, string address, string phone) 
{
    this->name = name;
    this->address = address;
    this->phone = phone;
    passengerCount++;
    id = createPassengerId();
}

Passenger::Passenger(const Passenger &obj) : id(obj.id)
{
    name = obj.name;
    address = obj.address;
    phone = obj.phone;
}

// Destructor
Passenger::~Passenger()
{
    cout << "Passenger " << id << " is being deleted" << endl;
}

// Getters
string Passenger::getName() const
{
    return name;
}

string Passenger::getId() const
{
    return id;
}

string Passenger::getAddress() const
{
    return address;
}

string Passenger::getPhone() const
{
    return phone;
}

// Setters

void Passenger::setName(string name)
{
    this->name = name;
    id = createPassengerId();
}

void Passenger::setAddress(string address)
{
    this->address = address;
}

void Passenger::setPhone(string phone)
{
    this->phone = phone;
}

// Create a unique id for the passenger
string Passenger::createPassengerId() const
{
    return name.substr(0, 2) + to_string(passengerCount);
}

void Passenger::printPassenger() const
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
}
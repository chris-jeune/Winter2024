// Authot: Christian Jeune, ID: 40279265

#include "Passenger.h"
#include <iostream>
#include "Booking.h"
using namespace std;

int Passenger::passengerCount = 0;

// Default constructor
Passenger::Passenger():name("N/A"),address("N/A"),phone("N/A"),id("###") 
{
    bookingCount = 0;
}

// Parameterized constructor
Passenger::Passenger(string name, string address, string phone):name(name),address(address),phone(phone)
{
    passengerCount++;
    id = createPassengerId();
    bookingCount = 0;
}

Passenger::Passenger(const Passenger &obj) : name(obj.name), address(obj.address), phone(obj.phone), id(obj.id)
{
    cout<<"Copy constructor called"<<endl;
    bookingCount = obj.bookingCount;
    if(bookingCount>0){
    bookings= new Booking[bookingCount];
    for(int i=0; i<bookingCount;i++){
        bookings[i].setPassenger(this);
        bookings[i].setSeatNumber(obj.bookings[i].getSeatNumber());
        bookings[i].setFlight(obj.bookings[i].getFlight());
    }
    }
}


// Destructor
Passenger::~Passenger()
{
    cout << "Passenger " << id << " is being deleted" << endl;
    if (bookingCount > 0)
    {
        delete[] bookings;
    }
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

void Passenger::listBookings() const
{
    cout<< "Bookings for Passenger "<<id<<endl;
    
        for (int i = 0; i < bookingCount; i++)
        {
            cout<<"Seat: "<<bookings[i].getSeatNumber()<<endl;
            cout<<"Flight: "<<bookings[i].getFlight()->getFlightIdent()<<endl;
            cout<<endl;
        }
}

void Passenger::addBooking(Booking *  b, Flight *fl){
    if(bookingCount==0){
        bookings = new Booking[1];
        bookings[0].setPassenger(this);
        bookings[0].setSeatNumber(b->getSeatNumber());
        bookings[0].setFlight(fl);
    }
    else{
        Booking *temp = new Booking[bookingCount+1];
        for(int i=0; i<bookingCount; i++){
            temp[i].setPassenger(this);
            temp[i].setSeatNumber(bookings[i].getSeatNumber());
            temp[i].setFlight(fl);
        }
        temp[bookingCount].setPassenger(this);
        temp[bookingCount].setSeatNumber(b->getSeatNumber());
        temp[bookingCount].setFlight(fl);
        delete [] bookings;
        bookings = temp;
    }
}
// Authot: Christian Jeune, ID: 40279265

#include "Passenger.h"
#include <iostream>
#include "Booking.h"

using namespace std;

int Passenger::passengerCount = 0;

// Default constructor
Passenger::Passenger() : name("N/A"), address("N/A"), phone("N/A"), id("###"), bookings(nullptr)
{
    bookingCount = 0;
}

// Parameterized constructor
Passenger::Passenger(string name, string address, string phone) : name(name), address(address), phone(phone), bookings(nullptr)
{
    passengerCount++;
    id = createPassengerId();
    bookingCount = 0;
}

// Copy constructor
Passenger::Passenger(const Passenger &obj) : name(obj.name), address(obj.address), phone(obj.phone), id(obj.id)
{
    bookingCount = obj.bookingCount;
    if (bookingCount > 0)
    {
        bookings = new Booking[bookingCount];
        for (int i = 0; i < bookingCount; i++)
        {
            bookings[i]=Booking(obj.bookings[i]);
            bookings[i].setPassenger(this);
        }
    }
}

// Destructor
Passenger::~Passenger()
{
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

// Print passenger details
void Passenger::printPassenger() const
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
}

// List all bookings for the passenger
void Passenger::listBookings() const
{
    cout << "Bookings for Passenger " << name << " (" << id << ")" << endl;
    for (int i = 0; i < bookingCount; i++)
    {
        cout << "Seat: " << bookings[i].getSeatNumber() << endl;
        cout << "Flight: " << bookings[i].getFlight()->getFlightIdent() << endl;
        cout << endl;
    }
}

// Add a booking to the passenger
void Passenger::addBooking(Booking *b)
{
    if (bookingCount == 0)
    {
        // If there are no existing bookings, create a new array with a single booking
        bookings = new Booking[1];
        bookings[0]=*b;
    }
    else
    {
        // If there are existing bookings, create a temporary array with increased size
        Booking *temp = new Booking[bookingCount + 1];
        // Copy existing bookings to the temporary array
        for (int i = 0; i < bookingCount; i++)
        {
            temp[i]=bookings[i];
        }
        // Add the new booking to the temporary array
        temp[bookingCount]=*b;
        // Delete the old bookings array and assign the temporary array to it
        delete[] bookings;
        bookings = temp;
    }
}

#include "Booking.h"
#include <iostream>

using namespace std;

int Booking::bookingCount = 0;  

Booking::Booking() : passenger(), flight() {
    seatNumber = "";
}

Booking::Booking(const Passenger &passenger, const Flight &flight): passenger(passenger), flight(flight) {
    bookingCount++;
    this->seatNumber = createSeatNumber();

    }

Booking::Booking(const Booking &other): passenger(other.passenger), flight(other.flight), seatNumber(other.seatNumber) {}

const Passenger &Booking::getPassenger() const
{
    return passenger;
}

const Flight &Booking::getFlight() const
{
    return flight;
}

const string &Booking::getSeatNumber() const
{
    return seatNumber;
}

string Booking::createSeatNumber()
{
    string seatNumber = "";
    int row = 1 + (bookingCount / 6);
    int column = (bookingCount % 6);
    seatNumber += static_cast<char>('A' + row);
    seatNumber += to_string(column);

    return seatNumber;
}
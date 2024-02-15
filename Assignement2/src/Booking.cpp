// Author: Christian Jeune, ID: 40279265

#include "Booking.h"
#include "Passenger.h"
#include "Flight.h"
#include <iostream>
#include <string>

using namespace std;

int Booking::bookingCount = 0;

Booking::Booking(){
    passenger=nullptr;
    flight= nullptr;
    seatNumber="";
}

Booking::Booking(Passenger & pass, const string & ident, Airline & airline) {
    bookingCount++;
    seatNumber=createSeatNumber();
        // Find the index of the flight to book
    int i = 0;

    for (; i < airline.numFlights; i++) {
        if (airline.flights[i].getFlightIdent() == ident) {
            break;
        }
    }

    passenger = &pass;
    flight = &airline.flights[i];

    pass.addBooking(*this);
    airline.flights[i].addBooking(*this);
    
}

Booking::Booking(const Booking &obj) {
    passenger = &(*obj.passenger);
    flight = &(*obj.flight);
    bookingCount++;
    seatNumber = createSeatNumber();
}

Booking::~Booking(){
    delete passenger;
    delete flight;
    bookingCount--;
}

Passenger  Booking::getPassenger() const{
    return *passenger;
}

Flight   Booking::getFlight() const{
    return *flight;
}

string Booking::getSeatNumber() const{
    return seatNumber;
}

int Booking::getBookingCount(){
    return bookingCount;
}

string Booking::createSeatNumber() const{
    string seatNumber = "";
    int row = 1 + (bookingCount / 6);
    int column = 1 + (bookingCount % 6);
    seatNumber += static_cast<char>('A' + row);
    seatNumber += to_string(column);

    return seatNumber;
}

Booking & Booking::operator=(const Booking &obj) {
    if (this != &obj) {
        delete passenger;
        delete flight;
        passenger = &(*obj.passenger);
        flight = &(*obj.flight);
        seatNumber = obj.seatNumber;
    }
    return *this;
}
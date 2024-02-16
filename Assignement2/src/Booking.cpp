// Author: Christian Jeune, ID: 40279265

#include "Booking.h"
#include "Passenger.h"
#include "Flight.h"
#include <iostream>


using namespace std;

int Booking::bookingCount = 0;

Booking::Booking(){
    passenger=nullptr;
    flight= nullptr;
    seatNumber="";
}

Booking::Booking(Passenger & pass, string ident, Airline & airline) {

    // Find the index of the flight to book
    int i = 0;

    for (; i < airline.numFlights; i++) {
        if (airline.flights[i].getFlightIdent() == ident) {
            break;
        }
    }

    if (i == airline.numFlights) {
        cout << "Flight not found" << endl;
        passenger=nullptr;
        flight= nullptr;
        
    }

    else{
        if(airline.flights[i].bookingCount>=Flight::MAX_SEATS){
            cout<<"Flight is full"<<endl;
            passenger=nullptr;
            flight= nullptr;
        }
        else{
            passenger = &pass;
            flight = &airline.flights[i];
            seatNumber = createSeatNumber();
            bookingCount++;
            if(airline.flights[i].addBooking(*this)){
                pass.addBooking(*this);

            }
        }

    }

}

Booking::Booking(const Booking &obj): passenger(obj.passenger), flight(obj.flight), seatNumber(obj.seatNumber){
    cout<<"Booking copy constructor"<<endl;
}


Passenger * Booking::getPassenger() const{
    return passenger;
}

Flight  * Booking::getFlight() const{
    return flight;
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

void Booking::cancelBooking(Passenger & pass, string bookid, string flid, Airline & airline) {
    if ( pass.getBooking(bookid)== nullptr) {
        cout << "No bookings to cancel" << endl;
        return;
    }
    int i = 0;

    for (; i < airline.numFlights; i++) {
        if (airline.flights[i].getFlightIdent() == flid) {
            break;
        }
    }

    if (i == airline.numFlights) {
        cout << "Flight not found" << endl;
    }

    else {
        if (pass.cancelBooking(bookid)) {
        airline.flights[i].cancelBooking(bookid);
    }
    }
}

void Booking::printBooking() const {
    cout << "Booking Information" << endl;
    cout << "Passenger: " << passenger->getName()<<", ID: "<<passenger->getId() << endl;
    cout << "Flight: " << flight->getFlightIdent() << endl;
    cout << "Seat Number: " << seatNumber << endl;
}
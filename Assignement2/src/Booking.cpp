// Author: Christian Jeune, ID: 40279265

#include "Booking.h"
#include "Passenger.h"
#include "Flight.h"
#include <iostream>

using namespace std;

int Booking::bookingCount = 0;

// Default constructor initializes member variables
Booking::Booking():passenger(nullptr), flight(nullptr), seatNumber("noseat")
{
}

// Parameterized constructor for creating a booking
Booking::Booking(Passenger &pass, string ident, Airline &airline) : passenger(nullptr), flight(nullptr), seatNumber("noseat")
{
    // Find the index of the flight to book
    int i = 0;
    for (; i < airline.numFlights; i++)
    {
        if (airline.flights[i].getFlightIdent() == ident)
        {
            break;
        }
    }

    // If flight not found, print error message and return
    if (i == airline.numFlights)
    {
        cout << "Flight not found" << endl;
        return; // Early return in case of error
    }

    // Check if the flight is full
    if (airline.flights[i].bookingCount >= Flight::MAX_SEATS)
    {
        cout << "Flight is full" << endl;
        return; // Early return in case of error
    }

    // Create the booking
    seatNumber = creatSeatNumber(); // Generate a seat number
    bookingCount++; // Increment booking count
    passenger = &pass; // Set the passenger
    flight = &(airline.flights[i]); // Set the flight
    airline.flights[i].addBooking(this, &pass); // Add booking to flight
    pass.addBooking(this, &(airline.flights[i])); // Add booking to passenger
    airline.flights[i].bookingCount++; // Increment booking count for flight
    pass.bookingCount++; // Increment booking count for passenger
}

// Copy constructor for creating a booking object based on an existing booking
Booking::Booking(const Booking &obj) : seatNumber(obj.seatNumber)
{
    if(obj.passenger==nullptr || obj.flight==nullptr){
        passenger=nullptr;
        flight=nullptr;
        return;
    }
    // Iterate through the flights of the booking associated with the original object
    for(int i = 0; i < obj.flight->bookingCount; i++) {
        // Check if the seat number and flight identifier match
        if(obj.passenger->bookings[i].seatNumber == obj.seatNumber && obj.passenger->bookings[i].getFlight()->flightIdent == obj.flight->flightIdent) {
            // If there is a match, update the passenger, flight, and generate a new seat number
            passenger = obj.passenger;
            flight = obj.flight;
            seatNumber = creatSeatNumber();
            bookingCount++;
            return;
        }
    }
    
    // If no match is found, update the passenger and flight without changing the seat number
    passenger = obj.passenger;
    flight = obj.flight;    
}

// Getter function to retrieve the passenger associated with the booking
Passenger * Booking::getPassenger() const
{
    return passenger;
}

// Getter function to retrieve the flight associated with the booking
Flight * Booking::getFlight() const
{
    return flight;
}

// Getter function to retrieve the seat number of the booking
string Booking::getSeatNumber() const
{
    return seatNumber;
}

// Setter function to set the passenger associated with the booking
void Booking::setPassenger(Passenger * pass)
{ 
    passenger = pass;
}

// Setter function to set the flight associated with the booking
void Booking::setFlight(Flight * fl)
{
    flight = fl;
}

// Setter function to set the seat number of the booking
void Booking::setSeatNumber(string seat)
{
    seatNumber = seat;
}

// Function to cancel a booking
void Booking::cancelBooking(Passenger& pass, string bookid, string flid) {
    // Find the flight index based on the flight identifier
    int flightIndex = -1;
    for (int i = 0; i < pass.bookingCount; i++) {
        if (pass.bookings[i].flight->flightIdent == flid) {
            flightIndex = i;
            break;
        }
    }

    // If flight not found, print error message and return
    if (flightIndex == -1) {
        std::cout << "Flight not found" << std::endl;
        return;
    }

    // Find the seat index based on the seat number
    int seatIndex = -1;
    for (int k = 0; k < pass.bookings[flightIndex].flight->bookingCount; k++) {
        if (pass.bookings[flightIndex].flight->bookings[k].seatNumber == bookid) {
            seatIndex = k;
            break;
        }
    }

    // If seat not found, print error message and return
    if (seatIndex == -1) {
        std::cout << "The seat " << bookid << " was not booked for this flight" << std::endl;
        return;
    }

    // Print a message indicating the cancellation of the booking
    std::cout << "Booking " << pass.bookings[flightIndex].seatNumber << " from Flight " << pass.bookings[flightIndex].flight->flightIdent << " is being cancelled" << std::endl;

    // Shift bookings in Flight to remove the cancelled booking
    for (int l = seatIndex; l < pass.bookings[flightIndex].flight->bookingCount - 1; l++) {
        pass.bookings[flightIndex].flight->bookings[l] = pass.bookings[flightIndex].flight->bookings[l + 1];
    }

    // Decrease booking count in Flight
    --pass.bookings[flightIndex].flight->bookingCount;

    // Reallocate memory for Flight bookings
    Booking* newFlightBookings = new Booking[pass.bookings[flightIndex].flight->bookingCount];
    for (int l = 0; l < pass.bookings[flightIndex].flight->bookingCount; l++) {
        newFlightBookings[l] = pass.bookings[flightIndex].flight->bookings[l];
    }
    delete[] pass.bookings[flightIndex].flight->bookings;
    pass.bookings[flightIndex].flight->bookings = newFlightBookings;

    // Shift bookings in Passenger to remove the cancelled booking
    for (int l = flightIndex; l < pass.bookingCount - 1; l++) {
        pass.bookings[l] = pass.bookings[l + 1];
    }

    // Decrease booking count in Passenger
    --pass.bookingCount;

    // Reallocate memory for Passenger bookings
    Booking* newBookings = new Booking[pass.bookingCount];
    for (int l = 0; l < pass.bookingCount; l++) {
        newBookings[l] = pass.bookings[l];
    }
    delete[] pass.bookings;
    pass.bookings = newBookings;

}

// Destructor to release memory and clean up
Booking::~Booking()
{
    passenger=nullptr;
    flight=nullptr;
}

// Function to print booking details
void Booking::printBooking()const
{
    // Check if the booking has a passenger associated with it
    if(passenger!=nullptr){
        cout << "Booking Details" << endl;
        cout << "Passenger: " << passenger->getName() << endl;
        cout << "Flight: " << flight->getFlightIdent() << endl;
        cout << "Seat: " << seatNumber << endl;
    }
    else{
        cout<<"Booking is empty"<<endl;
    }
}

// Function to generate a seat number for the booking
string Booking::creatSeatNumber() const
{
    string seat = "";
    int row = (bookingCount / 6); // Determine row number based on booking count
    int column = 1 + (bookingCount % 6); // Determine column number based on booking count
    seat += static_cast<char>('A' + row); // Convert row number to character (A, B, C, ...)
    seat += to_string(column); // Append column number
    return seat;
}

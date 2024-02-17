// Author: Christian Jeune, ID: 40279265

#include "Booking.h"
#include "Passenger.h"
#include "Flight.h"
#include <iostream>

using namespace std;

int Booking::bookingCount = 0;

Booking::Booking():passenger(nullptr), flight(nullptr), seatNumber("noseat")
{
}

Booking::Booking(Passenger &pass, string ident, Airline &airline):passenger(nullptr), flight(nullptr), seatNumber("noseat")
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

    if (i == airline.numFlights)
    {
        cout << "Flight not found" << endl;

            passenger = new Passenger();
            flight = new Flight();
       
    }

    else
    {
        if (airline.flights[i].bookingCount >= Flight::MAX_SEATS)
        {
            cout << "Flight is full" << endl;

                passenger = new Passenger();
                flight = new Flight();
            
        }
        else if (pass.bookingCount >= Passenger::MAX_BOOKINGS)
        {
            cout << "Passenger has too many bookings" << endl;

                passenger = new Passenger();
                flight = new Flight();
            
        }
        else
        {
            seatNumber ="";
                int row = 1 + (bookingCount / 6);
    int column = 1 + (bookingCount % 6);
    seatNumber += static_cast<char>('A' + row);
    seatNumber += to_string(column);
            bookingCount++;
            passenger = &pass;
            flight = &airline.flights[i];
            airline.flights[i].addBooking(this, &pass);
            pass.addBooking(this, &airline.flights[i]);
            airline.flights[i].bookingCount++;
            pass.bookingCount++;
                cout<<"Booking "<<seatNumber<<" from Flight "<<airline.flights[i].flightIdent<<" is being created"<<endl;

            

        }
    }
}

Booking::Booking(const Booking &obj) : seatNumber(obj.seatNumber)
{
        cout << "Booking copy constructor" << endl;
        passenger = obj.passenger;
        flight = obj.flight;
    
}

Passenger * Booking::getPassenger() const
{
    return passenger;
}

Flight * Booking::getFlight() const
{
    
    return flight;
}

string Booking::getSeatNumber() const
{
    return seatNumber;
}

void Booking::setPassenger(Passenger * pass)
{ 
        passenger = pass;
}

void Booking::setFlight(Flight * fl)
{
        flight = fl;
   
}

void Booking::setSeatNumber(string seat)
{
    seatNumber = seat;
}


void Booking::cancelBooking(Passenger &pass, string bookid, string flid, Airline &airline)
{
    int j = 0;
    for (; j < pass.bookingCount; j++)
    {
        if (pass.bookings[j].getSeatNumber() == bookid)
        {
            break;
        }
    }
    if (j == pass.bookingCount)
    {
        cout << "No bookings to cancel for passenger" << pass.id << endl;
        return;
    }

    int i = 0;
    for (; i < airline.numFlights; i++)
    {
        if (airline.flights[i].getFlightIdent() == flid)
        {
            break;
        }
    }

    if (i == airline.numFlights)
    {
        cout << "Flight not found" << endl;
        return;
    }

    int k = 0;
    for (; k < airline.flights[i].bookingCount; k++)
    {
        if (airline.flights[i].bookings[k].getSeatNumber() == bookid)
        {
            break;
        }
    }

    if (k == airline.flights[i].bookingCount)
    {
        cout << "The seat " << bookid << " was not booked for this flight" << endl;
        return;
    }

    else
    {
        cout << "Booking " << pass.bookings[j].getSeatNumber() << " from Flight " << airline.flights[i].flightIdent << " is being cancelled" << endl;
        for (int l = j; l < pass.bookingCount - 1; l++)
        {
            pass.bookings[l].setPassenger(pass.bookings[l + 1].getPassenger());
            pass.bookings[l].setSeatNumber(pass.bookings[l + 1].getSeatNumber());
            pass.bookings[l].setFlight(pass.bookings[l + 1].getFlight());
        }
        pass.bookingCount--;

        for (int l = k; l < airline.flights[i].bookingCount - 1; l++)
        {
            airline.flights[i].bookings[l].setPassenger(airline.flights[i].bookings[l + 1].getPassenger());
            airline.flights[i].bookings[l].setSeatNumber(airline.flights[i].bookings[l + 1].getSeatNumber());
            airline.flights[i].bookings[l].setFlight(airline.flights[i].bookings[l + 1].getFlight());
        }
        airline.flights[i].bookingCount--;
    }
}

Booking::~Booking()
{
    cout << "Booking " << seatNumber << " is being deleted" << endl;
    passenger=nullptr;
    flight=nullptr;
}
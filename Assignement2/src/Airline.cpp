// Author: Christian Jeune, ID: 40279265 

#include "Airline.h"
#include <iostream>
#include "Flight.h"
#include "Passenger.h"
#include "Booking.h"
#include "Time.h"

using namespace std;

int Airline::copyCount = 0;

// Default constructor
Airline::Airline() : airLineName("N/A"), airLineAddress("N/A"), airLinePhone("N/A"), numFlights(0) {
    flights = nullptr;
}

// Parameterized constructor
Airline::Airline(string name, string address, string phone, int number)
    : airLineName(name), airLineAddress(address), airLinePhone(phone), numFlights(number), flights(nullptr) {
}

// Copy constructor
Airline::Airline(const Airline &obj) : airLineName(obj.airLineName+'-'+to_string(++copyCount)), airLineAddress(obj.airLineAddress), airLinePhone(obj.airLinePhone), numFlights(obj.numFlights) {
    if (numFlights == 0) {
        flights = nullptr;
        return;
    }
    // Allocate memory for flights array
    flights = new Flight[numFlights];
    // Copy each flight from the original object to the new object
    for (int i = 0; i < numFlights; i++) {
        delete flights[i].departureTime;
        delete flights[i].arrivalTime;
        flights[i] = obj.flights[i];
        // Deep copy the bookings object
        if(obj.flights[i].bookingCount > 0)
        flights[i].setBookings(obj.flights[i].bookings, int(obj.flights[i].bookingCount));
        // Deep copy the departure time object
        flights[i].setDepartureTime(Time(obj.flights[i].getDepartureTime()));
        // Deep copy the arrival time object
        flights[i].setArrivalTime(Time(obj.flights[i].getArrivalTime()));
        // Update the flight identifier for each copied flight
        updateFlightIdent(flights[i]);
    }
}

// Parameterized constructor to initialize with an array of flights
Airline::Airline(string name, string address, string phone, Flight * list, int number): airLineName(name), airLineAddress(address), airLinePhone(phone), numFlights(number) {
    if (number == 0) {
        flights = nullptr;
        return;
    }
    flights = new Flight[number];
    for (int i = 0; i < number; i++) {
        delete flights[i].departureTime;
        delete flights[i].arrivalTime;
        flights[i] = list[i];
        // Deep copy the bookings object
        if(list[i].bookingCount > 0)
            flights[i].setBookings(list[i].bookings, int(list[i].bookingCount));
        // Deep copy the departure time object
        flights[i].setDepartureTime(list[i].getDepartureTime());
        // Deep copy the arrival time object
        flights[i].setArrivalTime(list[i].getArrivalTime());
        // Update the flight identifier for each copied flight
        updateFlightIdent(flights[i]);
    }
}

// Destructor
Airline::~Airline() {
    if(numFlights > 0)
        delete[] flights;
}

// Getters
string Airline::getAirLineName() const {
    return airLineName;
}

string Airline::getAirLineAddress() const {
    return airLineAddress;
}

string Airline::getAirLinePhone() const {
    return airLinePhone;
}

// Setters
void Airline::setAirLineAddress(const string&address) {
    airLineAddress = address;
}

void Airline::setAirLinePhone(string phone) {
    airLinePhone = phone;
}

// Add a flight to the airline
void Airline::addFlight(const string & dep, const string & arr, const Time & depTime, const  Time & arrTime) {     
    // Create a new flight object
    Flight temp(dep, arr, depTime, arrTime);                                   
    // Create a new array with increased size
    Flight* newFlights = new Flight[numFlights + 1];
    
    // Copy existing flights to the new array
    for (int i = 0; i < numFlights; i++) {
        delete newFlights[i].departureTime;
        delete newFlights[i].arrivalTime;
        newFlights[i] = flights[i];
        // Deep copy the bookings object
        if(flights[i].bookingCount>0)
        newFlights[i].setBookings(flights[i].bookings, int(flights[i].bookingCount));
        // Deep copy the departure time object
        newFlights[i].setDepartureTime(Time(flights[i].getDepartureTime()));
        // Deep copy the arrival time object
        newFlights[i].setArrivalTime(Time(flights[i].getArrivalTime()));

    }
    
    // Add the new flight to the end of the array
    delete newFlights[numFlights].departureTime;
    delete newFlights[numFlights].arrivalTime;
    newFlights[numFlights]= temp;
    newFlights[numFlights].setDepartureTime(depTime);
    newFlights[numFlights].setArrivalTime(arrTime);
    updateFlightIdent(newFlights[numFlights]);

    // Delete the old array
    if(numFlights > 0)
    delete[] flights;
    
    // Update the flights pointer to point to the new array
    flights = newFlights;
    
    // Increment the number of flights
    numFlights++;
}

// Add a flight to the airline
void Airline::addFlight(Flight & flight) {                                         
    // Create a new array with increased size
    Flight* newFlights = new Flight[numFlights + 1];
    
    // Copy existing flights to the new array
    for (int i = 0; i < numFlights; i++) {
        delete newFlights[i].departureTime;
        delete newFlights[i].arrivalTime;
        newFlights[i] = flights[i];
        // Deep copy the bookings object
        if(flights[i].bookingCount>0)
        newFlights[i].setBookings(flights[i].bookings, int(flights[i].bookingCount));
        // Deep copy the departure time object
        newFlights[i].setDepartureTime(Time(flights[i].getDepartureTime()));
        // Deep copy the arrival time object
        newFlights[i].setArrivalTime(Time(flights[i].getArrivalTime()));
    }
    
    // Add the new flight to the end of the array
    delete newFlights[numFlights].departureTime;
    delete newFlights[numFlights].arrivalTime;
    newFlights[numFlights]=flight;
        // Deep copy the bookings object
        if(flight.bookingCount>0)
        newFlights[numFlights].setBookings(flight.bookings, int(flight.bookingCount));
        // Deep copy the departure time object
        newFlights[numFlights].setDepartureTime(Time(flight.getDepartureTime()));
        // Deep copy the arrival time object
        newFlights[numFlights].setArrivalTime(Time(flight.getArrivalTime()));
        // Update the flight identifier for each copied flight
        updateFlightIdent(newFlights[numFlights]);

    // Delete the old array
    if(numFlights > 0)
    delete[] flights;
    
    // Update the flights pointer to point to the new array
    flights = newFlights;
    
    // Increment the number of flights
    numFlights++;
}

// Add multiple flights to the airline
void Airline::addFlight(Flight * list,int number){

    Flight* newFlights = new Flight[numFlights + number];
    int i = 0;
    for (; i < numFlights; i++) {
        delete newFlights[i].departureTime;
        delete newFlights[i].arrivalTime;
        newFlights[i] = flights[i];
        // Deep copy the bookings object
        if(flights[i].bookingCount>0)
        newFlights[i].setBookings(flights[i].bookings, int(flights[i].bookingCount));
        // Deep copy the departure time object
        newFlights[i].setDepartureTime(Time(flights[i].getDepartureTime()));
        // Deep copy the arrival time object
        newFlights[i].setArrivalTime(Time(flights[i].getArrivalTime()));

    }

    for (int j = 0; j < number; j++) {
        delete newFlights[i].departureTime;
        delete newFlights[i].arrivalTime;
        newFlights[i]=list[j];
        // Deep copy the bookings object
        if(list[j].bookingCount>0)
        newFlights[i].setBookings(list[j].bookings, int(list[j].bookingCount));
        // Deep copy the departure time object
        newFlights[i].setDepartureTime(Time(list[j].getDepartureTime()));
        // Deep copy the arrival time object
        newFlights[i].setArrivalTime(Time(list[j].getArrivalTime()));
        // Update the flight identifier for each copied flight
        updateFlightIdent(newFlights[i]);
        i++;
    }
    if(numFlights > 0)
    delete[] flights;
    flights = newFlights;
    numFlights+=number;
}

// Remove a flight from the airline
void Airline::removeFlight(string ident) {
    // Check if there are any flights to remove
    if(numFlights == 0) {
        cout << "No flights to remove." << endl;
        return;
    }

    // Find the index of the flight to remove
    int i = 0;
    for (; i < numFlights; i++) {
        if (flights[i].getFlightIdent() == ident) {
            break;
        }
    }

    // If the flight is not found
    if (i == numFlights) {
        cout << "Flight not in system" << endl;
        return;
    }

    // Move all flights after the flight to remove one position to the left
    for (; i < numFlights - 1; i++) {
        delete flights[i].departureTime;
        delete flights[i].arrivalTime;
        flights[i]=flights[i+1];
        // Deep copy the bookings object
        if(flights[i].bookingCount>0)
        flights[i].setBookings(flights[i+1].bookings, int(flights[i+1].bookingCount));
        // Deep copy the departure time object
        flights[i].setDepartureTime(Time(flights[i+1].getDepartureTime()));
        // Deep copy the arrival time object
        flights[i].setArrivalTime(Time(flights[i+1].getArrivalTime()));

    }
    
    // Reduce the size of the flights array
    Flight* temp = new Flight[--numFlights];
    for (i = 0; i < numFlights; i++) {
        delete temp[i].departureTime;
        delete temp[i].arrivalTime;
        temp[i]=flights[i];
        // Deep copy the bookings object
        if(flights[i].bookingCount>0)
        temp[i].setBookings(flights[i].bookings, int(flights[i].bookingCount));
        // Deep copy the departure time object
        temp[i].setDepartureTime(Time(flights[i].getDepartureTime()));
        // Deep copy the arrival time object
        temp[i].setArrivalTime(Time(flights[i].getArrivalTime()));

    }
    delete[] flights;
    flights = temp;
}

// List all flights in the airline
void Airline::listFlights() const {
    for (int i = 0; i < numFlights; i++) {
        cout << flights[i].getFlightIdent() <<", available seats: "<< Flight::MAX_SEATS-flights[i].bookingCount<< endl;
    }
}

// List flights with a specific departure and arrival city
void Airline::listFlights(string depCity, string arrCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getDeparture() == depCity && flights[i].getArrival() == arrCity) {
            cout << flights[i].getFlightIdent() <<", available seats: "<< Flight::MAX_SEATS-flights[i].bookingCount<< endl;
        }
    }
}

// List flights with a specific departure city
void Airline::listFlightsDep(string depCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getDeparture() == depCity) {
            cout << flights[i].getFlightIdent() <<", available seats: "<< Flight::MAX_SEATS-flights[i].bookingCount<< endl;
        }
    }
}

// List flights with a specific arrival city
void Airline::listFlightsArr(string arrCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getArrival() == arrCity) {
            cout << flights[i].getFlightIdent() <<", available seats: "<< Flight::MAX_SEATS-flights[i].bookingCount<< endl;
        }
    }
}

// Get the number of flights in the airline
int Airline::getNumFlights() const {
    return numFlights;
}

// Update the flight identifier based on the airline name
void Airline::updateFlightIdent(Flight & flight){
    bool hasInitial = false;   
    // Initialize the identifier with the initials of the airline name
    string initial = "";
    for (char elem : airLineName) {
        if (isupper(elem)) {
            initial += elem;
        }
    }

    for(char elem: flight.flightIdent){
        for (char elem2 : initial) {
            if (elem == elem2) {
                hasInitial = true;
                break;
            }
        }
    }
    if(!hasInitial)
    // Append the initial to the flight identifier
    flight.flightIdent = initial + flight.flightIdent;
}
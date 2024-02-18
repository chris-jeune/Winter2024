// Author: Christian Jeune, ID: 40279265 

#include "Airline.h"
#include <iostream>
#include "Flight.h"
#include "Passenger.h"

using namespace std;

// Default constructor
Airline::Airline() : airLineName("N/A"), airLineAddress("N/A"), airLinePhone("N/A"), numFlights(0) {
    flights = nullptr;
}

// Parameterized constructor
Airline::Airline(string name, string address, string phone, int number)
    : airLineName(name), airLineAddress(address), airLinePhone(phone), numFlights(number) {
    
    this->flights = new Flight[number];
}

// Copy constructor
Airline::Airline(const Airline &obj) : airLineName(obj.airLineName), airLineAddress(obj.airLineAddress), airLinePhone(obj.airLinePhone), numFlights(obj.numFlights) {
    // Allocate memory for flights array
    flights = new Flight[numFlights];
    // Copy each flight from the original object to the new object
    for (int i = 0; i < numFlights; i++) {
        flights[i] = obj.flights[i];
        // Update the flight identifier for each copied flight
        updateFlightIdent(flights[i]);
    }
}

// Parameterized constructor to initialize with an array of flights
Airline::Airline(string name, string address, string phone, Flight * list, int number): airLineName(name), airLineAddress(address), airLinePhone(phone), numFlights(number) {
    flights = new Flight[number];
    for (int i = 0; i < number; i++) {
        flights[i] = list[i];
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
void Airline::setAirLineName(const string&name) {
    airLineName = name;
}

void Airline::setAirLineAddress(const string&address) {
    airLineAddress = address;
}

void Airline::setAirLinePhone(string phone) {
    airLinePhone = phone;
}

// Add a flight to the airline
void Airline::addFlight(const string & dep, const string& arr, const Time & depTime, const Time & arrTime) {         
    if (numFlights==0){
        flights= new Flight[1];
        flights[0]=Flight(dep, arr, depTime, arrTime);
        updateFlightIdent(flights[0]);
        numFlights++;
        return;
    }                                 
    // Create a new array with increased size
    Flight* newFlights = new Flight[numFlights + 1];
    
    // Copy existing flights to the new array
    for (int i = 0; i < numFlights; i++) {
        newFlights[i]=flights[i];
    }
    
    // Add the new flight to the end of the array
    newFlights[numFlights]= Flight (dep, arr, depTime, arrTime);
    updateFlightIdent(newFlights[numFlights]);

    // Delete the old array
    delete[] flights;
    
    // Update the flights pointer to point to the new array
    flights = newFlights;
    
    // Increment the number of flights
    numFlights++;
}

// Add a flight to the airline
void Airline::addFlight(Flight flight) {         
    if (numFlights==0){
        flights= new Flight[1];
        flights[0]=flight;
        updateFlightIdent(flights[0]);
        numFlights++;
        return;
    }                                 
    // Create a new array with increased size
    Flight* newFlights = new Flight[numFlights + 1];
    
    // Copy existing flights to the new array
    for (int i = 0; i < numFlights; i++) {
        newFlights[i]=flights[i];
    }
    
    // Add the new flight to the end of the array
    newFlights[numFlights]=flight;
    updateFlightIdent(newFlights[numFlights]);

    // Delete the old array
    delete[] flights;
    
    // Update the flights pointer to point to the new array
    flights = newFlights;
    
    // Increment the number of flights
    numFlights++;
}

// Add multiple flights to the airline
void Airline::addFlight(Flight * list,int number){
    if (numFlights==0){
        flights= new Flight[number];
        for (int i = 0; i < number; i++) {
            flights[i]=list[i];
            updateFlightIdent(flights[i]);
        }
        numFlights=number;
        return;
    }

    Flight* newFlights = new Flight[numFlights + number];
    int i = 0;
    for (; i < numFlights; i++) {
        newFlights[i]=flights[i];
    }

    for (int j = 0; j < number; j++) {
        newFlights[i]=list[j];
        updateFlightIdent(newFlights[i]);
        i++;
    }

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
        flights[i]=flights[i+1];
    }
    
    // Reduce the size of the flights array
    Flight* temp = new Flight[--numFlights];
    for (i = 0; i < numFlights; i++) {
        temp[i]=flights[i];
    }
    delete[] flights;
    flights = temp;
}

// List all flights in the airline
void Airline::listFlights() const {
    for (int i = 0; i < numFlights; i++) {
        cout << flights[i].getFlightIdent() << endl;
    }
}

// List flights with a specific departure and arrival city
void Airline::listFlights(string depCity, string arrCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getDeparture() == depCity && flights[i].getArrival() == arrCity) {
            cout << flights[i].getFlightIdent() << endl;
        }
    }
}

// List flights with a specific departure city
void Airline::listFlightsDep(string depCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getDeparture() == depCity) {
            cout << flights[i].getFlightIdent() << endl;
        }
    }
}

// List flights with a specific arrival city
void Airline::listFlightsArr(string arrCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getArrival() == arrCity) {
            cout << flights[i].getFlightIdent() << endl;
        }
    }
}

// Get the number of flights in the airline
int Airline::getNumFlights() const {
    return numFlights;
}

// Get a flight object by its identifier
Flight Airline::getFlight(string ident){
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getFlightIdent() == ident) {
            return flights[i];
        }
    }

    cout << "Flight not found" << endl;
    return Flight();
}

// Update the flight identifier based on the airline name
void Airline::updateFlightIdent(Flight & flight){   
    // Initialize the identifier with the initials of the airline name
    string initial = "";
    for (char elem : airLineName) {
        if (isupper(elem)) {
            initial += elem;
        }
    }
    // Append the initial to the flight identifier
    flight.flightIdent = initial + flight.flightIdent;
}
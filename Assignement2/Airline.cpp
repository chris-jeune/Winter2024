// Author: Christian Jeune, ID: 40279265 
#include "Airline.h"

// Default constructor
Airline::Airline() : airLineName(""), airLineAddress(""), airLinePhone(""), numFlights(0), flights(nullptr) {}

// Parameterized constructor
Airline::Airline(string name, string address, string phone, int number, Flight *flight)
    : airLineName(name), airLineAddress(address), airLinePhone(phone), numFlights(number) {
    
    this->flights = new Flight[number];

    for (int i = 0; i < number; i++) {
        this->flights[i] = flight[i];
    }
}

Airline::Airline(const Airline &obj) : airLineName(obj.airLineName), airLineAddress(obj.airLineAddress), airLinePhone(obj.airLinePhone), numFlights(obj.numFlights) {
    flights = new Flight[numFlights];
    for (int i = 0; i < numFlights; i++) {
        flights[i] = obj.flights[i];
    }
}

// Destructor
Airline::~Airline() {
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
void Airline::setAirLineName(string name) {
    airLineName = name;
}

void Airline::setAirLineAddress(string address) {
    airLineAddress = address;
}

void Airline::setAirLinePhone(string phone) {
    airLinePhone = phone;
}

// Add a flight to the airline
void Airline::addFlight(string dep, string arr, Time depTime, Time arrTime) {         

    if (numFlights==0){
        flights= new Flight[1];
        flights[0]= Flight(dep, arr, depTime, arrTime);
        numFlights++;
        return;
    }                                 
    // Create a new array with increased size
    Flight* newFlights = new Flight[numFlights + 1];
    
    // Copy existing flights to the new array
    for (int i = 0; i < numFlights; i++) {
        newFlights[i] = flights[i];
    }
    
    // Add the new flight to the end of the array
    newFlights[numFlights] = Flight(dep, arr, depTime, arrTime);
    
    // Delete the old array
    delete[] flights;
    
    // Update the flights pointer to point to the new array
    flights = newFlights;
    
    // Increment the number of flights
    numFlights++;
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
        flights[i] = flights[i + 1];
    }
    
    // Reduce the size of the flights array
    Flight* temp = new Flight[--numFlights];
    for (i = 0; i < numFlights; i++) {
        temp[i] = flights[i];
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
void Airline::listFlights(string depCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getDeparture() == depCity) {
            cout << flights[i].getFlightIdent() << endl;
        }
    }
}

// List flights with a specific arrival city
void Airline::listFlights(string arrCity) const {
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

void Airline::addBooking(Passenger & passenger, string ident){
    // Find the index of the flight to book
    int i = 0;

    for (; i < numFlights; i++) {
        if (flights[i].getFlightIdent() == ident) {
            break;
        }
    }


    Booking * book= new Booking(passenger,flights[i]);

    passenger.addBooking(*book);
    flights[i].addBooking(*book);
    
}

void Airline::cancelBooking(Passenger & pass, string bookid, string flid){
     // Find the index of the flight to book
    int i = 0;
    int j=0;
    int k=0;
    for (; i < numFlights; i++) {
        if (flights[i].getFlightIdent() == flid) {
            break;
        }
    }

    flights[i].cancelBooking(bookid);
    pass.cancelBooking(bookid);
}
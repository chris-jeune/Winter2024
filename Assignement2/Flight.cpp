// Author: Christian Jeune, ID: 40279265

#include "Flight.h"
#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

const string Flight::airlineName = "CoenAir";

int Flight::flightCount = 0;

// Default constructor
Flight::Flight(): flightIdent(createFlightIdent()) {
    departure = "N/A";
    arrival = "N/A";

    departureTime = new Time();
    arrivalTime = new Time();

    flightDuration = 0;

    flightCount++;
}

// Parameterized constructor
Flight::Flight(string dep, string arr, Time depTime, Time arrTime): flightIdent(createFlightIdent()){
    departure = dep;
    arrival = arr;

    departureTime = new Time(depTime);
    arrivalTime = new Time(arrTime);

    flightDuration = flightDurationCalc();
    flightCount++;
}

// Copy constructor
Flight::Flight(const Flight &obj) : flightIdent(obj.flightIdent) {
    departure = obj.departure;
    arrival = obj.arrival;

    departureTime = new Time(*obj.departureTime);
    arrivalTime = new Time(*obj.arrivalTime);

    flightDuration = obj.flightDuration;
    flightCount++;
}

// Destructor
Flight::~Flight() {
    delete departureTime;
    delete arrivalTime;
}

// Getters
string Flight::getFlightIdent() const {
    return flightIdent;
}

string Flight::getDeparture() const {
    return departure;
}

string Flight::getArrival() const {
    return arrival;
}

Time  Flight::getDepartureTime() const {
    return *departureTime;
}

Time  Flight::getArrivalTime() const {
    return *arrivalTime;
}

int Flight::getFlightDuration() const {
    return flightDuration;
}

// Setters
void Flight::setCities(const string& dep, const string& arr) {
    departure = dep;
    arrival = arr;
}

void Flight::setDepartureTime(const Time& depTime) {
    *departureTime = depTime;
}

void Flight::setArrivalTime(const Time& arrTime) {
    *arrivalTime = arrTime;
}

// Create flight identifier
inline string Flight::createFlightIdent() const {
    string initial;

    // Searching for uppercase letters in the airline name
    for(char elem: airlineName) {
        if (isupper(elem)) {
            initial += elem;
        }
    }
    return  initial + to_string(flightCount);
}

// Calculate flight duration
inline int Flight::flightDurationCalc() const {
    // Get the hour and minute of the departure time
    int depHour = departureTime->getHour();
    int depMin = departureTime->getMinute();

    // Get the hour and minute of the arrival time
    int arrHour = arrivalTime->getHour();
    int arrMin = arrivalTime->getMinute();

    // Convert the departure time to minutes
    int depTime = (depHour * 60) + depMin;

    // Convert the arrival time to minutes
    int arrTime = (arrHour * 60) + arrMin;

    // Calculate the duration by subtracting the departure time from the arrival time
    int duration = arrTime - depTime;

    return duration;
}

// Print flight details
void Flight::printFlight() const {
    cout << "Flight: " << flightIdent << endl;
    cout << "Departure: " << departure << endl;
    cout << "Arrival: " << arrival << endl;
    cout << "Departure Time: ";
    departureTime->printTime();
    cout << endl;
    cout << "Arrival Time: ";
    arrivalTime->printTime();
    cout << endl;
    cout << "Flight Duration: " << flightDuration << " minutes" << endl;
}
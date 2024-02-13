// Author: Christian Jeune, ID: 40279265

#include "Flight.h"
#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

string Flight::airlineName = "N/A";

int Flight::flightCount = 0;

// Default constructor
Flight::Flight() {
    flightIdent = "N/A";
    departure = "N/A";
    arrival = "N/A";
    departureTime = new Time();
    arrivalTime = new Time();
    flightDuration = 0;
    flightCount++;
}

// Parameterized constructor
Flight::Flight(string dep, string arr, Time depTime, Time arrTime) {
    departure = dep;
    arrival = arr;
    departureTime = new Time(depTime);
    arrivalTime = new Time(arrTime);
    flightIdent = createFlightIdent();
    flightDuration = flightDurationCalc();
    flightCount++;
}

// Copy constructor
Flight::Flight(const Flight &obj) {
    departure = obj.departure;
    arrival = obj.arrival;
    departureTime = new Time(*obj.departureTime);
    arrivalTime = new Time(*obj.arrivalTime);
    flightIdent = obj.flightIdent;
    flightDuration = obj.flightDuration;
    flightCount++;
}

// Destructor
Flight::~Flight() {
    delete departureTime;
    delete arrivalTime;
    flightCount--;
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

void Flight::setAirlineName(string name) {
    airlineName = name;
}

// Create flight identifier
inline string Flight::createFlightIdent() const {
    string initial;
    for(char elem: airlineName) {
        if (isupper(elem)) {
            initial += elem;
        }
    }
    return  initial + to_string(flightCount);
}

// Calculate flight duration
inline int Flight::flightDurationCalc() const {
    int depHour = departureTime->getHour();
    int depMin = departureTime->getMinute();
    int arrHour = arrivalTime->getHour();
    int arrMin = arrivalTime->getMinute();
    int depTime = (depHour * 60) + depMin;
    int arrTime = (arrHour * 60) + arrMin;
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
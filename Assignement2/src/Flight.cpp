// Author: Christian Jeune, ID: 40279265

#include "Flight.h"
#include "Booking.h"
#include <iostream>

using namespace std;

// Initialize static member variable
int Flight::flightCount = 0;

// Default constructor
Flight::Flight() : departure("N/A"), arrival("N/A"), flightIdent("N/A"), departureTime(new Time()), arrivalTime(new Time()), bookings(nullptr) {
    flightDuration = 0;
    bookingCount = 0;
}

// Parameterized constructor
Flight::Flight(const string dep, const string arr, const Time & depTime, const Time & arrTime) : departure(dep), arrival(arr), departureTime(new Time(depTime)), arrivalTime(new Time(arrTime)), bookings(nullptr) {
    flightDuration = flightDurationCalc();
    flightCount++;
    flightIdent = createFlightIdent();
    bookingCount = 0;
}

// Copy constructor
Flight::Flight(const Flight& obj) : departure(obj.departure), arrival(obj.arrival), departureTime(new Time(*obj.departureTime)), arrivalTime(new Time(*obj.arrivalTime)), flightIdent(obj.flightIdent), bookingCount(obj.bookingCount), flightDuration(obj.flightDuration) {
    // Copy bookings from the source object to the current object
    if (bookingCount > 0) {
        // Allocate memory for the bookings array
        bookings = new Booking[bookingCount];

        // Copy each booking from the source object to the current object
        for (int i = 0; i < bookingCount; i++) {
            bookings[i]=obj.bookings[i];
            bookings[i].setFlight(this);
        }
    }
    else{
        bookings = nullptr;
    }
}

// Destructor
Flight::~Flight() {
    delete departureTime;
    delete arrivalTime;
    if (bookingCount>0) {
        delete[] bookings;
    }
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

Time Flight::getDepartureTime() const {
    return *departureTime;
}

Time Flight::getArrivalTime() const {
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
    departureTime = new Time(depTime);
    flightDuration = flightDurationCalc();
}

void Flight::setArrivalTime(const Time& arrTime) {
    arrivalTime = new Time(arrTime);
    flightDuration = flightDurationCalc();
}

// Create flight identifier
string Flight::createFlightIdent() const {
    string initial="FL-";
    return initial + to_string(flightCount);
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

    // Handle cases where the flight crosses midnight
    duration /= 60;

    return (duration < 0) ? duration + 24 : duration;
}

// Print flight details
void Flight::printFlight() const {
    cout << "Flight: " << flightIdent << endl;
    cout << "Departure: " << departure << endl;
    cout << "Arrival: " << arrival << endl;
    cout << "Departure Time: ";
    if (departureTime != nullptr)
        departureTime->printTime();
    cout << endl;
    cout << "Arrival Time: ";
    if (arrivalTime != nullptr)
        arrivalTime->printTime();
    cout << endl;
    cout << "Flight Duration: " << flightDuration << " hours" << endl;
    cout << "Available Seats: " << MAX_SEATS - bookingCount << endl;
}

// List all bookings for the flight
void Flight::listBookings() const {
    cout << "Bookings for Flight " << flightIdent << endl;
    for (int i = 0; i < bookingCount; i++) {
        cout << "Seat: " << bookings[i].getSeatNumber() << endl;
        cout << "Passenger: " << bookings[i].getPassenger()->getName() <<", ("<< bookings[i].getPassenger()->getId()<<")"<< endl;
        cout << endl;
    }
}

// Add a booking to the flight
void Flight::addBooking(Booking* b) {

    // Check if there are no existing bookings
    if (bookingCount == 0) {
        // Create a new array with a single booking
        bookings = new Booking[1];
        bookings[0]=*b;
    }
    else {
        // Create a temporary array with increased size
        Booking* temp = new Booking[bookingCount + 1];
        
        // Copy existing bookings to the temporary array
        for (int i = 0; i < bookingCount; i++) {
            temp[i]=bookings[i];
        }
        
        // Add the new booking to the temporary array
        temp[bookingCount]=*b;
        
        // Delete the old bookings array and assign the temporary array to it
        delete[] bookings;
        bookings = temp;
    }

}

void Flight::setBookings(Booking* booking, int count) {
    bookings = new Booking[count];
    for(int i = 0; i < count; i++) {
        bookings[i]=booking[i];
        bookings[i].setFlight(this);
    }
    bookingCount = count;
}

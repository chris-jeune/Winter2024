// Author: Christian Jeune, ID: 40279265

#include "Flight.h"
#include <iostream>
#include <string>
#include "Time.h"
#include "Booking.h"

using namespace std;

const string Flight::airlineName = "CoenAir";

int Flight::flightCount = 0;

// Default constructor
Flight::Flight(): flightIdent("N/A"), departureTime( new Time()), arrivalTime(new Time()) /*bookings(nullptr)*/ {
    departure = "N/A";
    arrival = "N/A";

    flightDuration = 0;
    bookingCount = 0;
}

// Parameterized constructor
Flight::Flight(string dep, string arr, Time depTime, Time arrTime):departureTime(new Time(depTime)), arrivalTime(new Time(depTime)) /*bookings(nullptr)*/ {
    departure = dep;
    arrival = arr;

    flightDuration = flightDurationCalc();
    flightCount++;

    flightIdent = createFlightIdent();
    bookingCount = 0;
}

// Copy constructor
Flight::Flight(const Flight &obj):departureTime(new Time(*obj.departureTime)), arrivalTime (new Time(*obj.arrivalTime)){
    departure = obj.departure;
    arrival = obj.arrival;

    flightDuration = obj.flightDuration;
    flightCount++;

    flightIdent = createFlightIdent();

    bookingCount=obj.bookingCount;
    bookings= new Booking[bookingCount];
    for(int i=0; i<bookingCount;i++){
        bookings[i]=obj.bookings[i];
    }
}

// Destructor
Flight::~Flight() {
    cout<<"Flight "<<flightIdent<<" is being deleted"<<endl;
    delete departureTime;
    delete arrivalTime;
    delete[] bookings;
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
    delete departureTime;
    departureTime = new Time(depTime);
    flightDuration = flightDurationCalc();
}

void Flight::setArrivalTime(const Time& arrTime) {
    delete arrivalTime;
    arrivalTime = new Time(arrTime);
    flightDuration = flightDurationCalc();
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

    return duration/60;
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
    cout << "Flight Duration: " << flightDuration << " hours" << endl;
}


void Flight::addBooking(Booking & book){
if(bookingCount==0){
    bookings= new Booking[++bookingCount];
    bookings[0]=book;
    bookingCount++;
    return;
}

else if(bookingCount==MAX_SEATS){
cout<<"Flight is full"<<endl;
return;

}

    Booking * temp= new Booking[bookingCount+1];
    for(int i=0; i<bookingCount;i++){
        temp[i]=bookings[i];
    }

    temp[bookingCount]=book;

    delete[] bookings;

    bookings= temp;

    bookingCount++;


}

void Flight::cancelBooking(string bookid){
    int i=0;

        for (; i < bookingCount; i++) {
        if (bookings[i].getSeatNumber() == bookid) {
            break;
        }
    }
    for(; i<bookingCount-1;i++){
        bookings[i]=bookings[i+1];
    }

    Booking * temp= new Booking[--bookingCount];

    for(int i=0; i<bookingCount;i++){
        temp[i]=bookings[i];
    }

    delete[] bookings;
    bookings= temp;

}
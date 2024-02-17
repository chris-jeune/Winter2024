// Author: Christian Jeune, ID: 40279265

#include "Flight.h"
#include "Booking.h"
#include <iostream>

using namespace std;

const string Flight::airlineName = "CoenAir";

int Flight::flightCount = 0;

// Default constructor
Flight::Flight():departure("N/A"), arrival("N/A") ,flightIdent("N/A"), departureTime( new Time()), arrivalTime(new Time()){
    flightDuration = 0;
    bookingCount = 0;


}

// Parameterized constructor
Flight::Flight(string dep, string arr, Time depTime, Time arrTime):departure(dep), arrival(arr), departureTime(new Time(depTime)), arrivalTime(new Time(arrTime)) {
    flightDuration = flightDurationCalc();
    flightCount++;

    flightIdent = createFlightIdent();
    bookingCount = 0;

}

// Copy constructor
Flight::Flight(const Flight &obj):departure(obj.departure), arrival(obj.arrival),departureTime(new Time(*obj.departureTime)), arrivalTime (new Time(*obj.arrivalTime)){
    flightDuration = obj.flightDuration;

    bookingCount = obj.bookingCount;
    flightIdent = createFlightIdent();
    if(bookingCount>0){
    bookings= new Booking[bookingCount];
    for(int i=0; i<bookingCount; i++){
        bookings[i].setPassenger(obj.bookings[i].getPassenger());
        bookings[i].setSeatNumber(obj.bookings[i].getSeatNumber());
        bookings[i].setFlight(this);
    }
    }

}

// Destructor
Flight::~Flight() {
    cout<<"Flight "<<flightIdent<<" is being deleted"<<endl;
    delete departureTime;
    delete arrivalTime;
    if (bookingCount>0){
        delete [] bookings;
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

    duration/=60;

    return (duration<0)?duration+24:duration;
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

void Flight::listBookings()const{
    cout<<"Bookings for Flight "<<flightIdent<<endl;
    for (int i=0; i<bookingCount;i++){

            cout<<"Seat: "<<bookings[i].getSeatNumber()<<endl;
            cout<<"Passenger: "<<bookings[i].getPassenger()->getName()<<endl;
            cout<<"Phone: "<<bookings[i].getPassenger()->getPhone()<<endl;
            cout<<"Address: "<<bookings[i].getPassenger()->getAddress()<<endl;
            cout<<endl;
    }

}

void Flight::setFlightIdent(string id){
    flightIdent = id;
}

void Flight::addBooking(Booking * b, Passenger *p){
    if(bookingCount==0){
        bookings = new Booking[1];
        bookings[0].setPassenger(p);
        bookings[0].setSeatNumber(b->getSeatNumber());
        bookings[0].setFlight(this);
    }
    else{
        Booking *temp = new Booking[bookingCount+1];
        for(int i=0; i<bookingCount; i++){
            temp[i].setPassenger(p);
            temp[i].setSeatNumber(bookings[i].getSeatNumber());
            temp[i].setFlight(this);
        }
        temp[bookingCount].setPassenger(p);
        temp[bookingCount].setSeatNumber(b->getSeatNumber());
        temp[bookingCount].setFlight(this);
        delete [] bookings;
        bookings = temp;
    }
}
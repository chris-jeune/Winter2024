#include "Airline.h"
#include "Flight.h"
#include "Passenger.h"
#include "Booking.h"
#include "Time.h"
#include <iostream>
#include <random>
#include <vector>
#include <string>

using namespace std;


Time generateRandomTime() {
    int hour = rand() % 24; // Generate random hour (0-23)
    int minute = rand() % 60; // Generate random minute (0-59)
    int second = rand() % 60; // Generate random second (0-59)
    return Time(hour, minute, second);
}

vector<string> cities = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix", "Philadelphia", "San Antonio", "San Diego", "Dallas", "San Jose"};

string getRandomCity() {
    return cities[rand() % cities.size()];
}

Flight createRandomFlight() {
    string origin = getRandomCity();
    string destination = getRandomCity();
    Time departureTime = generateRandomTime();
    Time arrivalTime = generateRandomTime();

    // Create and return the Flight object
    Flight f(origin, destination, departureTime, arrivalTime);
    return f;
}


void testAirlineCreation() {
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    cout<< "Airline Name: " << airline.getAirLineName() << endl;
    cout<< "Airline Address: " << airline.getAirLineAddress() << endl;
    cout<< "Airline Phone: " << airline.getAirLinePhone() << endl;
}   

void testBookingCreation(){
    cout << "Creating a booking\n" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    Flight f = createRandomFlight();
    airline.addFlight(f);
    Passenger p("John Doe", "8 rue de Maisonneuve", "123456789");
    Booking b(p, f.getFlightIdent(), airline);
    cout<<"List of bookings from passenger"<<endl;
    p.listBookings();
    cout<<"\nList of bookings from flight"<<endl;
    airline.getFlight(f.getFlightIdent()).listBookings();

}

void testCancelBooking(){
    string book;
    string flid;
    cout << "Creating a booking\n" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout<<"Airline created"<<endl;
    Passenger p("John Doe", "8 rue de Maisonneuve", "123456789");
    cout<<"Passenger created"<<endl;
    Flight f = createRandomFlight();
    cout<<"Flight created"<<endl;
    airline.addFlight(f);
    cout<<"Listing all flights from Airline "<<airline.getAirLineName()<<endl;
    airline.listFlights();
    Booking b(p, f.getFlightIdent(), airline);
    cout<<"List of bookings from passenger"<<endl;
    p.listBookings();
    cout<<"\nWhich booking would you like to cancel "<<endl;
    cin>>book;
    cout<< "\nWhich flight is the booking from "<<endl;
    cin>>flid;
    cout<< "\nCancelling booking\n"<<endl;
    Booking::cancelBooking(p, book, flid,airline);
    p.listBookings();

}

int main(){
    //testAirlineCreation();
    testBookingCreation();
    // testCancelBooking();
    return 0;
}
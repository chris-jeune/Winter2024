// Author: Christian Jeune, ID: 40279265

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

// Function to generate a random Time object
Time generateRandomTime() {
    int hour = rand() % 24; // Generate random hour (0-23)
    int minute = rand() % 60; // Generate random minute (0-59)
    int second = rand() % 60; // Generate random second (0-59)
    Time t(hour, minute, second);
    return t;
}

// List of cities for generating random flights
vector<string> cities = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix", "Philadelphia", "San Antonio", "San Diego", "Dallas", "San Jose"};

// Function to get a random city from the list
string getRandomCity() {
    return cities[rand() % cities.size()];
}

// Function to create a random Flight object
Flight createRandomFlight() {
    string origin = getRandomCity();
    string destination = getRandomCity();
    Time departureTime(generateRandomTime());
    Time arrivalTime(generateRandomTime());

    // Create and return the Flight object
    Flight f(origin, destination, departureTime, arrivalTime);
    return f;
}

// Test function to demonstrate airline creation
void testAirlineCreation() {
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    cout << "Airline Name: " << airline.getAirLineName() << endl;
    cout << "Airline Address: " << airline.getAirLineAddress() << endl;
    cout << "Airline Phone: " << airline.getAirLinePhone() << endl;
}

// Test creating airline with flights
void testAirlineCreationWithFlights() {
    cout << "Creating an airline" << endl;
    Flight f = createRandomFlight();
    Flight f2 = createRandomFlight();
    Flight f3 = createRandomFlight();
    Flight tab[3] = {f, f2, f3};
    Airline airline("CoenAir", "1234 Main St", "123-456-7890",tab,3);
    cout << "Airline created" << endl;
    cout << "Listing all flights from Airline " << airline.getAirLineName() << endl;
    airline.listFlights();
}

// Test function for copy constructor
void testAirlineCopy(){
    cout << "Creating an airline" << endl;
    Flight f = createRandomFlight();
    Flight f2 = createRandomFlight();
    Flight f3 = createRandomFlight();
    Flight tab[3] = {f, f2, f3};
    Airline airline("CoenAir", "1234 Main St", "123-456-7890",tab,3);
    cout << "Airline created" << endl;
    cout << "Airline Name: " << airline.getAirLineName() << endl;
    cout << "Airline Address: " << airline.getAirLineAddress() << endl;
    cout << "Airline Phone: " << airline.getAirLinePhone() << endl;
    cout << "Creating a copy of the airline" << endl;
    Airline airline2(airline);
    cout << "Airline copied" << endl;
    cout << "Airline Name: " << airline2.getAirLineName() << endl;
    cout << "Airline Address: " << airline2.getAirLineAddress() << endl;
    cout << "Airline Phone: " << airline2.getAirLinePhone() << endl;
}

// Test function to demonstrate adding flights using an array
void testAddingFlightsArray() {
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    Flight f = createRandomFlight();
    Flight f2 = createRandomFlight();
    Flight f3 = createRandomFlight();
    Flight tab[3] = {f, f2, f3};
    cout << "Flight created" << endl;
    airline.addFlight(tab, 3);
    cout << "Listing all flights from Airline " << airline.getAirLineName() << endl;
    airline.listFlights();
}

// Test function to demonstrate adding flights using parameters
void testAddingFlightsParam() {
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    cout << "Adding flight" << endl;
    airline.addFlight("New York", "Los Angeles", Time(9, 30, 0), Time(12, 0, 0));
    cout << "Listing all flights from Airline " << airline.getAirLineName() << endl;
    airline.listFlights();
}

// Test function to demonstrate adding flights using Flight objects
void testAddingFlightObj() {
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    cout << "Flight created" << endl;
    Flight f = createRandomFlight();
    airline.addFlight(f);
    cout << "Listing all flights from Airline " << airline.getAirLineName() << endl;
    airline.listFlights();
}

// Test function to demonstrate adding flights to a non-empty airline
void testAddingFlightsArrayNotEmpty() {
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    cout << "Flight created" << endl;
    Flight f(createRandomFlight());
    Flight f2(createRandomFlight());
    Flight f3(createRandomFlight());
    Flight tab[3] = {f, f2, f3};
    Flight f4("New York", "Los Angeles", Time(9, 30, 0), Time(12, 0, 0));
    cout << "Flight created" << endl;
    airline.addFlight(f4);
    airline.addFlight(tab, 3);
    cout << "Listing all flights from Airline " << airline.getAirLineName() << endl;
    airline.listFlights();
}

// Test function to demonstrate adding flights to a non-empty airline
void testAddingFlightsParamNotEmpty() {
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    cout << "Flight created" << endl;
    Flight f(createRandomFlight());
    Flight f2(createRandomFlight());
    Flight f3(createRandomFlight());
    Flight f4("New York", "Los Angeles", Time(9, 30, 0), Time(12, 0, 0));
    cout << "Flight created" << endl;
    airline.addFlight(f4);
    airline.addFlight("New York", "Los Angeles", Time(9, 30, 0), Time(12, 0, 0));
    airline.addFlight(f);
    airline.addFlight(f2);
    airline.addFlight(f3);
    cout << "Listing all flights from Airline " << airline.getAirLineName() << endl;
    airline.listFlights();
}

// Test function to demonstrate the copy constructor for Airline class
void testCopyConstructorAirline() {
    cout << "Testing copy constructor" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Original airline" << endl;
    cout << "Airline Name: " << airline.getAirLineName() << endl;
    cout << "Airline Address: " << airline.getAirLineAddress() << endl;
    cout << "Airline Phone: " << airline.getAirLinePhone() << endl;
    Airline airline2(airline);
    cout << "Copied airline" << endl;
    cout << "Airline Name: " << airline2.getAirLineName() << endl;
    cout << "Airline Address: " << airline2.getAirLineAddress() << endl;
    cout << "Airline Phone: " << airline2.getAirLinePhone() << endl;
}

// Test function to demonstrate removing flights from an airline
void testRemoveFlight(){
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    cout<<"Flight created"<<endl;
    Flight f = createRandomFlight();
    Flight f2 = createRandomFlight();
    Flight f3 = createRandomFlight();   
    Flight tab[3] = {f, f2, f3};
    airline.addFlight(tab,3);
    cout<<"Listing all flights from Airline "<<airline.getAirLineName()<<endl;
    airline.listFlights();
    cout<<"Removing flight"<<endl;
    airline.removeFlight("CAFL-1");
    cout<<"Listing all flights from Airline "<<airline.getAirLineName()<<endl;
    airline.listFlights();
    cout<<"Removing remaining"<<endl;
    airline.removeFlight("CAFL-2");
    airline.removeFlight("CAFL-3");
    cout<<"Listing all flights from Airline "<<airline.getAirLineName()<<endl;
    airline.listFlights();
    cout<<"Removing non existing flight"<<endl;
    airline.removeFlight("CAFL-4");
    cout<<"Adding flight"<<endl;
    airline.addFlight(f);
    cout<<"Listing all flights from Airline "<<airline.getAirLineName()<<endl;
    airline.listFlights();
}

// Test function to demonstrate the setters for the Airline class
void testAirlineSetters(){
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    cout<< "Airline Name: " << airline.getAirLineName() << endl;
    cout<< "Airline Address: " << airline.getAirLineAddress() << endl;
    cout<< "Airline Phone: " << airline.getAirLinePhone() << endl;
    cout<<"Setting new address"<<endl;
    airline.setAirLineAddress("5678 Main St");
    cout<< "Airline Address: " << airline.getAirLineAddress() << endl;
    cout<<"Setting new phone"<<endl;
    airline.setAirLinePhone("987-654-3210");
    cout<< "Airline Phone: " << airline.getAirLinePhone() << endl;
}

// Test function to demonstrate listing flights from an airline
void testAirlineListing(){
    cout << "Creating an airline" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    cout << "Airline created" << endl;
    cout<<"Flight created"<<endl;
    Flight f = createRandomFlight();
    Flight f2 = createRandomFlight();
    Flight f3 = createRandomFlight();
    Flight f4 = createRandomFlight();
    Flight f5 = createRandomFlight();
    Flight f6 = createRandomFlight();
    Flight f7 = createRandomFlight();
    Flight f8 = createRandomFlight();
    Flight f9 = createRandomFlight();
    Flight f10 = createRandomFlight();   
    Flight tab[10] = {f, f2, f3, f4, f5, f6, f7, f8, f9, f10};
    airline.addFlight(tab,10);
    cout<<"Listing all flights from Airline "<<airline.getAirLineName()<<endl;
    airline.listFlights();
    cout<<"Listing flights departing from specific city"<<endl;
    airline.listFlightsDep("Los Angeles");
    cout<<"Listing flights arriving to specific city"<<endl;
    airline.listFlightsArr("San Diego");
    cout<<"Listing flights departing and arriving to specific cities"<<endl;
    airline.listFlights("Los Angeles", "San Diego");
}

// Test function to demonstrate booking creation
void testBookingCreation(){
    cout<<"Default Booking Constructor"<<endl;
    Booking b;
    b.printBooking();
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    Flight f = createRandomFlight();
    airline.addFlight(f);
    Passenger p("John Doe", "8 rue de Maisonneuve", "123456789");
    cout<<"\nParameterized Booking Constructor"<<endl;
    Booking b1(p, "CAFL-1", airline);
    b1.printBooking();
    cout<<endl;
    p.listBookings();
    f.listBookings();
    cout<<"Copy Booking Constructor"<<endl;
    Booking b2(b1);
    b2.printBooking();
}

// Test function to demonstrate cancelling a booking
void testCancelBooking(){
    cout << "Creating a booking\n" << endl;
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0);
    Passenger p("John Doe", "8 rue de Maisonneuve", "123456789");
    Flight f = createRandomFlight();
    Flight f2 = createRandomFlight();
    Flight f3 = createRandomFlight();
    Flight tab[3] = {f, f2, f3};
    airline.addFlight(tab,3);
    cout<<"Listing all flights from Airline "<<airline.getAirLineName()<<endl;
    airline.listFlights();
    Booking b(p,  "CAFL-1", airline);
    Booking b4(p, "CAFL-2", airline);
    Booking b7(p, "CAFL-3", airline);
    Booking b10(p, "CAFL-1", airline);
    Booking b13(p, "CAFL-2", airline);
    Booking b16(p, "CAFL-3", airline);
    cout<<"\nList of all flights from airline after booking"<<endl;
    airline.listFlights();
    cout<<"\nList of bookings from passenger"<<endl;
    p.listBookings();
    cout<< "\nCancelling booking\n"<<endl;
    Booking::cancelBooking(p, "A1", "CAFL-1");
    p.listBookings();
    cout<<"\nCancelling booking\n"<<endl;
    Booking::cancelBooking(p, "A2", "CAFL-2");
    p.listBookings();
    cout<<"\nCancelling booking\n"<<endl;
    Booking::cancelBooking(p, "A1", "CAFL-3");
    p.listBookings();
    cout<<"\nCancelling non existing booking\n"<<endl;
    Booking::cancelBooking(p, "A4", "CAFL-1");
    cout<<"Adding booking"<<endl;
    Booking b1(p, "CAFL-2", airline);
    p.listBookings();
}

// Test copying passengers with bookings
void testCopyPassBookings(){
    cout << "Creating a booking\n" << endl;
    Passenger p("John Doe", "8 rue de Maisonneuve", "123456789");
    Flight f = createRandomFlight();
    Flight f2 = createRandomFlight();
    Flight f3 = createRandomFlight();
    Booking b(p,  f);
    Booking b4(p, f2);
    Booking b7(p, f3);
    cout<<"\nList of bookings from passenger"<<endl;
    p.listBookings();
    cout<< "\nCopying passenger\n"<<endl;
    Passenger p2(p);
    p2.listBookings();
}

// Test copying flights with bookings
void testCopyFlightBookings(){
    cout << "Creating a booking\n" << endl;
    Passenger p("John Doe", "8 rue de Maisonneuve", "123456789");
    Flight f = createRandomFlight();
    Booking b(p,  f);
    Booking b4(p, f);
    Booking b7(p, f);
    cout<<"\nList of bookings from flight"<<endl;
    f.listBookings();
    cout<< "\nCopying flight\n"<<endl;
    Flight f5(f);
    f5.listBookings();
}

// test copying airlines with flights with bookings
void testCopyAirlineBooking(){
    cout << "Creating an airline" << endl;
    Passenger p("John Doe", "8 rue de Maisonneuve", "123456789");
    Flight f = createRandomFlight();
    Flight f2 = createRandomFlight();
    Flight f3 = createRandomFlight();
    Flight tab[3] = {f, f2, f3};
    Booking b(p,  tab[0]);
    Booking b4(p, tab[1]);
    Booking b7(p, tab[2]);
    Airline airline("CoenAir", "1234 Main St", "123-456-7890",tab,3);
    cout << "Airline created" << endl;
    cout << "Listing all flights from Airline " << airline.getAirLineName() << endl;
    airline.listFlights();
    cout << "Creating a copy of the airline" << endl;
    Airline airline2(airline);
    cout << "Airline copied" << endl;
    cout << "Listing all flights from Airline " << airline2.getAirLineName() << endl;
    airline2.listFlights();

}

int main(){
    // testAirlineCreation();
    // testAirlineCreationWithFlights();
    // testAirlineCopy();
    // testBookingCreation();
    // testAddingFlightsArray();
    // testAddingFlightsParam();
    // testAddingFlightObj();
    // testAddingFlightsArrayNotEmpty();
    // testAddingFlightsParamNotEmpty();
    // testCopyConstructorAirline();
    // testRemoveFlight();
    // testAirlineSetters();
    // testAirlineListing();
    // testCancelBooking();
    // testCopyPassBookings();
    // testCopyFlightBookings();
    // testCopyAirlineBooking();
    return 0;
}
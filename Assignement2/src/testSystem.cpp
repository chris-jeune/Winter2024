#include "Airline.h"
#include "Flight.h"
#include "Passenger.h"
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
    Airline airline("CoenAir", "1234 Main St", "123-456-7890", 0, nullptr);
    cout << "Airline created" << endl;
    cout<< "Airline Name: " << airline.getAirLineName() << endl;
    cout<< "Airline Address: " << airline.getAirLineAddress() << endl;
    cout<< "Airline Phone: " << airline.getAirLinePhone() << endl;
}  


void testListFlights() {

}


int main(){
    //testAirlineCreation();
    // testBooking();
    return 0;
}

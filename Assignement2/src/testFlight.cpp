#include "Flight.h"
#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

void testDefaultConstructor(){
    cout << "Testing default constructor" << endl;
    Flight f;
    f.printFlight();
}

void testParameterizedConstructor(){
    cout << "Testing parameterized constructor" << endl;
    Time depTime(12, 30,0);
    Time arrTime(14, 30,0);
    Flight f("Toronto", "Vancouver", depTime, arrTime);
    f.printFlight();
}

void testCopyConstructor(){
    cout << "Testing copy constructor" << endl;
    Time depTime(12, 30,0);
    Time arrTime(14, 30,0);
    Flight f1("Toronto", "Vancouver", depTime, arrTime);
    cout<<"Original flight"<<endl;
    f1.printFlight();
    cout<<"Copied flight"<<endl;
    Flight f2(f1);
    f2.printFlight();
}

void testAccesserAndDuration(){
    cout << "Testing accessors" << endl;
    Time depTime(12, 30,0);
    Time arrTime(14, 30,0);
    Flight f("Toronto", "Vancouver", depTime, arrTime);
    cout<< "Flight number: " << f.getFlightIdent() << endl;
    cout << "Departing city: " << f.getDeparture() << endl;
    cout << "Arriving city: " << f.getArrival() << endl;
    cout << "Departure time: ";
    f.getDepartureTime().printTime();
    cout << "\nArrival time: ";
    f.getArrivalTime().printTime();
    cout << "\nFlight duration(expected 2 hours): " << f.getFlightDuration() << " hours" << endl;

}

void testSetters(){
    cout << "Testing setters" << endl;
    Time depTime(12, 30,0);
    Time arrTime(14, 30,0);
    Flight f("Toronto", "Vancouver", depTime, arrTime);
    cout << "Original flight" << endl;
    f.printFlight();
    Time newDepTime(11, 30,0);
    Time newArrTime(15, 30,0);
    f.setDepartureTime(newDepTime);
    f.setArrivalTime(newArrTime);
    f.setCities("Montreal", "Calgary");
    cout << "Modified flight" << endl;
    f.printFlight();
}

int main1(){
    // testDefaultConstructor();
    // testParameterizedConstructor();
     testCopyConstructor();
    // testAccesserAndDuration();
    // testSetters();
    return 0;
}


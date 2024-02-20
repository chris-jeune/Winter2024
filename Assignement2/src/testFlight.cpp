// Author: Christian Jeune, ID: 40279265
#include "Flight.h"
#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

// Test default constructor
void testDefaultConstructor(){
    cout << "Testing default constructor" << endl;
    Flight f;
    f.printFlight();
}

// Test parameterized constructor
void testParameterizedConstructor(){
    cout << "Testing parameterized constructor" << endl;
    Time depTime(12, 30,0);
    Time arrTime(14, 30,0);
    Flight f("Toronto", "Vancouver", depTime, arrTime);
    f.printFlight();
}

// Test copy constructor
void testCopyConstructor(){
    cout << "Testing copy constructor" << endl;
    Time depTime(12, 30,0);
    Time arrTime(14, 30,0);
    Flight f1("Toronto", "Vancouver", depTime, arrTime);
    cout<<"Original flight"<<endl;
    f1.printFlight();
    cout<<"\nCopied flight"<<endl;
    Flight f2(f1);
    f2.printFlight();
}

// Test getters
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

// Test setters
void testSetters(){
    cout << "Testing setters" << endl;
    Time depTime(12, 30,0);
    Time arrTime(14, 30,0);
    Flight f("Toronto", "Vancouver", depTime, arrTime);
    cout << "Original flight" << endl;
    f.printFlight();
    Time newDepTime(11, 30,0);
    Time newArrTime(15, 30,0);
    cout<<"\nModified flight"<<endl;
    f.setDepartureTime(newDepTime);
    f.setArrivalTime(newArrTime);
    f.setCities("Montreal", "Calgary");
    f.printFlight();
}

int main3(){
    // testDefaultConstructor();
    // cout<<endl<<endl;
    // testParameterizedConstructor();
    // cout<<endl<<endl;
    // testCopyConstructor();
    // cout<<endl<<endl;
    // testAccesserAndDuration();
    // cout<<endl<<endl;
    // testSetters();
    return 0;
}


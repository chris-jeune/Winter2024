// Author: Christian Jeune, ID: 40279265
#include <iostream>
#include <string>
#include "Time.h"
#include "Passenger.h"

using namespace std;

// Test default constructor
void testDefaultConstructorPass() {
    cout << "Testing default constructor" << endl;
    Passenger p;
    p.printPassenger();
}

// Test parameterized constructor
void testParameterizedConstructorPass() {
    cout << "Testing parameterized constructor" << endl;
    Passenger p("John Doe", "8 rue de Maisonneuve", "123456789");
    p.printPassenger();
}

// Test copy constructor
void testCopyConstructorPass() {
    cout << "Testing copy constructor" << endl;
    Passenger p1("John Doe", "8 rue de Maisonneuve", "123456789");
    cout << "Original passenger" << endl;
    p1.printPassenger();
    cout << "Copied passenger" << endl;
    Passenger p2(p1);
    p2.printPassenger();
}

// Test getters
void testGettersPass() {
    cout << "Testing accessors" << endl;
    Passenger p("John Doe", "8 rue de Maisonneuve", "123456789");
    cout << "Passenger name: " << p.getName() << endl;
    cout << "Passenger ID: " << p.getId() << endl;
    cout << "Address: " << p.getAddress() << endl;
    cout << "Phone: " << p.getPhone() << endl;
}

// Test setters
void testSettersPass() {
    cout << "Testing mutators" << endl;
    Passenger p;
    cout << "Original passenger" << endl;
    p.printPassenger();
    p.setName("John Doe");
    p.setAddress("8 rue de Maisonneuve");
    p.setPhone("123456789");
    cout << "Modified passenger" << endl;
    p.printPassenger();
}

int main() {
    // testDefaultConstructorPass();
    // testParameterizedConstructorPass();
    // testCopyConstructorPass();
    // testGettersPass();
    testSettersPass();
    return 0;
}
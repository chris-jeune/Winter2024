// Authot: Christian Jeune, ID: 40279265

#include "Passenger.h"
#include <iostream>
#include <string>

using namespace std;

int Passenger::passengerCount = 0;

// Default constructor
Passenger::Passenger(): id(createPassengerId()){
    name = "N/A";
    address = "N/A";
    phone = "N/A";
    bookingCount=0;
    passengerCount++;
}

// Parameterized constructor
Passenger::Passenger(string name, string address, string phone): id(createPassengerId()){
    this->name = name;
    this->address = address;
    this->phone = phone;
    bookingCount=0;
    passengerCount++;
}


Passenger::Passenger(const Passenger &obj) : id(obj.id) {
    name = obj.name;
    address = obj.address;
    phone = obj.phone;
    bookingCount=obj.bookingCount;
    bookings= new Booking[bookingCount];
    for(int i=0; i<bookingCount;i++){
        bookings[i]=obj.bookings[i];
    }
}

// Getters
string Passenger::getName() const {
    return name;
}

string Passenger::getId() const {
    return id;
}

string Passenger::getAddress() const {
    return address;
}

string Passenger::getPhone() const {
    return phone;
}

// Setters

void Passenger::setName(string name)  {
    this->name = name;
    id=name.substr(0,2)+id.substr(2);
}

void Passenger::setAddress(string address) {
    this->address = address;
}

void Passenger::setPhone(string phone) {
    this->phone = phone;
}

// Create a unique id for the passenger
string Passenger::createPassengerId() const {
    return name.substr(0,2)+to_string(passengerCount);
}

 void Passenger::printPassenger() const {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
 }

 void Passenger::addBooking(Booking & booking) {
     if (bookingCount==0){
         bookings= new Booking[1];
         bookings[0]= booking;
         bookingCount++;
         return;
     }                                 
     // Create a new array with increased size
     Booking* newBookings = new Booking[bookingCount + 1];
     
     // Copy the old array into the new array
     for (int i = 0; i < bookingCount; i++) {
         newBookings[i] = bookings[i];
     }
     
     // Add the new booking to the new array
     newBookings[bookingCount] = booking;
     
     // Delete the old array
     delete[] bookings;
     
     // Set the old array to the new array
     bookings = newBookings;
     
     // Increase the booking count
     bookingCount++;
 }

 void Passenger::cancelBooking(string bookid) {
     if(bookingCount==0){
         cout<<"No bookings to cancel"<<endl;
         return;
     }
     
     int i=0;

         for (; i < bookingCount; i++) {
         if (bookings[i].getSeatNumber() == bookid) {
             break;
         }
     }

     if(i==bookingCount){
         cout<<"Booking not found"<<endl;
         return;
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
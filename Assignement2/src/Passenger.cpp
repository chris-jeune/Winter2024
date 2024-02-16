// Authot: Christian Jeune, ID: 40279265

#include "Passenger.h"
#include "Booking.h"
#include <iostream>
using namespace std;

int Passenger::passengerCount = 0;

// Default constructor
Passenger::Passenger(): bookings(nullptr){
    name = "N/A";
    address = "N/A";
    phone = "N/A";
    bookingCount=0;
    id = "###";
    passengerCount++;
}

// Parameterized constructor
Passenger::Passenger(string name, string address, string phone): bookings(nullptr){
    this->name = name;
    this->address = address;
    this->phone = phone;
    bookingCount=0;
    passengerCount++;
    id = createPassengerId();
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

// Destructor 
Passenger::~Passenger() {
    cout<<"Passenger "<<id<<" is being deleted"<<endl;
    if(bookingCount!=0){
        delete[] bookings;
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
    id=createPassengerId();
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

 bool Passenger::cancelBooking(string bookid) {
     if(bookingCount==0){
         cout<<"No bookings to cancel"<<endl;
         return 0;
     }
     
     int i=0;

         for (; i < bookingCount; i++) {
         if (bookings[i].getSeatNumber() == bookid) {
             break;
         }
     }

     if(i==bookingCount){
         cout<<"Booking not found"<<endl;
         return 0;
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

     return 1;
 }

Booking * Passenger::getBooking(string bookid) const {
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].getSeatNumber() == bookid) {
            return &bookings[i];
        }
    }
    cout<<"Booking not found"<<endl;
    return nullptr;
}

void Passenger::listBookings() const {
    if (bookingCount == 0) {
        cout << "No bookings for " << name << " (" << id << ")" << endl;
        return;
    }
    cout << "Bookings for " << name << " (" << id << "):" << endl;
    for (int i = 0; i < bookingCount; i++) {
        cout << "Booking " << i + 1 << " : " <<bookings[i].getSeatNumber() << endl;
        
    }
}
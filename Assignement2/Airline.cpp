#include "Airline.h"
#include <stdlib.h>

Airline::Airline() : airLineName(""), airLineAddress(""), airLinePhone(""), numFlights(0), flights(new Flight[0]) {}

Airline::Airline(string name, string address, string phone, int number, Flight *flights)
    : airLineName(name), airLineAddress(address), airLinePhone(phone), numFlights(number) {
    this->flights = new Flight[number];
    for (int i = 0; i < number; i++) {
        this->flights[i] = flights[i];
    }
}

Airline::~Airline() {
    delete[] flights;
}

string Airline::getAirLineName() const {
    return airLineName;
}

string Airline::getAirLineAddress() const {
    return airLineAddress;
}

string Airline::getAirLinePhone() const {
    return airLinePhone;
}

void Airline::setAirLineName(string name) {
    airLineName = name;
}

void Airline::setAirLineAddress(string address) {
    airLineAddress = address;
}

void Airline::setAirLinePhone(string phone) {
    airLinePhone = phone;
}

void Airline::addFlight(string dep, string arr, Time depTime, Time arrTime) {                                          
    Flight *temp= new Flight[numFlights];
    for (int i = 0; i < numFlights; i++) {
        temp[i] = flights[i];
    }
    flights = new Flight[++numFlights];
    for (int i = 0; i < numFlights-1; i++) {
        flights[i] = temp[i];
    }
    flights[numFlights-1] = Flight(dep, arr, depTime, arrTime);
    delete[] temp;
}

void Airline::removeFlight(string ident) {
    bool isFound=false;
    if(numFlights == 0) {
        cout << "No flights to remove." << endl;
        return;
    }

    Flight * temp= new Flight[numFlights];

    for(int i=0;i<numFlights;i++){
        temp[i]=flights[i];
         if(flights[i].getFlightIdent()==ident)
            isFound=true;
    }

    if(!isFound){
        delete [] temp;
        cout<<"Flight not in system"<<endl;
        return;
    }


    flights= new Flight[--numFlights];

    for(int i=0; i<numFlights;){
        if(temp[i].getFlightIdent()==ident)
            i++;
        else{
            flights[i]=temp[i];
            i++;
        }

    }




}

void Airline::listFlights() const {
    for (int i = 0; i < numFlights; i++) {
        cout << flights[i].getFlightIdent() << endl;
    }
}

void Airline::listFlights(string depCity, string arrCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getDeparture() == depCity && flights[i].getArrival() == arrCity) {
            cout << flights[i].getFlightIdent() << endl;
        }
    }
}

void Airline::listFlights(string depCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getDeparture() == depCity) {
            cout << flights[i].getFlightIdent() << endl;
        }
    }
}

void Airline::listFlights(string arrCity) const {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getArrival() == arrCity) {
            cout << flights[i].getFlightIdent() << endl;
        }
    }
}

int Airline::getNumFlights() const {
    return numFlights;
}
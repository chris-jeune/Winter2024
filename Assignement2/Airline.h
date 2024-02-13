// Author: Christian Jeune, ID: 40279265

#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include "Flight.h"
using namespace std;

class Airline
{
private:
    string airLineName; /**< The name of the airline. */
    string airLineAddress; /**< The address of the airline. */
    string airLinePhone; /**< The phone number of the airline. */
    int numFlights; /**< The number of flights of the airline. */
    Flight *flights; /**< The flights of the airline. */

public:
    /**
     * @brief Default constructor for the Airline class.
     */
    Airline();

    /**
     * @brief Parameterized constructor for the Airline class.
     * @param name The name of the airline.
     * @param address The address of the airline.
     * @param phone The phone number of the airline.
     * @param number number of flights of the airline.
     * @param flights The flights of the airline.
     */
    Airline(string name, string address, string phone, int number, Flight *flights);

    /**
     * @brief Destructor for the Airline class.
     */
    ~Airline();

    /**
     * @brief Get the name of the airline.
     * @return The name of the airline.
     */
    string getAirLineName() const;

    /**
     * @brief Get the address of the airline.
     * @return The address of the airline.
     */
    string getAirLineAddress() const;

    /**
     * @brief Get the phone number of the airline.
     * @return The phone number of the airline.
     */
    string getAirLinePhone() const;

    /**
     * @brief Set the name of the airline.
     * @param name The name of the airline.
     */
    void setAirLineName(string name);

    /**
     * @brief Set the address of the airline.
     * @param address The address of the airline.
     */
    void setAirLineAddress(string address);

    /**
     * @brief Set the phone number of the airline.
     * @param phone The phone number of the airline.
     */
    void setAirLinePhone(string phone);

    /**
     * @brief add a flight to the airline.
     * @param dep departing city
     * @param arr arriving city
     * @param depTime departing time
     * @param arrTime arriving time
     */
    void addFlight(string dep, string arr, Time depTime, Time arrTime);

    /**
     * @brief Remove a flight from the airline.
     * @param ident The identification of the flight.
     */
    void removeFlight(string ident);

    /**
     * @brief List all flights of the airline.
     */
    void listFlights() const;

    /**
     * @brief List all flights of the airline departing and arriving to specific cities.
     */
    void listFlights(string depCity, string arrCity) const; 

    /**
     * @brief List all flights of the airline departing from a specific city.
     */
    void listFlights(string depCity) const;

    /**
     * @brief List all flights of the airline arriving to a specific city.
     */
    void listFlights(string arrCity) const;  

    /**
     * @brief Get the number of flights of the airline.
     * @return The number of flights of the airline.
     */
    int getNumFlights() const;

};

#endif // AIRLINE_H
// Author: Christian Jeune, ID: 40279265

#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include "Flight.h"
#include "Passenger.h"

using namespace std;

class Airline
{
friend class Booking;// Friend class
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
     * @param number Number of flights of the airline.
     */
    Airline(string name, string address, string phone, int number);

    /**
     * @brief Parameterized constructor for the Airline class.
     * @param name The name of the airline.
     * @param address The address of the airline.
     * @param phone The phone number of the airline.
     * @param list Pointer to an array of flights.
     * @param number Number of flights of the airline.
     */
    Airline(string name, string address, string phone, Flight * list, int number);

    /**
     * @brief Copy constructor for the Airline class.
     * @param obj The Airline object to copy.
     */
    Airline(const Airline &obj);

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
    void setAirLineName(const string & name);

    /**
     * @brief Set the address of the airline.
     * @param address The address of the airline.
     */
    void setAirLineAddress(const string & address);

    /**
     * @brief Set the phone number of the airline.
     * @param phone The phone number of the airline.
     */
    void setAirLinePhone(string phone);

    /**
     * @brief Add a flight to the airline.
     * @param dep Departing city.
     * @param arr Arriving city.
     * @param depTime Departing time.
     * @param arrTime Arriving time.
     */
    void addFlight(const string & dep, const string & arr, const Time & depTime,const Time & arrTime);

    /**
     * @brief Add a flight to the airline.
     * @param flight The flight to add.
     */
    void addFlight(Flight flight);

    /**
     * @brief Add multiple flights to the airline.
     * @param flight Pointer to an array of flights.
     * @param number Number of flights to add.
     */
    void addFlight(Flight * flight, int number);

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
     * @param depCity Departing city.
     * @param arrCity Arriving city.
     */
    void listFlights(string depCity, string arrCity) const; 

    /**
     * @brief List all flights of the airline departing from a specific city.
     * @param depCity Departing city.
     */
    void listFlightsDep(string depCity) const;

    /**
     * @brief List all flights of the airline arriving to a specific city.
     * @param arrCity Arriving city.
     */
    void listFlightsArr(string arrCity) const;  

    /**
     * @brief Get the number of flights of the airline.
     * @return The number of flights of the airline.
     */
    int getNumFlights() const;

    /**
     * @brief Get a specific flight by its identifier.
     * @param ident The identifier of the flight.
     * @return The flight object.
     */
    Flight  getFlight(string ident);

    /**
     * @brief Update the identifier of a flight.
     * @param flight The flight object to update.
     */
    void updateFlightIdent(Flight & flight);

};

#endif // AIRLINE_H

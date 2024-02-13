// Author: Christian Jeune, ID: 40279265

#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include "Booking.h"

using namespace std;

/**
 * @brief The Passenger class represents a passenger with its name and passport number.
 */
class Passenger {
private:
    string name; /**< The name of the passenger. */
    const string id; /**< The id of the passenger. */
    string address; /**< The address of the passenger. */
    string phone; /**< The phone number of the passenger. */
    Booking *bookings; /**< The bookings of the passenger. */ 
    static int passengerCount; /**< The count of total passengers created. */
    inline string createPassengerId() const;

public:

    /**
     * @brief Default constructor for the Passenger class.
     */
    Passenger();

    /**
     * @brief Parameterized constructor for the Passenger class.
     * @param name The name of the passenger.
     * @param id The id of the passenger.
     * @param address The address of the passenger.
     * @param phone The phone number of the passenger.
     */
    Passenger(string name, string address, string phone);

    /**
     * @brief Get the name of the passenger.
     * @return The name of the passenger.
     */
    string getName() const;

    /**
     * @brief Get the id of the passenger.
     * @return The id of the passenger.
     */
    string getId() const;

    /**
     * @brief Get the address of the passenger.
     * @return The address of the passenger.
     */
    string getAddress() const;

    /**
     * @brief Get the phone number of the passenger.
     * @return The phone number of the passenger.
     */
    string getPhone() const;

    /**
     * @brief Set the name of the passenger.
     * @param name The name of the passenger.
     */
    void setName(string name);

    /**
     * @brief Set the address of the passenger.
     * @param address The address of the passenger.
     */
    void setAddress(string address);

    /**
     * @brief Set the phone number of the passenger.
     * @param phone The phone number of the passenger.
     */
    void setPhone(string phone);

    /**
     * @brief Print the passenger information.
     */
    void printPassenger() const;

};

#endif // PASSENGER_H

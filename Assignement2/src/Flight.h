//Author: Christian Jeune, ID: 40279265

#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include "Time.h"
using namespace std;

class Booking; 
class Passenger;
/**
 * @brief The Flight class represents a flight with its departure and arrival information.
 */
class Flight {

friend class Booking;

private:
    static const int MAX_SEATS = 156; /**< The number of seats of the flight. */
    static const string airlineName; /**< The name of the airline. */
    string flightIdent; /**< The identification code of the flight. */
    string departure; /**< The departure city of the flight. */
    string arrival; /**< The arrival city of the flight. */
    Time *departureTime; /**< The departure time of the flight. */
    Time *arrivalTime; /**< The arrival time of the flight. */
    int flightDuration; /**< The duration of the flight in minutes. */
    Booking * bookings; /**< The bookings of the flight. */
    int bookingCount; /**< The count of total bookings created. */
    static int flightCount; /**< The count of total flights created. */

    /**
     * @brief Create a unique identification code for the flight.
     * @return The identification code of the flight.
     */
    string createFlightIdent() const;

    /**
     * @brief Calculate the duration of the flight in minutes.
     * @return The duration of the flight in minutes.
     */
    int flightDurationCalc() const;


public:

    /**
     * @brief Default constructor for the Flight class.
     */
    Flight();

    /**
     * @brief Parameterized constructor for the Flight class.
     * @param dep The departure city of the flight.
     * @param arr The arrival city of the flight.
     * @param depTime The departure time of the flight.
     * @param arrTime The arrival time of the flight.
     */
    Flight(string dep, string arr, Time depTime, Time arrTime);

    /**
     * @brief Copy constructor for the Flight class.
     * @param obj The Flight object to be copied.
     */
    Flight(const Flight &obj);

    /**
     * @brief Destructor for the Flight class.
     */
    ~Flight();

    /**
     * @brief Get the identification code of the flight.
     * @return The identification code of the flight.
     */
    string getFlightIdent() const;

    /**
     * @brief Get the departure city of the flight.
     * @return The departure city of the flight.
     */
    string getDeparture() const;

    /**
     * @brief Get the arrival city of the flight.
     * @return The arrival city of the flight.
     */
    string getArrival() const;

    /**
     * @brief Get the departure time of the flight.
     * @return A pointer to the departure time of the flight.
     */
    Time getDepartureTime() const;

    /**
     * @brief Get the arrival time of the flight.
     * @return A pointer to the arrival time of the flight.
     */
    Time getArrivalTime() const;

    /**
     * @brief Get the duration of the flight in minutes.
     * @return The duration of the flight in minutes.
     */
    int getFlightDuration() const;


    /**
     * @brief Set the departure and arrival cities of the flight.
     * @param dep The departure city of the flight.
     * @param arr The arrival city of the flight.
     */
    void setCities(const string& dep, const string& arr);

    /**
     * @brief Set the departure time of the flight.
     * @param depTime The departure time of the flight.
     */
    void setDepartureTime(const Time& depTime);

    /**
     * @brief Set the arrival time of the flight.
     * @param arrTime The arrival time of the flight.
     */
    void setArrivalTime(const Time& arrTime);

    /**
     * @brief Print the details of the flight.
     */
    void printFlight() const;

    void listBookings() const;

    void setFlightIdent(string ident);

    void addBooking(Booking *  booking, Passenger *pass);


};

#endif // FLIGHT_H
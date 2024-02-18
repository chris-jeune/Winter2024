// Author: Christian Jeune, ID: 40279265
#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "Airline.h"

using namespace std;

class Booking {
private:
    Passenger* passenger; /**< The passenger of the booking. */
    Flight* flight; /**< The flight of the booking. */
    string seatNumber; /**< The identification code of the seat. */
    static int bookingCount; /**< The count of total bookings created. */

    /**
     * @brief Generate a unique seat number for the booking.
     * @return A unique seat number.
     */
    string creatSeatNumber() const;

public:
    Booking(); // Default constructor

    /**
     * @brief Parameterized constructor for the Booking class.
     * @param pass The passenger of the booking.
     * @param ident The identifier of the flight.
     * @param airline The airline the flight belongs to.
     */
    Booking(Passenger& pass, string ident, Airline& airline);

    /**
     * @brief Copy constructor for the Booking class.
     * @param obj The Booking object to be copied.
     */
    Booking(const Booking& obj);

    /**
     * @brief Destructor for the Booking class.
     */
    ~Booking();

    /**
     * @brief Get the passenger of the booking.
     * @return The passenger of the booking.
     */
    Passenger* getPassenger() const;

    /**
     * @brief Get the flight of the booking.
     * @return The flight of the booking.
     */
    Flight* getFlight() const;

    /**
     * @brief Get the seat number of the booking.
     * @return The seat number of the booking.
     */
    string getSeatNumber() const;

    /**
     * @brief Set the passenger of the booking.
     * @param pass The passenger of the booking.
     */
    void setPassenger(Passenger* pass);

    /**
     * @brief Set the flight of the booking.
     * @param fl The flight of the booking.
     */
    void setFlight(Flight* fl);

    /**
     * @brief Set the seat number of the booking.
     * @param seat The seat number of the booking.
     */
    void setSeatNumber(string seat);

    /**
     * @brief Static method to cancel a booking.
     * @param pass The passenger whose booking is to be canceled.
     * @param bookid The seat number of the booking to be canceled.
     * @param flid The identifier of the flight.
     */
    static void cancelBooking(Passenger& pass, string bookid, string flid);

    /**
     * @brief Print details of the booking.
     */
    void printBooking() const;

};

#endif // BOOKING_H

#ifndef BOOKING_H
#define BOOKING_H

#include "Passenger.h"
#include "Flight.h"

class Booking{
private:
    Passenger * passenger; /**< The passenger of the booking. */
    const Flight * const flight; /**< The flight of the booking. */
    const string seatNumber; /**< The identification code of the seatNumber. */
    static int bookingCount; /**< The count of total bookings created. */

    /**
     * @brief Create a unique identification code for the booking.
     * @return The identification code of the booking.
     */
    inline string createSeatNumber() const;

public:
    /**
     * @brief Parameterized constructor for the Booking class.
     * @param passenger The passenger of the booking.
     * @param flight The flight of the booking.
     */
    Booking(Passenger * passenger, Flight * flight);

    /**
     * @brief Destructor for the Booking class.
     */
    ~Booking();

    /**
     * @brief Get the passenger of the booking.
     * @return The passenger of the booking.
     */
    Passenger * getPassenger() const;

    /**
     * @brief Get the flight of the booking.
     * @return The flight of the booking.
     */
    Flight * getFlight() const;

    /**
     * @brief Get the seat number of the booking.
     * @return The seat number of the booking.
     */
    string getSeatNumber() const;

    /**
     * @brief Set the seat number of the booking.
     * @param seatNumber The seat number of the booking.
     */
    void setSeatNumber(string seatNumber);

    /**
     * @brief Get the count of total bookings created.
     * @return The count of total bookings created.
     */
    static int getBookingCount();
};



#endif // BOOKING_H

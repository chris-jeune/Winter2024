#ifndef BOOKING_H
#define BOOKING_H


#include <string>
#include "Airline.h"

using namespace std;

class Booking{
    
private:
    Passenger * passenger; /**< The passenger of the booking. */
    Flight * flight; /**< The flight of the booking. */
    string seatNumber; /**< The identification code of the seatNumber. */
    static int bookingCount; /**< The count of total bookings created. */


public:
    Booking();


    /**
     * @brief Parameterized constructor for the Booking class.
     * @param passenger The passenger of the booking.
     * @param flight The flight of the booking.
     */
    Booking(Passenger & pass, string ident, Airline & airline);

    Booking(const Booking &obj);

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

    void setPassenger(Passenger * pass);

    void setFlight(Flight * fl);

    void setSeatNumber(string seat);

    /**
     * @brief Get the count of total bookings created.
     * @return The count of total bookings created.
     */
    static int getBookingCount();

    /**
     * @brief Overloaded assignment operator for the Booking class.
     * @param obj The Booking object to be assigned.
     * @return The Booking object to be assigned.
     */

    static void cancelBooking(Passenger& pass, string bookid, string flid, Airline & airline);

    
};



#endif // BOOKING_H
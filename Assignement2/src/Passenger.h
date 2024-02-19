// Author: Christian Jeune, ID: 40279265
#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

using namespace std;

// Forward declarations
class Booking;

/**
 * @brief The Passenger class represents a passenger with its name, ID, address, and phone number.
 */
class Passenger {
friend class Booking; // Friend class
private:
    string name; /**< The name of the passenger. */
    string id; /**< The ID of the passenger. */
    string address; /**< The address of the passenger. */
    string phone; /**< The phone number of the passenger. */
    Booking *bookings; /**< The bookings of the passenger. */
    int bookingCount; /**< The count of total bookings created. */
    static int passengerCount; /**< The count of total passengers created. */
    
    /**
     * @brief Creates a unique passenger ID based on the passenger count.
     * @return The generated passenger ID.
     */
    string createPassengerId() const;

public:
    /**
     * @brief Default constructor for the Passenger class.
     */
    Passenger();

    /**
     * @brief Parameterized constructor for the Passenger class.
     * @param name The name of the passenger.
     * @param address The address of the passenger.
     * @param phone The phone number of the passenger.
     */
    Passenger(string name, string address, string phone);

    /**
     * @brief Copy constructor for the Passenger class.
     * @param obj The Passenger object to be copied.
     */
    Passenger(const Passenger &obj);

    /**
     * @brief Destructor for the Passenger class.
     */
    ~Passenger();

    /**
     * @brief Get the name of the passenger.
     * @return The name of the passenger.
     */
    string getName() const;

    /**
     * @brief Get the ID of the passenger.
     * @return The ID of the passenger.
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

    /**
     * @brief List all bookings associated with the passenger.
     */
    void listBookings() const;

    /**
     * @brief Add a booking to the passenger's list of bookings.
     * @param book The booking to be added.
     * @param fl The flight associated with the booking.
     */
    void addBooking(Booking * book);

};

#endif // PASSENGER_H

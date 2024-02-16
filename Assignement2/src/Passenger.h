// Author: Christian Jeune, ID: 40279265

#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

using namespace std;

class Booking;

/**
 * @brief The Passenger class represents a passenger with its name and passport number.
 */
class Passenger {
private:
    string name; /**< The name of the passenger. */
    string id; /**< The id of the passenger. */
    string address; /**< The address of the passenger. */
    string phone; /**< The phone number of the passenger. */
    Booking *bookings; /**< The bookings of the passenger. */
    int bookingCount;
    static int passengerCount; /**< The count of total passengers created. */
    string createPassengerId() const;
    void addBooking(Booking & book);

    bool cancelBooking(string bookid);

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

    Booking * getBooking(string bookid) const;

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

    void listBookings() const;

    friend class Booking;

};

#endif // PASSENGER_H

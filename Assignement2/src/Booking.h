#include "Passenger.h"
#include "Flight.h"
#include <string>

class Booking {
private:
    Passenger passenger;
    Flight flight;
    std::string seatNumber;

    std::string createSeatNumber();
    static int bookingCount;

public:
    // Default constructor
    Booking() {}

    // Constructor with parameters
    Booking(const Passenger& passenger, const Flight& flight)
        : passenger(passenger), flight(flight), seatNumber(seatNumber) {}

    // Copy constructor
    Booking(const Booking& other)
        : passenger(other.passenger), flight(other.flight), seatNumber(other.seatNumber) {}

    // Destructor
    ~Booking() {}

    // Getters
    const Passenger& getPassenger() const {
        return passenger;
    }

    const Flight& getFlight() const {
        return flight;
    }

    const std::string& getSeatNumber() const {
        return seatNumber;
    }
};

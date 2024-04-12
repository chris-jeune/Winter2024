#include "Data.h"
#include <iostream>
using namespace std;

// Function to test the setTime method of the Data class
void testSetTime() {
    Data runner;
    // Array of record times for testing
    double recordTime[5] = {5, -30.5, 20.986565, 500000000, 19.2};
    cout << "Test for setTime." << endl;
    // Set the time using the test data and display the statistics
    runner.setTime(recordTime);
    runner.display();
}

// Function to test the setDistance method of the Data class
void testSetDistance() {
    Data runner;
    cout << "Test 1:" << endl;
    // Set the distance to a positive value and display the statistics
    runner.setDistance(5);
    runner.display();
    cout << "Test 2" << endl;
    // Set the distance to a negative value (should be set to 0) and display the statistics
    runner.setDistance(-30.5);
    runner.display();
    cout << "Test 3" << endl;
    // Set the distance to a positive value and display the statistics
    runner.setDistance(50.2);
    runner.display();
}

// Function to test the statistics method of the Data class
void testStatistics() {
    Data runner;
    // Array of record times for testing
    double recordTime[5] = {5, -30.5, 20.986565, 500000000, 19.2};
    // Set the time using the test data and calculate statistics
    runner.setTime(recordTime);
    runner.statistics();
}

// Main function to interactively gather user input for runner statistics
int main() {
    // Uncomment the following lines to test the functions individually
    // testSetDistance();
    // testSetTime();
    // testStatistics();

    double recordTime[5];
    int distance;
    double time;
    cout << "Welcome to runner statistics. Which distance would you like to analyze? ";
    cin >> distance;
    cout << endl << "Please enter your five best times for that event: ";

    // Gather user input for five best times
    for (int i = 0; i < 5; i++) {
        cin >> time;
        recordTime[i] = time;
    }

    // Create a Data object, set distance and time, calculate statistics, and display
    Data runner;
    runner.setDistance(distance);
    runner.setTime(recordTime);
    runner.statistics();
    cout << endl;
    runner.display();
    return 0;
}

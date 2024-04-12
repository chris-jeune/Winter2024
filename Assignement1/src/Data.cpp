#include "Data.h"
#include <iostream>
using namespace std;

// Function to calculate statistics (min, max, average)
void Data::statistics() {
    double total = time[0];
    double highest = time[0];
    double lowest = time[0];

    // Loop through the time array to calculate total, highest, and lowest
    for (int i = 1; i < 5; i++) {
        total += time[i];

        if (time[i] < lowest)
            lowest = time[i];

        if (time[i] > highest)
            highest = time[i];
    }

    // Update the member variables with calculated values
    min = lowest;
    max = highest;
    average = total / 5;
}

// Function to set the time array
void Data::setTime(double* record) {
    // Loop through the record array to set the time array
    for (int i = 0; i < 5; i++) {
        // Ensure non-negative values for time, set to 0 if negative
        if (record[i] > 0)
            time[i] = record[i];
        else
            time[i] = 0;
    }
}

// Function to set the distance value
void Data::setDistance(int dist) {
    // Ensure non-negative values for distance, set to 0 if negative
    if (dist > 0)
        distance = dist;
    else
        distance = 0;
}

// Function to display the statistics
void Data::display() {
    cout << "Statistic of the runner for the " << distance << "km." << endl;
    cout << "All times: ";
    // Loop through the time array to display all times
    for (int i = 0; i < 4; i++) {
        cout << time[i] << ", ";
    }
    cout << time[4] << endl;

    // Displaying statistics
    cout << "Worst time: " << max << endl;
    cout << "Best time: " << min << endl;
    cout << "Average time: " << average << endl << endl;
}

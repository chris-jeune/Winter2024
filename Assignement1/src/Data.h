#ifndef DATA_H_
#define DATA_H_

// Declaration of the Data class
class Data {
public:
    // Function to calculate statistics (min, max, average)
    void statistics();

    // Function to set the time array
    void setTime(double*);

    // Function to set the distance value
    void setDistance(int);

    // Function to display the statistics
    void display();

private:
    double time[5];   // Array to store time values in seconds (assuming a fixed size of 5)
    int distance;     // Distance in meters
    double min, max, average;  // Variables to store the calculated statistics

};

#endif // DATA_H_

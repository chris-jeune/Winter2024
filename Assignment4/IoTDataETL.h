#ifndef IOTDATAETL_H_
#define IOTDATAETL_H_

#include <limits.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "RankOneTensorType.h"

using namespace std;

class IoTDataETL
{

public:
    IoTDataETL()
    {
        iot_category.resize(0);
        iot_data.resize(0);
    }

    double getValue(int row, int col)
    {
        double value{INT_MAX};
        try
        {
            RankOneTensorType<string> tensor = iot_data[row];

            value = stod(tensor[col]);
        }
        catch (invalid_argument &e)
        {
            cerr << "Invalid argument: " << e.what() << endl;
        }
        catch (out_of_range &e)
        {
            cerr << "Out of range: " << e.what() << endl;
        }

        return value;
    }

    void loadData(string fileLocation)
    {
        ifstream file(fileLocation);
        if (!file)
        {
            string error_msg = fileLocation + " was not open properly!";
            throw runtime_error(error_msg);
        }

        string line;
        getline(file, line);
        std::stringstream lineString(line);

        int size(0);
        string token;
        while (getline(lineString, token, ','))
        {
            cout << token << endl;
            iot_category.push_back(token);
            ++size;
        }

        while (getline(file, line))
        {
            lineString.clear();
            lineString.str("");
            lineString.str(line);
            string token;

            RankOneTensorType<string> tensor(0);
            lineString >> tensor;
            cout << tensor << endl;
            iot_data.push_back(tensor);
        }
        file.close();
    }

    string getCategory(int index)
    {
        return iot_category[index];
    }

    int getIndex(string category)
    {
        for (int i = 0; i < iot_category.size(); i++)
        {
            if (iot_category[i] == category)
            {
                return i;
            }
        }
        return -1;
    }

    RankOneTensorType<string> extractColValues(int index)
    {
        RankOneTensorType<string> tensor(0);
        for (RankOneTensorType<string> t : iot_data)
        {
            tensor.insertData(t[index]);
        }
        return tensor;
    }

private:
    vector<string> iot_category;
    vector<RankOneTensorType<string>> iot_data;
};

#endif

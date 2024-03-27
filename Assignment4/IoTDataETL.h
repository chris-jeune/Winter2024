#ifndef IOTDATAETL_H_
#define IOTDATAETL_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "RankOneTensorType.h"

using namespace std;

class IoTDataETL{

public:

    IoTDataETL (){
        iot_category.resize(0);

    }

    double getValue(int row, int col){
        //return iot_data[row].get(col);
        return 0;
    }

    void loadData( string fileLocation){
        ifstream file(fileLocation);
        if(!file){
            string error_msg = fileLocation + " was not open properly!";
            throw runtime_error(error_msg);
        }
        
        string line;
        getline(file,line);
        std::stringstream lineString(line);

        int size(0);
        string token;
        while(getline(lineString, token, ',')){
            cout<<token<<endl;
            iot_category.push_back(token);
            ++size;
        }

        while(getline(file,line)){
            lineString.clear();
            lineString.str("");
            lineString.str(line);
            string token;
            
            while(getline(lineString, token, ',')){
                cout<<token<<endl;
            }

            //lineString >>tensor;
            //cout<< tensor<<endl;
            //iot_data.push;
        }

    }

private:
    vector<string> iot_category;
    // vector<RankOneTensorType<string>> iot_data;

};

#endif

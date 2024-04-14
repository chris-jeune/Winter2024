//Christian Jeune
//ID: 40279265

#include "IoTDataETL.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void testExtractColumn(){
    IoTDataETL iot;
    try{
        iot.loadData("iot-shard.txt");
        int row=0;
        int col=5;
        cout<<"Correct numeric values: "<<endl;
        cout<< iot.getCategory(col)<<": "<<iot.getValue(row,col)<<endl;
        cout<<iot.extractColValues(col);
        col=3;
        cout<<"Non numeric values: "<<endl;
        cout<<iot.getCategory(col)<<": "<<iot.getValue(row,col)<<endl;
        cout<<iot.extractColValues(col);

    } catch(runtime_error &e){
        cerr<<e.what()<<endl;
    }
}

void testIot(){
    IoTDataETL file;
    try{
    file.loadData("iot-shard.txt");
    // cout<< file.getValue(0,3);
    // cout<< file.getValue(1,5);
    // cout<< file.getValue(1,3);
    // cout<< file.getValue(17,5);
    // cout<< file.getValue(1,300);
    cout<< file.getValue(2,7);
    }catch(runtime_error &e){
        cerr<<e.what()<<endl;
    }
    cout<<endl;
}

int main(){
    testExtractColumn();
    //testIot();
    return 0;
}
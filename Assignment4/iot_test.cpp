#include "IoTDataETL.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void testIot(){
    IoTDataETL iot;
    try{
        iot.loadData("RT_IOT22.txt");
        int row=0;
        int col=5;
        int index = iot.getIndex(iot.getCategory(col));
        cout<< iot.getCategory(col)<<": "<<iot.getValue(row,col)<<endl;
        cout<<iot.extractColValues(index);
    } catch(runtime_error &e){
        cerr<<e.what()<<endl;
    }
}
void testLoadFile(){
    IoTDataETL file;
    try{
    file.loadData("RT_IOT22.txt");
    cout<< file.getValue(0,3);
    }catch(runtime_error &e){
        cerr<<e.what()<<endl;
    }
}

int main(){
    testIot();
    //testLoadFile();
    return 0;
}
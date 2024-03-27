#include "IoTDataETL.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


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
    testLoadFile();
    return 0;
}
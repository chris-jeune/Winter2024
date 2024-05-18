#ifndef RANKFOURTENSOR_H_
#define RANKFOURTENSOR_H_

#include "BaseTensor.h"
#include "RankThreeTensor.h"
#include <vector>
#include <iostream>

using namespace std;
class RankFourTensor : public BaseTensor{
private:
    std::vector<RankThreeTensor> data;
public:
    RankFourTensor(): data() {}

    RankFourTensor(int rows, int cols, int floors, int t1): data(rows, RankThreeTensor(cols, floors,t1)){}

    ~RankFourTensor() override {}
    
    void loadData() override{
        for(int i=0; i<data.size(); i++){
            data[i].loadData();
        }
    }
    
    RankFourTensor& operator=(const RankFourTensor& obj){
        if(this!= &obj){
        data.resize(obj.data.size());
        for(int i=0;i<data.size();i++){
            data[i]=obj.data[i];
        }
        
        }
        return *this;
    }

    //prefix
    RankFourTensor operator++(){
        for(int i=0; i<data.size(); i++){
            data[i]++;
        }
        return *this;
    }

    //postfix
    RankFourTensor operator++(int){
        RankFourTensor t=*this;
        for(int i=0; i<data.size(); i++){
            data[i]++;
        }
        return t;
    }

    //prefix
    RankFourTensor operator--(){
        for(int i=0; i<data.size(); i++){
            data[i]--;
        }
        return *this;
    }

    //postfix
    RankFourTensor operator--(int){
        RankFourTensor t=*this;
        for(int i=0; i<data.size(); i++){   
            data[i]--;
        }
        return t;
    }

    RankFourTensor operator+(const RankFourTensor& obj) {
        int rows = max(data.size(), obj.data.size());

        RankFourTensor newObj(rows, 0, 0,0);

        for(int i = 0; i < rows; i++) {
            newObj.data[i] = data[i] + obj.data[i];
        }

        return newObj;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const RankFourTensor& tensor){
        os<< "Four dimension data: "<<std::endl;
        for(int i=0; i<tensor.data.size(); i++){
            os<< tensor.data[i];
        }
        return os;

    }

    friend std::istream& operator>>(std::istream& in, RankFourTensor& tensor){
        cout<< "Please type in your values to the RankFourTensor "<<endl;
        for(int i=0; i<tensor.data.size(); i++){
           in>>tensor.data[i];
        }
        return in;
    }

};
#endif // RankThreeTensor_H_  
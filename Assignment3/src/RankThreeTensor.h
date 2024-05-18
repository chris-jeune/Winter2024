#ifndef RANKTHREETENSOR_H_
#define RANKTHREETENSOR_H_

#include "BaseTensor.h"
#include "RankTwoTensor.h"
#include <vector>
#include <iostream>

using namespace std;
class RankThreeTensor : public BaseTensor{
private:
    std::vector<RankTwoTensor> data;
public:
    RankThreeTensor(): data(){}

    RankThreeTensor(int rows, int cols, int floors): data(rows, RankTwoTensor(cols, floors)){}

    ~RankThreeTensor() override {}
    
    void loadData() override{
        for(int i=0; i<data.size(); i++){
            data[i].loadData();
        }
    }
    
    RankThreeTensor& operator=(const RankThreeTensor& obj){
        if(this!= &obj){
        data.resize(obj.data.size());
        for(int i=0;i<data.size();i++){
            data[i]=obj.data[i];
        }
        
        }
        return *this;
    }

    //prefix
    RankThreeTensor operator++(){
        for(int i=0; i<data.size(); i++){
            data[i]++;
        }
        return *this;
    }

    //postfix
    RankThreeTensor operator++(int){
        RankThreeTensor t=*this;
        for(int i=0; i<data.size(); i++){
            data[i]++;
        }
        return t;
    }

    //prefix
    RankThreeTensor operator--(){
        for(int i=0; i<data.size(); i++){
            data[i]--;
        }
        return *this;
    }

    //postfix
    RankThreeTensor operator--(int){
        RankThreeTensor t=*this;
        for(int i=0; i<data.size(); i++){   
            data[i]--;
        }
        return t;
    }

    RankThreeTensor operator+(const RankThreeTensor& obj) {
        int rows = max(data.size(), obj.data.size());

        RankThreeTensor newObj(rows, 0, 0);

        for(int i = 0; i < rows; i++) {
            newObj.data[i] = data[i] + obj.data[i];
        }

        return newObj;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const RankThreeTensor& tensor){
        os<< "Three dimension data: "<<std::endl;
        for(int i=0; i<tensor.data.size(); i++){
            os<< tensor.data[i];
        }
        return os;

    }

    friend std::istream& operator>>(std::istream& in, RankThreeTensor& tensor){
        cout<< "Please type in your values to the RankThreeTensor "<<endl;
        for(int i=0; i<tensor.data.size(); i++){
           in>>tensor.data[i];
        }
        return in;
    }

};
#endif // RankTwoTensor_H_  
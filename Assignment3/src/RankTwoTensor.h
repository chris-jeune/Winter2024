#ifndef RANKTWOTENSOR_H_
#define RANKTWOTENSOR_H_

#include "BaseTensor.h"
#include <vector>
#include <iostream>

using namespace std;
class RankTwoTensor : public BaseTensor{
private:
    std::vector<RankOneTensor> data;
public:
    RankTwoTensor(): data(){}

    RankTwoTensor(int rows, int cols): data(rows, RankOneTensor(cols)){}

    ~RankTwoTensor() override {}
    
    void loadData() override{
        for(int i=0; i<data.size(); i++){
            data[i].loadData();
        }
    }
    
    RankTwoTensor& operator=(const RankTwoTensor& obj){
        if(this!= &obj){
        data.resize(obj.data.size());
        for(int i=0;i<data.size();i++){
            data[i]=obj.data[i];
        }
        
        }
        return *this;
    }

    //prefix
    RankTwoTensor operator++(){
        for(int i=0; i<data.size(); i++){
            data[i]++;
        }
        return *this;
    }

    //postfix
    RankTwoTensor operator++(int){
        RankTwoTensor t=*this;
        for(int i=0; i<data.size(); i++){
            data[i]++;
        }
        return t;
    }

    //prefix
    RankTwoTensor operator--(){
        for(int i=0; i<data.size(); i++){
            data[i]--;
        }
        return *this;
    }

    //postfix
    RankTwoTensor operator--(int){
        RankTwoTensor t=*this;
        for(int i=0; i<data.size(); i++){   
            data[i]--;
        }
        return t;
    }

    RankTwoTensor operator+(const RankTwoTensor& obj) {
        int rows = max(data.size(), obj.data.size());

        RankTwoTensor newObj(rows, 0);

        for(int i = 0; i < rows; i++) {
            newObj.data[i] = data[i] + obj.data[i];
        }

        return newObj;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const RankTwoTensor& tensor){
        os<< "Two dimension data: "<<std::endl;
        for(int i=0; i<tensor.data.size(); i++){
            os<< tensor.data[i];
        }
        return os;

    }

    friend std::istream& operator>>(std::istream& in, RankTwoTensor& tensor){
        cout<< "Please type in your values to the RankTwoTensor "<<endl;
        for(int i=0; i<tensor.data.size(); i++){
           in>>tensor.data[i];
        }
        return in;
    }

};
#endif // RANKONETENSOR_H_  
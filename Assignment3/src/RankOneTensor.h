#ifndef RANKONETENSOR_H_
#define RANKONETENSOR_H_

#include "BaseTensor.h"
#include <vector>
#include <iostream>

using namespace std;
class RankOneTensor : public BaseTensor{
private:
    std::vector<double> data;
    std::vector<double> gradient;
public:
    RankOneTensor(int size):data(size),gradient(size) {}

    ~RankOneTensor() override {}
    
    void loadData() override{
        std::fill(data.begin(), data.end(), valueGen());
    }

    //prefix increment
    RankOneTensor operator++(){
        for (int i = 0; i < data.size(); i++) {
            data[i]+=1;
        }
        return *this;
    }

    //postfix increment
    RankOneTensor operator++(int){
        RankOneTensor t=*this;
        for (int i = 0; i < data.size(); i++) {
            data[i]+=1;
        }
        return t;
    }

    //prefix decrement
    RankOneTensor operator--(){
        for (int i = 0; i < data.size(); i++) {
            data[i]-=1;
        }
        return *this;
    }

    //postfix decrement
    RankOneTensor operator--(int){
        RankOneTensor t=*this;
        for (int i = 0; i < data.size(); i++) {
            data[i]-=1;
        }
        return t;
    }

    RankOneTensor& operator=(const RankOneTensor& obj){
       if(this!= &obj){
            // Perform the assignment operation
            data.resize(obj.data.size());
            for (int i = 0; i < obj.data.size(); i++) {
                data[i] = obj.data[i];
            }
        }
        return *this;
    }
    
    RankOneTensor operator+(const RankOneTensor& obj){
        int index= max(data.size(), obj.data.size());

        RankOneTensor newObj(index);

        for (int i=0; i<index;  i++){
            double val1=(i<data.size())?data[i]:0;
            double val2=(i<obj.data.size())?obj.data[i]:0;
            newObj.data[i]=val1+val2;
        }

        return newObj;
    }

    friend std::ostream& operator<<(std::ostream& os, const RankOneTensor& tensor){
        os<< "Data: [";
        for (size_t i=0; i<tensor.data.size(); i++){
            os<<tensor.data[i];
            if(i<tensor.data.size()-1)
                os<<", ";
        }
        os<<']'<<std::endl;
        return os;
    }


    friend std::istream& operator>>(std::istream& in, RankOneTensor& tensor){
        cout<< "Please type in your values to the RankOneTensor "<<endl;
        for(size_t i=0; i<tensor.data.size();i++){
            in >> tensor.data[i];
        }
        return in;
    }
};
#endif // RANKONETENSOR_H_  
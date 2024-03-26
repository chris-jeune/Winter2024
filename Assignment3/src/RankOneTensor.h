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

    RankOneTensor operator=(const RankOneTensor& obj){
        if(this!= &obj){
            RankOneTensor newObj(obj.data.size());
            for (int i=0; i<obj.data.size();i++){
                newObj.data[i]=obj.data[i];
            }
            return newObj;
        }
        return *this;
    }
    
    RankOneTensor operator+(const RankOneTensor& obj){
        if(data.size()>=obj.data.size()){
        RankOneTensor newObj(data.size());
        int i=0;
            for (; i<obj.data.size();i++){
                newObj.data[i]=data[i]+obj.data[i];
            }
            for (;i<data.size();i++){
                newObj.data[i]=data[i];
            }
            return newObj;
        }

        RankOneTensor newObj(obj.data.size());
        int i=0;
        for (; i<data.size();i++){
                newObj.data[i]=data[i]+obj.data[i];
        }

        for(;i<obj.data.size();i++){
            newObj.data.push_back(obj.data[i]);
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
        cout<< "Please type in your values to the tensor "<<endl;
        for(size_t i=0; i<tensor.data.size();i++){
            in >> tensor.data[i];
        }
        return in;
    }
};
#endif // RANKONETENSOR_H_  
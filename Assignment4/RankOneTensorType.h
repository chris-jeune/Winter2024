#ifndef RankOneTensorTypeTYPE_H_
#define RankOneTensorTypeTYPE_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>

class RankOneTensorTypeType: public BaseTensor{
private:
    vector<T> data;
public:
    RankOneTensorTypeType():data(0){}
    RankOneTensorTypeType(int size):data(size){}

    T& operator[](int index){
        return data[index];
    }

    const T& operator[](int index) const{
        return data[index];
    }

    void loadData() override{
        std::fill(data.begin(), data.end(), valueGen());
    }

    //prefix increment
    RankOneTensorType operator++(){
        for (int i = 0; i < data.size(); i++) {
            data[i]+=1;
        }
        return *this;
    }

    //postfix increment
    RankOneTensorType operator++(int){
        RankOneTensorType t=*this;
        for (int i = 0; i < data.size(); i++) {
            data[i]+=1;
        }
        return t;
    }

    //prefix decrement
    RankOneTensorType operator--(){
        for (int i = 0; i < data.size(); i++) {
            data[i]-=1;
        }
        return *this;
    }

    //postfix decrement
    RankOneTensorType operator--(int){
        RankOneTensorType t=*this;
        for (int i = 0; i < data.size(); i++) {
            data[i]-=1;
        }
        return t;
    }

    RankOneTensorType& operator=(const RankOneTensorType& obj){
       if(this!= &obj){
            // Perform the assignment operation
            data.resize(obj.data.size());
            for (int i = 0; i < obj.data.size(); i++) {
                data[i] = obj.data[i];
            }
        }
        return *this;
    }
    
    RankOneTensorType operator+(const RankOneTensorType& obj){
        if(data.size()>=obj.data.size()){
        RankOneTensorType newObj(data.size());
        int i=0;
            for (; i<obj.data.size();i++){
                newObj.data[i]=data[i]+obj.data[i];
            }
            for (;i<data.size();i++){
                newObj.data[i]=data[i];
            }
            return newObj;
        }

        RankOneTensorType newObj(obj.data.size());
        int i=0;
        for (; i<data.size();i++){
                newObj.data[i]=data[i]+obj.data[i];
        }

        for(;i<obj.data.size();i++){
            newObj.data.push_back(obj.data[i]);
        }
        return newObj;
    }

    friend std::ostream& operator<<(std::ostream& os, const RankOneTensorType& tensor){
        os<< "Data: [";
        for (size_t i=0; i<tensor.data.size(); i++){
            os<<tensor.data[i];
            if(i<tensor.data.size()-1)
                os<<", ";
        }
        os<<']'<<std::endl;
        return os;
    }


    friend std::istream& operator>>(std::istream& in, RankOneTensorType& tensor){
        cout<< "Please type in your values to the tensor "<<endl;
        for(size_t i=0; i<tensor.data.size();i++){
            in >> tensor.data[i];
        }
        return in;
    }
    //overloading operator [],+,++,>>,<<,==,!=
    //void insertData(T item)

};

#endif
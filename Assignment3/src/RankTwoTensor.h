#ifndef RANKTWOTENSOR_H_
#define RANKTWOTENSOR_H_

#include "BaseTensor.h"
#include <vector>
#include <iostream>

using namespace std;
class RankTwoTensor : public BaseTensor{
private:
    std::vector<std::vector<double>> data;
public:
    RankTwoTensor(int rows, int cols): data(rows, std::vector<double>(cols)){}

    void loadData() override{
        for (int i=0; i<data.size(); i++){
            for(int j=0; j<data[0].size();j++)
                 data[i][j]=valueGen();
        }

    }
    
    RankTwoTensor& operator=(const RankTwoTensor& obj){
        if(this!= &obj){
        data.resize(obj.data.size());
        for(int i=0;i<data.size();i++){
            data[i].resize(obj.data[i].size());
            for(int j=0;j<data[i].size();j++){
                data[i][j]=obj.data[i][j];
            }
        }
        
        }
        return *this;
    }

    //prefix
    RankTwoTensor operator++(){
        for(int i=0; i<data.size(); i++){
            for (int j=0; j<data[i].size(); j++){
                data[i][j]+=1;
            }
        }
        return *this;
    }

    //postfix
    RankTwoTensor operator++(int){
        RankTwoTensor t=*this;
        for(int i=0; i<data.size(); i++){
            for (int j=0; j<data[i].size(); j++){
                data[i][j]+=1;
            }
        }
        return t;
    }

    //prefix
    RankTwoTensor operator--(){
        for(int i=0; i<data.size(); i++){
            for (int j=0; j<data[i].size(); j++){
                data[i][j]-=1;
            }
        }
        return *this;
    }

    //postfix
    RankTwoTensor operator--(int){
        RankTwoTensor t=*this;
        for(int i=0; i<data.size(); i++){
            for (int j=0; j<data[i].size(); j++){
                data[i][j]-=1;
            }
        }
        return t;
    }

    RankTwoTensor operator+(const RankTwoTensor& obj){
        if(data.size()>=obj.data.size()){
            if(data[0].size()>=obj.data[0].size()){
                RankTwoTensor newObj(data.size(), data[0].size());
                int i=0;
                for(; i<obj.data.size();i++){
                    int j=0;
                    for(;j<obj.data[i].size();j++){
                        newObj.data[i][j]= data[i][j]+obj.data[i][j];
                    }
                    for(;j<data[i].size();j++){
                        newObj.data[i][j]= data[i][j];
                    }
                }
                for(; i<data.size();i++){
                    for(int j=0;j<data[i].size();j++){
                        newObj.data[i][j]= data[i][j];
                    }
                }
                return newObj;
            }
            else{
                RankTwoTensor newObj(data.size(), obj.data[0].size());
                int i=0;
                for(; i<obj.data.size();i++){
                    int j=0;
                    for(;j<data[i].size();j++){
                        newObj.data[i][j]= data[i][j]+obj.data[i][j];
                    }
                    for(;j<obj.data[i].size();j++){
                        newObj.data[i][j]= obj.data[i][j];
                    }
                }
                for(; i<data.size();i++){
                    for(int j=0;j<obj.data[i].size();j++){
                        newObj.data[i][j]= obj.data[i][j];
                    }
                }
                return newObj;
            }
        }
        else{
            if(data[0].size()>=obj.data[0].size()){
                RankTwoTensor newObj(obj.data.size(), data[0].size());
                int i=0;
                for(; i<data.size();i++){
                    int j=0;
                    for(;j<obj.data[i].size();j++){
                        newObj.data[i][j]= data[i][j]+obj.data[i][j];
                    }
                    for(;j<data[i].size();j++){
                        newObj.data[i][j]= data[i][j];
                    }
                }
                for(; i<obj.data.size();i++){
                    for(int j=0;j<data[i].size();j++){
                        newObj.data[i][j]= data[i][j];
                    }
                }
                return newObj;
            }
            else{
                RankTwoTensor newObj(obj.data.size(), obj.data[0].size());
                int i=0;
                for(; i<data.size();i++){
                    int j=0;
                    for(;j<data[i].size();j++){
                        newObj.data[i][j]= data[i][j]+obj.data[i][j];
                    }
                    for(;j<obj.data[i].size();j++){
                        newObj.data[i][j]= obj.data[i][j];
                    }
                }
                for(; i<obj.data.size();i++){
                    for(int j=0;j<obj.data[i].size();j++){
                        newObj.data[i][j]= obj.data[i][j];
                    }
                }
                return newObj;
            }
        }

    }
    
    friend std::ostream& operator<<(std::ostream& os, const RankTwoTensor& tensor){
        os<< "Data: "<<std::endl;
        for(int i=0; i<tensor.data.size(); i++){
            os<<"[";
            for(int j=0; j<tensor.data[i].size(); j++){
                os<<tensor.data[i][j];
                if(j<tensor.data[i].size()-1)
                    os<<", ";
            }
            os<<"]"<<std::endl;
        }
        return os;

    }

    friend std::istream& operator>>(std::istream& in, RankTwoTensor& tensor){
        cout<< "Please type in your values to the tensor "<<endl;
        for(int i=0; i<tensor.data.size(); i++){
            for(int j=0; j<tensor.data[i].size(); j++){
                in >>  tensor.data[i][j];
            }
        }
        return in;
    }

};
#endif // RANKONETENSOR_H_  
//Christian Jeune
//ID: 40279265

#ifndef BASETENSOR_H_
#define BASETENSOR_H_

#include <random>

class BaseTensor{

public: 

    virtual void loadData() = 0;

    double valueGen(){
        std::random_device rd;
        std::mt19937 mt(rd());

        std::uniform_real_distribution<double> dist(0.0, 1.0);

        double randomValue=dist(mt);
        return randomValue;

    }





};

#endif // BASETENSOR_H_

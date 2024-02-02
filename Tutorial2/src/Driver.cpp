#include "Point.h"
#include <iostream>
using namespace std;
int globalX=10;
int globalY=100;

void modifyPointByValue(Point point){
point.setX(globalX);
point.setY(globalY);
}

void modifyPointByReference(Point & point){
point.setX(globalX);
point.setY(globalY);
}

void modifyPointByAdress(Point * point){
point->setX(5);
point->setY(50);

}

int main(){
    Point point(1,2);
    Point *ptr=&point;
    cout<<"Point before any changes: ";
    cout<<"("<<point.getX()<<","<<point.getY()<<")"<<endl;
    cout<<"Modify by value: ";
    modifyPointByValue(point);
    cout<<"("<<point.getX()<<","<<point.getY()<<")"<<endl;
    cout<<"Modify by reference: ";
    modifyPointByReference(point);
    cout<<"("<<point.getX()<<","<<point.getY()<<")"<<endl;
    cout<<"Modify by address: ";
    modifyPointByAdress(ptr);
    cout<<"("<<point.getX()<<","<<point.getY()<<")"<<endl<<endl;
    return 0;
}
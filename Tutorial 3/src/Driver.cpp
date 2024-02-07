#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

void testAdd(){
    cout<<"Testing add function"<<endl;
    LinkedList list;
    cout<<"List after adding elements:"<<endl;
    list.add(1);
    list.add(-50);
    list.add(300);
    cout<<list.print()<<endl<<endl;
   
}

void testRemove(){
    cout<<"Testing remove function"<<endl;
    LinkedList list;
    list.add(1);
    list.add(-50);
    list.add(300);
    cout<<"Trying to remove element at index 4 in the list... ";
    list.remove(4);
    cout<<"Trying to remove element at index 0 in the list... ";
    list.remove(0);
    cout<<endl<<"Trying to remove element at index 1 in the list... ";
    list.remove(1);
    cout<<endl<<"List after removing:"<<endl;
    cout<<list.print()<<endl<<endl;
}

void testContains(){
    cout<<"Testing contains function"<<endl;
    LinkedList list;
    list.add(1);
    list.add(-50);
    list.add(300);
    cout<<"The list: "<<list.print()<<endl;
    
    cout<<"Contains integer 2? "<<((list.contains(2)==1)? "yes" : "no") <<endl; 
    cout<<"Contains integer 300? "<<((list.contains(300)==1)? "yes" : "no")<<endl;
    cout<<"Contains integer 5? "<<((list.contains(5)==1)? "yes" : "no")<<endl;
    cout<<"Contains integer -50? "<<((list.contains(-50)==1)? "yes" : "no")<<endl;   
    
}
int main(){
    testAdd();
    testRemove();
    testContains();
}
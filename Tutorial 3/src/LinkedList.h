#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"
#include <string>
using namespace std;

class LinkedList{
private:
    Node * head;
public:
    LinkedList();
    void add(int item);
    void remove(int item);
    bool contains(int item);
    string print();

};


#endif // LINKEDLIST_H_
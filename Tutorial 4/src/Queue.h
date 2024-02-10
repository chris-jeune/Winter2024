#ifndef QUEUE_H_
#define QUEUE_H_

#include "Node.h"
class Queue {
private:
Node * rear;
Node* front;
public:
    Queue();
    void enqueue(int item);
    void dequeue();
    int peek();
    bool isEmpty();
    bool contains(int item);
};


#endif

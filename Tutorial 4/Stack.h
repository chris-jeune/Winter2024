#ifndef STACK_H_
#define STACK_H_
#include "Node.h"
class Stack {
private:
Node *top;
public:
    Stack();
    void push(int item);
    void pop();
    int peek();
    bool isEmpty();
    bool contains(int item);
};

#endif

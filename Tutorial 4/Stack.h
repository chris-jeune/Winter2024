#ifndef STACK_H_
#define STACK_H_
class Stack {
public:
    Stack();
    void push(int item);
    void pop();
    int peek();
    bool isEmpty();
    bool contains(int item);
};

#endif

#ifndef QUEUE_H_
#define QUEUE_H_
class Queue {
public:
    Queue();
    void enqueue(int item);
    void dequeue();
    int peek();
    bool isEmpty();
    bool contains(int item);
};


#endif

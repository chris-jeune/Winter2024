#ifndef QUEUE_H_
#define QUEUE_H_
class Queue {
public:
    Queue();
    void enqueue(int item);
    void dequeue();
    int peek();
    bool isEmpty();
    boolean contains(int item);
};


#endif

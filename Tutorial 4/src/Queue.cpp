#include "Queue.h"
#include <iostream>
#include <limits.h>

Queue::Queue(){
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int item){
    Node *newNode = new Node(item);
    
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } 
    else{
        rear->next=newNode;
    }
    rear=newNode;
}

void Queue::dequeue(){
    if (isEmpty()) {
        return;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
}

int Queue::peek() {
    if (front == nullptr) {
        return INT_MAX+1;
    }
    return front->getValue();
}

bool Queue::isEmpty(){
    return rear == nullptr;
}

bool Queue::contains(int item){
    for (Node *temp = front; temp != nullptr; temp = temp->next) {
        if (temp->getValue() == item) {
            return true;
        }
    }
    return false;
}

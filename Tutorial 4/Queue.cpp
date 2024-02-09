#include "Queue.h"
#include <iostream>

Queue::Queue(){
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int item){
    Node *newNode = new Node(item);
    Node * temp=rear;
    if (isEmpty()) {
        front = newNode;
    } 
    rear = newNode;
    rear->next=temp;
}

void Queue::dequeue(){
    if (isEmpty()) {
        return;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) {
        rear = nullptr;
    }
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

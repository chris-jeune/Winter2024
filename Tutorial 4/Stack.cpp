#include "Stack.h"
#include <iostream>

Stack::Stack() {
    top = nullptr;
}

void Stack::push(int item) {
    Node *newNode = new Node(item);
    if (top == nullptr) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

void Stack::pop() {
    if (top == nullptr) {
        return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}

int Stack::peek() {
    if (top == nullptr) {
        // Handle the case where stack is empty
        throw std::logic_error("Stack is empty");
    }
    return top->getValue();
}

bool Stack::isEmpty() {
    return top == nullptr;
}

bool Stack::contains(int item) {
    for (Node *temp = top; temp != nullptr; temp = temp->next) {
        if (temp->getValue() == item) {
            return true;
        }
    }
    return false;
}

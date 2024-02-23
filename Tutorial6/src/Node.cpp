#include "Node.h"

Node::Node() {
    value = 0;
    left=right = nullptr;
}

Node::Node(int value) {
    this->value = value;
    left=right = nullptr;
}

int Node::getValue() {
    return value;
}
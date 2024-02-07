#include "Node.h"

Node::Node(){
    value=0;
    next=nullptr;
}

Node::Node(int value){
    this->value=value;
    this->next=nullptr;
}

int Node::getValue(){
    return value;
}


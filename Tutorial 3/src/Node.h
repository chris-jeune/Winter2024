#ifndef NODE_H_
#define NODE_H_

class Node{
private:
    int value;
public:
    Node* next;
    Node();
    Node(int);
    int getValue();
};

#endif // NODE_H_

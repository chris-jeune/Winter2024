#ifndef NODE_H_
#define NODE_H_

class Node {
private:
    int value;
public:
    Node *left, *right;
    Node();
    Node(int);
    int getValue();
};

#endif // NODE_H_
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
    void setValue(int value);
};

#endif // NODE_H_
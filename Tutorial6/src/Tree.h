#ifndef TREE_H_
#define TREE_H_

#include "Node.h"

class Tree {
private: 
	Node* root;
	void inorder(Node * & node);
	void preorder(Node*& node);
	void postorder(Node*& node);
    int findMin(Node*&node);
    int findMax(Node*&node);
    void remove(Node*&node, int value);

public:
	Tree();
	Tree(int value);
	void insert(int value);
	void inorder();
	void preorder();
	void postorder();
    int findMin();
    int findMax();
    void remove(int value);

};

#endif
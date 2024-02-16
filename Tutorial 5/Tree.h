#ifndef TREE_H_
#define TREE_H_

#include "Node.h"

class Tree {
private: 
	Node* root;
	void inorder(Node * & node);
	void preorder(Node*& node);
	void postorder(Node*& node);

public:
	Tree();
	Tree(int value);
	void insert(int value);
	void inorder();
	void preorder();
	void postorder();

};

#endif
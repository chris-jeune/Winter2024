#ifndef TREE_H_
#define TREE_H_

#include "Node.h"
#include <vector>

class Tree {
private: 
	Node* root;
	void inorder(Node * & node);
	void preorder(Node*& node);
	void postorder(Node*& node);
    int findMin(Node*&node);
    int findMax(Node*&node);
    Node* remove(Node*&node, int value);
	void dfs(Node* node, std::vector<Node*>& nodes);
	void bfs(std::vector<Node*>& currentLevel, std::vector<Node*>& nodes);

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
	std::vector<Node*> bfs();
	std::vector<Node*> dfs();

};

#endif
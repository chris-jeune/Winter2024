#include "Tree.h"
#include <iostream>

using namespace std;

Tree::Tree() {
	root = nullptr;
}

Tree::Tree(int value) {
	root = new Node(value);
}

void Tree::insert(int value) {
	if (root == nullptr) {
		root = new Node(value);
		return; 
	}

	Node* temp = root;
	while (true) {
		if (value < temp->getValue()) {
			if (temp->left == nullptr) {
				temp->left = new Node(value);
				return; 
			}
			temp = temp->left;
		}
		else {
			if (temp->right == nullptr) {
				temp->right = new Node(value);
				return;
			}
			temp = temp->right;
		}
	}

}

void Tree::inorder(Node*& node) {
	if (node == nullptr)
		return;

	inorder(node->left);

	cout << node->getValue() << " ";

	inorder(node->right);

}

void Tree::inorder() {
	inorder(root);
}

void Tree::preorder(Node*& node) {
	if (node == nullptr)
		return;
	
	cout << node->getValue() << " ";
	
	preorder(node->left);

	preorder(node->right);
}

void Tree::preorder() {
	preorder(root);
}

void Tree::postorder(Node*& node) {
	if (node == nullptr)
		return;
	postorder(node->left);
	postorder(node->right);
	cout << node->getValue() << " ";
}

void Tree::postorder() {
	postorder(root);
}

int Tree::findMin(Node * & node){
	if (node==nullptr)
	return -1;
	else if(node->left==nullptr)
		return node->getValue();
	else 
		return findMin(node->left);
}

int Tree::findMin(){
	return findMin(root);
}

int Tree::findMax(Node *& node){
	if (node==nullptr)
	return -1;
	else if(node->right==nullptr)
		return node->getValue();
	else 
		return findMax(node->right);
}

int Tree::findMax() {
	return findMax(root);
}

Node* Tree::remove(Node *& node, int value){
	if (node == nullptr)
		return node;
	if (node->getValue() > value)
		node->left=remove(node->left, value);
	else if (node->getValue() < value)
		node->right=remove(node->right, value);

	else {
		if (node->right == nullptr) {
			return node->left;
		}
		else if (node->left == nullptr) {
			return node->right;
		}

		else {
			int min=findMin(node->right);
			node-> right= remove(node->right, min);
			node->setValue(min);
		}
		
	}
	return node;
	
}

void Tree::remove(int value){
	root = remove(root, value);
}

void Tree::dfs(Node* node, std::vector<Node*>& nodes) {
	if (node == nullptr)
		return;
		
	nodes.push_back(node);
	dfs(node->left, nodes);
	dfs(node->right, nodes);
}

std::vector<Node*> Tree::dfs() {
	std::vector<Node*> nodes;
	dfs(root, nodes);
	return nodes;
}

void Tree::bfs(std::vector<Node*>& currentLevel, std::vector<Node*>& nodes) {
	if(currentLevel.empty())
		return;

	std::vector<Node*> nextLevel;
	for (auto node:currentLevel){
		nodes.push_back(node);
		if (node->left != nullptr) 
			nextLevel.push_back(node->left);
		if(node->right!=nullptr)
			nextLevel.push_back(node->right);
	}

	bfs(nextLevel, nodes);

}

std::vector<Node*> Tree::bfs() {
	std::vector<Node*> final;
	if(root==nullptr)
		return final;
	
	vector<Node*> currentLevel;
	currentLevel.push_back(root);

	bfs(currentLevel, final);
	return final;
}

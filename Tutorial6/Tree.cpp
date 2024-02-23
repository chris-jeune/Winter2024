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
	findMin(root);
}

int Tree::findMax(Node *& node){
	if (node==nullptr)
	return -1;
	else if(node->right==nullptr)
		return node->getValue();
	else 
		return findMax(node->right);
}

void Tree::remove(Node *& node, int value){
	if (root==nullptr)
		return;
	else if(node->getValue()==value)
		return;
	remove(node->left, value);
	remove(node->right, value);
}

void Tree::remove(int value){
	remove(root, value);
}
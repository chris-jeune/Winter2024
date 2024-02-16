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

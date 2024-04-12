#include "Node.h"
#include <iostream>
#include <climits>
using namespace std;

// Static variable to assign unique IDs to nodes
static int staticID = 0;

// Default constructor for the Node class
Node::Node() {
    // Increment the static ID and assign it to the node
    id = ++staticID;
    // Set data to the maximum possible integer value
    data = INT_MAX;
}

// Parameterized constructor for the Node class with data initialization
Node::Node(int data) {
    // Set the provided data and increment the static ID for the node
    this->data = data;
    id = ++staticID;
}

// Getter function to retrieve the data of the node
int Node::GetData() const {
    return data;
}

// Setter function to set the data of the node
void Node::SetData(int data) {
    this->data = data;
}

// Getter function to retrieve the ID of the node
int Node::GetId() const {
    return id;
}

// Setter function to set the ID of the node with additional validation
void Node::SetId(int id) {
    // Check if the provided ID is greater than the current ID
    if (id > (this->id)) {
        // Set the ID of the node and update the staticID
        this->id = id;
        staticID = id;
    } else {
        // Inform that the ID cannot be changed
        cout << "No change because ID has already been assigned to another node." << endl;
    }
}

// Method to create a clone of the node
Node Node::clone() {
    // Create a new node and set its data to match the current node
    Node node;
    node.SetData(this->data);
    return node;
}

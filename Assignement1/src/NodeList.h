#ifndef NODELIST_H_
#define NODELIST_H_

#include "Node.h"       
#include <array>        

class NodeList {
private:
    static const size_t LIST_SIZE = 500;  // The maximum items in the list
    Node *items;                          // Pointer to a dynamically allocated array of Nodes
    size_t numItems;                      // The number of items currently in the list

public:
    // Default constructor for the NodeList class
    NodeList();

    // Parameterized constructor for the NodeList class with initial items
    NodeList(size_t numItems, Node* items);

    // Copy constructor for the NodeList class
    NodeList(const NodeList&);

    // Destructor for the NodeList class
    ~NodeList();

    // Display the contents of the NodeList
    void display();

    // Find the index of a specific element in the NodeList
    int finder(int elem, bool type);

    // Getter function to retrieve the pointer to items array
    Node* getItems();

    // Getter function to retrieve the number of items in the list
    size_t getNumItems();

    // Add a node to the NodeList
    void addNode(const Node& a);

    // Remove a node from the NodeList based on its ID
    void removeNode(int ID);
};

#endif // NODELIST_H_

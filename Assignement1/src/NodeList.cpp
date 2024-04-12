#include "NodeList.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


// Function to compare Nodes based on their data
int compareData(const void * a, const void * b){
    return ((*(Node*)a).GetData() - (*(Node*)b).GetData());
}

// Function to compare Nodes based on their ID
int compareID(const void * a, const void * b){
    return ((*(Node*)a).GetId() - (*(Node*)b).GetId());
}

// Binary search function for finding a Node in the NodeList
// @param type is 0 when the search is based on the data of Node and 1 for the ID
int binarySearch(Node array[], int low, int high, int elem, bool type){
    switch(type){
    //Binary search element based on its Data
    case 0:
        if(high >= low){
            int mid = (low + high) / 2;

            if(array[mid].GetData() == elem)
                return mid;

            if(array[mid].GetData() > elem)
                return binarySearch(array, low, mid - 1, elem, type);

            return binarySearch(array, mid + 1, high, elem, type);
        }

        return -1;
    // Binary search element based on its ID
    case 1:
        if(high >= low){
            int mid = (low + high) / 2;

            if(array[mid].GetId() == elem)
                return mid;

            if(array[mid].GetId() > elem)
                return binarySearch(array, low, mid - 1, elem, type);

            return binarySearch(array, mid + 1, high, elem, type);
        }

        return -1;

    default:
        return -1;
    }
}

// Default constructor for the NodeList class
NodeList::NodeList(){
    numItems = 0;
}

// Parameterized constructor for the NodeList class with initial items
NodeList::NodeList(size_t numItems, Node* newItems){
    // checks if numItems is smaller than the max and assigns
    if (numItems <= LIST_SIZE){
        this->numItems = numItems;
        //initialize items
        items = new Node[LIST_SIZE];
        for (size_t i = 0; i < numItems; i++)
            (this->items)[i] = newItems[i];
    }
}

// Copy constructor for the NodeList class
NodeList::NodeList(const NodeList& clone){
    // initializes or reset items
    items = new Node[LIST_SIZE];
    numItems = clone.numItems;
    // copying each value using clone function
    for(size_t i = 0; i < numItems; i++)
        items[i] = clone.items[i].clone();
}

// Destructor for the NodeList class
NodeList::~NodeList(){
    // checks wheter or not items have been initialized
    if(numItems > 0){
        delete[] items;
        cout << "NodeList destructor called..." << endl;
    }
    else
        cout << "NodeList destructor called, but list was not initialized..." << endl;
}

// Display the contents of the NodeList
void NodeList::display(){
    for(size_t i = 0; i < numItems; i++){
        cout << "ID: " << items[i].GetId() << ", data: " << items[i].GetData() << endl;
    }
}

// Finder function to search for an element in the NodeList
// @param type is 0 when the search is based on the data of Nodes and 1 for the ID
int NodeList::finder(int elem, bool type){
    // Sort the array based on specified comparison type
    if(type)
        qsort(items, numItems, sizeof(Node), compareID);
    else
        qsort(items, numItems, sizeof(Node), compareData);

    // Perform binary search and return the index of the element
    return binarySearch(items, 0, numItems - 1, elem, type);
}

// Getter function to retrieve the pointer to items array
Node* NodeList::getItems(){
    return items;
}

// Getter function to retrieve the number of items in the list
size_t NodeList::getNumItems(){
    return numItems;
}

// Add a node to the NodeList
void NodeList::addNode(const Node & a){
    // If the list is not initialized, allocate memory for it
    if(numItems == 0){
        items = new Node[LIST_SIZE];
    }

    // If there is space, add the node to the list
    if (numItems < LIST_SIZE){
        items[numItems] = a;
        numItems++;
    }
    else
        cout << "Node " << a.GetId() << " cannot be added - maximum number of nodes reached" << endl;
}

// Remove a node from the NodeList based on its ID
void NodeList::removeNode(int ID){
    // Check if the list is not initialized
    if(numItems == 0){
        cout << "No item can be removed - list has not been initialized" << endl;
        return;
    }

    // Find the index of the node with the specified ID
    int index = finder(ID, true);

    // If the index is valid, shift elements to remove the node
    if(index >= 0){
        for(size_t j = index; j < numItems - 1; j++){
            items[j] = items[j + 1];
        }
        numItems--;
    }
    else
        cout << "Specified index is out of range" << endl;
}

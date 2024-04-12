#include "Node.h"
#include "NodeList.h"
#include <iostream>
#include <stdlib.h> 

using namespace std;

// Function to compare Nodes based on their data
int compareData(const void *a, const void *b);

// Function to compare Nodes based on their ID
int compareID(const void *a, const void *b);

// Test function for comparing data
void testCompareData();

// Test function for comparing IDs
void testCompareID();

// Test function for binary search on NodeList
void testNodeFinder();

// Test function for NodeList creation
void testNodeListCreation();

// Test function for NodeList copy constructor
void testCopy();

// Test function for NodeList destructor
void testDestructor();

// Test function for NodeList getters
void testGetters();

// Test function for adding nodes to NodeList
void testAddingNode();

// Test function for removing nodes from NodeList
void testRemovingNode();

// Test function for Node creation
void testingNodeCreation();

// Test function for Node cloning
void testClone();

int main() {
    // Uncomment the specific test function you want to run
    // testCompareData();
    // testCompareID();
    // testNodeFinder();
    // testNodeListCreation();
    // testCopy();
    // testDestructor();
    // testGetters();
    // testAddingNode();
    // testRemovingNode();
    // testingNodeCreation();
    testClone();

    return 0;
}

// Test function for comparing data
void testCompareData() {
    // Creating an array of Nodes
    Node list[6] = {Node(40), Node(33), Node(10), Node(27), Node(43), Node(5)};
    NodeList list1(6, list);

    // Displaying the array before sorting
    cout << "Array before the qsort function uses compare data: " << endl;
    list1.display();
    cout << endl;

    // Sorting the array based on data using qsort
    qsort(list1.getItems(), 6, sizeof(Node), compareData);

    // Displaying the array after sorting
    cout << "Array after the qsort function uses compare data: " << endl;
    list1.display();
    cout << endl;
}

// Test function for comparing IDs
void testCompareID() {
    // Creating an array of Nodes with specific order
    Node node1(40), node2(33), node3(10), node4(27), node5(43), node6(5);
    Node list[6] = {node6, node3, node1, node4, node2, node5};
    NodeList list1(6, list);

    // Displaying the array before sorting
    cout << "Array before the qsort function uses compare id: " << endl;
    list1.display();
    cout << endl;

    // Sorting the array based on IDs using qsort
    qsort(list1.getItems(), 6, sizeof(Node), compareID);

    // Displaying the array after sorting
    cout << "Array after the qsort function uses compare id: " << endl;
    list1.display();
    cout << endl;
}

// Test function for binary search on NodeList
void testNodeFinder() {
    // Creating an array of Nodes
    Node list[6] = {Node(40), Node(33), Node(10), Node(27), Node(43), Node(5)};
    NodeList list1(6, list);

    // Displaying the unsorted list
    cout << "Testing binary search using data." << endl << "Unsorted list:" << endl;
    list1.display();

    // Searching for a specific number using binary search based on data
    cout << "Searching for number 33..." << endl;
    int index = list1.finder(33, 0);

    // Displaying the result of the search
    cout << "The number is at index " << index << " in the list sorted by data, which is the " << (index + 1) << " element." << endl;
    list1.display();

    // Displaying the unsorted list
    cout << "Testing binary search using ID." << endl << "Unsorted list:" << endl;
    list1.display();

    // Searching for a specific ID using binary search based on ID
    cout << "Searching for ID 2..." << endl;
    index = list1.finder(2, 1);

    // Displaying the result of the search
    cout << "The number is at index " << index << " on the sorted list, which is the " << (index + 1) << " element." << endl;
    list1.display();
}

// Test function for NodeList creation
void testNodeListCreation() {
    // Testing default constructor
    cout << "Testing for default constructor." << endl;
    NodeList list;
    cout << "numItems: " << list.getNumItems() << endl;
    cout << "List: " << endl;
    list.display();

    // Testing parameterized constructor
    cout << "\nTesting parameterized constructor." << endl;
    Node list1[6] = {Node(40), Node(33), Node(10), Node(27), Node(43), Node(5)};
    NodeList list2(6, list1);
    cout << "numItems: " << list2.getNumItems() << endl;
    cout << "List: " << endl;
    list2.display();
}

// Test function for NodeList copy constructor
void testCopy() {
    // Creating an array of Nodes
    Node list[6] = {Node(40), Node(33), Node(10), Node(27), Node(43), Node(5)};
    NodeList list1(6, list);

    // Displaying the original list
    cout << "Original: " << endl;
    list1.display();

    // Creating a copy using the copy constructor
    cout << "Copy: " << endl;
    NodeList list2 = list1;
    list2.display();
}

// Test function for NodeList destructor
void testDestructor() {
    // Creating an array of Nodes
    Node list[6] = {Node(40), Node(33), Node(10), Node(27), Node(43), Node(5)};
    NodeList list1(6, list);

    // Displaying a message when the destructor is called
    cout << "Testing destructor for parameterized NodeList" << endl<<"List:"<<endl;
    list1.display();

    // Uncomment this code and comment previous code to test for empty NodeList
    // NodeList list2;
    // cout << "Testing destructor for default NodeList" << endl<<"List: "<<endl;
    // list2.display();
}

// Test function for NodeList getters
void testGetters() {
    // Creating an array of Nodes
    Node list[6] = {Node(40), Node(33), Node(10), Node(27), Node(43), Node(5)};
    NodeList list1(6, list);

    // Testing the getter for numItems
    cout << "Testing getter for numItem :" << list1.getNumItems() << endl;

    // Testing the getter for items
    cout << "Testing getter for items: " << endl << "List: " << endl;
    for (int i = 0; i < 6; i++) {
        cout << list1.getItems()[i].GetData() << endl;
    }
}

// Test function for adding nodes to NodeList
void testAddingNode() {
    // Testing adding a node to an empty list
    NodeList list1;
    cout << "Testing adding node to empty list: " << endl;
    cout << "Number of items before: " << list1.getNumItems() << endl;
    list1.addNode(Node(40));
    cout << "Number of items after: " << list1.getNumItems() << endl;
    cout << "New list: " << endl;
    list1.display();

    // Testing adding another node to the same list
    cout << "\nTesting adding another node to the same list: " << endl;
    list1.addNode(Node(33));
    cout << "Number of items after: " << list1.getNumItems() << endl;
    cout << "New list: " << endl;
    list1.display();

    // Testing adding a node to a list that has reached max size
    cout << "\nTesting adding node to list which has reached max size" << endl;
    for (int i = 0; i < 499; i++) {
        list1.addNode(Node(i));
    }
}

// Test function for removing nodes from NodeList
void testRemovingNode() {
    // Testing removing a node from an empty list
    NodeList list;
    cout << "Testing removing node from empty list." << endl << "Removing item with ID 50..." << endl;
    list.removeNode(50);

    // Testing removing a node from a non-empty list using an ID that is out of range
    cout << "\nTesting removing node from non-empty list using an ID that is out of range" << endl;
    list.addNode(Node(5));
    cout << "List: " << endl;
    list.display();
    cout << "Removing item with ID 50..." << endl;
    list.removeNode(50);

    // Testing removing a node from a non-empty list using a correct ID
    cout << "\nTesting removing node from non-empty list using a correct ID" << endl;
    for (int i = 0; i < 6; i++) {
        list.addNode(Node(i));
    }
    cout << "Number of items before: " << list.getNumItems() << endl << "List before:" << endl;
    list.display();
    cout << "Removing item with ID 502" << endl;
    list.removeNode(502);
    cout << "Number of items after: " << list.getNumItems() << endl << "List after:" << endl;
    list.display();
}

// Test function for Node creation
void testingNodeCreation() {
    // Testing the default Node constructor
    Node node;
    cout << "Default node." << endl;
    cout << "Identity: " << node.GetId() << endl;
    cout << "Data: " << node.GetData() << endl;

    // Modifying the initial node and displaying the changes
    node.SetData(98);//changing data
    cout << "\nChanging initial node using set functions..." << endl;
    node.SetId(1);// trying to set ID to the same
    cout<< "Trying again..."<<endl;
    node.SetId(5);
    cout << "Identity: " << node.GetId() << endl;
    cout << "Data: " << node.GetData() << endl;

    // Creating a new node and displaying its properties
    Node another(60);
    cout << "\nCreating new node...\nNew node." << endl;
    cout << "Identity: " << another.GetId() << endl;
    cout << "Data: " << another.GetData() << endl;
}

// Test function for Node cloning
void testClone() {
    // Creating an original Node
    Node node(98);
    cout << "Original object." << endl;
    cout << "Identity: " << node.GetId() << endl;
    cout << "Data: " << node.GetData() << endl;

    // Cloning the original Node and displaying the clone
    Node clone = node.clone();
    cout << "\nCloned object from original" << endl;
    cout << "Identity: " << clone.GetId() << endl;
    cout << "Data: " << clone.GetData() << endl;
}

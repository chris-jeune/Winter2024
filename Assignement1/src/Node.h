#ifndef NODE_H_
#define NODE_H_

// Definition of the Node class
class Node {
private:
    int id;   // Identifier for the node
    int data; // Data associated with the node

public:
    // Default constructor
    Node();

    // Parameterized constructor with data initialization
    Node(int data);

    // Method to create a clone of the node
    Node clone();

    // Getter function to retrieve the id of the node
    int GetId() const;

    // Setter function to set the id of the node
    void SetId(int identity);

    // Getter function to retrieve the data of the node
    int GetData() const;

    // Setter function to set the data of the node
    void SetData(int data);
};

#endif // NODE_H_

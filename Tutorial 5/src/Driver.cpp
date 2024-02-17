#include "Tree.h"
#include <iostream>

using namespace std;

void testTreeCreationInsertInorder() {
    Tree tree1;
    cout << "Testing tree Default constructor" << endl;

    Tree tree2(5);

    cout << "Testing tree Parameterized constructor" << endl;

    cout<< "Testing tree insert in each trees" << endl;

    tree2.insert(3);
    tree2.insert(7);
    tree2.insert(2);
    tree2.insert(4);
    tree2.insert(6);
    tree2.insert(8);

    tree1.insert(3);
    tree1.insert(7);
    tree1.insert(2);
    tree1.insert(4);
    tree1.insert(6);
    tree1.insert(8);

    // Test de la fonction inorder()
    cout << "Testing inorder() in each trees :\nTree1 : ";
    tree2.inorder();
    cout << endl<<"Tree2 : ";
    tree1.inorder();
    cout << endl;
}

void testPreorder(){
     Tree tree2(5);

    tree2.insert(3);
    tree2.insert(7);
    tree2.insert(2);
    tree2.insert(4);
    tree2.insert(6);
    tree2.insert(8);

    cout << "Testing preorder()\n";
    tree2.preorder();
    cout << endl;
}

void testPostorder(){
     Tree tree2(5);

    tree2.insert(3);
    tree2.insert(7);
    tree2.insert(2);
    tree2.insert(4);
    tree2.insert(6);
    tree2.insert(8);

    cout << "Testing postorder()\n";
    tree2.postorder();
    cout << endl;
}



int main() {
    testTreeCreationInsertInorder();
    cout<<endl;
    testPreorder();
    cout<<endl;
    testPostorder();
    return 0;
}

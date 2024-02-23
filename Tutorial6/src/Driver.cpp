#include "Tree.h"
#include "Node.h"
#include <iostream>

using namespace std;

void testFindMin(){
    Tree tree(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(14);
    tree.insert(13);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    cout<<"Test find min function"<<endl;
    tree.inorder();
    cout<<"The min is "<<tree.findMin()<<endl;
}

void testFindMax(){
    Tree tree(8);
    tree.insert(3);
    tree.insert(10);;
    tree.insert(1);
    tree.insert(14);
    tree.insert(13);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    cout<<"Test find max function"<<endl;
    tree.inorder();
    cout<<"The max is "<<tree.findMax()<<endl;
}

void testRemove(){
    Tree tree(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(14);
    tree.insert(13);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    cout<<"Test find remove function"<<endl;
    tree.inorder();
    cout<<"Removing 10"<<endl;
    tree.remove(10);
    tree.inorder();
}


int main(){
    testFindMin();
    // testFindMax();
    // testRemove();
    return 0;
}
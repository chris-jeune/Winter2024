#include "Tree.h"
#include "Node.h"
#include <vector>
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
    cout<<"\nThe min is "<<tree.findMin()<<endl;
}

void testFindMax(){
    Tree tree(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(14);
    tree.insert(13);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    cout<<"Test find max function"<<endl;
    tree.inorder();
    cout<<"\nThe max is "<<tree.findMax()<<endl;
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
    cout << "\nRemoving 8" << endl;
    tree.remove(8);
    tree.inorder();
}

void testSearch(){
Tree t1;
t1.insert(10);
t1.insert(5);
t1.insert(20);
t1.insert(4);
t1.insert(8);
t1.insert(15);
t1.insert(48);
t1.insert(1);
t1.insert(9);
t1.insert(16);

cout<<endl<<"Testing breadth-first search"<<endl;
for (auto node: t1.bfs()){
    cout<< node->getValue()<<" ";
}

cout<<endl<<"Testing depth-first search"<<endl;
for (auto node: t1.dfs()){
    cout<< node->getValue()<<" ";
}
t1.remove(10);
cout<<endl << "Testing breadth-first search after removing" << endl;
for (auto node: t1.bfs()){
    cout<< node->getValue()<<" ";
}

cout<<endl<<"Testing depth-first search after removing"<<endl;
for (auto node: t1.dfs()){
    cout<< node->getValue()<<" ";
}

}


int main(){
    // testFindMin();
    // testFindMax();
    //testRemove();
    testSearch();
    return 0;
}

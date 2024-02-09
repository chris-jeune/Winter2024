#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head=nullptr;
}

void LinkedList::add(int item){

    Node* newNode = new Node(item);

    if(head==nullptr){
        head= newNode;
        return;
    }

    Node*temp=head;

    for(; temp->next!=nullptr; temp=temp->next);

    temp->next= newNode;

}


void LinkedList::remove(int item){
int length=0;
Node*temp=head;
for(; temp!=nullptr; temp=temp->next){
    length++;
}

if(item>length){
    cout<<"Out of range"<<endl;
    return;
}
temp=head;
Node*temp1=nullptr;

if(item==0){
    head=head->next;
    delete temp;
    return;
}

for(;item-->0; temp1=temp, temp=temp->next);

temp1->next=temp->next;

delete temp;

}

bool LinkedList::contains(int item){
    for(Node*temp=head; temp!=nullptr; temp=temp->next){
        if(temp->getValue()==item)
        return true;
    }

    return false;

}

string LinkedList::print(){
    string list="";
    Node*temp=head;
    for(; temp->next!=nullptr; temp=temp->next){
        list+=(to_string(temp->getValue()))+", ";
    }
    list+=(to_string(temp->getValue()));


    return list;
}

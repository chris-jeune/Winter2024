#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>

using namespace std;

void testPush(){
Stack stack;
cout<<"Testing is empty function: "<< ((stack.isEmpty())?"is empty":"is not empty")<<endl;
cout<<"Testing push function in stack"<<endl;
cout<<"Value of top when stack is empty: "<<stack.peek()<<endl;
cout<<"Adding number 60..."<<endl;
stack.push(60);
cout<<"Value of the top Node: "<<stack.peek()<<endl;
cout<<"Adding number 45..."<<endl;
stack.push(45);
cout<<"Value of the top Node: "<<stack.peek()<<endl;
cout<<"Testing is empty function: "<< ((stack.isEmpty())?"is empty":"is not empty")<<endl;

}

void testPop(){
Stack stack;
stack.push(60);
stack.push(45);
cout<<"Testing pop function. Number 45 followed by number 60 were pushed into the stack"<<endl;
cout<<"Top initially: "<<stack.peek()<<endl;
stack.pop();
cout<<"Top after popping: "<< stack.peek()<<endl;
stack.pop();
cout<<"Popping a second time: "<< stack.peek()<<endl;

}

void testStackContains(){
Stack stack;
stack.push(60);
stack.push(45);
cout<<"Testing contains function. Number 45 followed by number 60 were pushed into the stack"<<endl;
cout<<"Does the stack contains number 60? "<<((stack.contains(60)?"yes":"no"))<<endl;
cout<<"Does the stack contains number 45? "<<((stack.contains(45)?"yes":"no"))<<endl;
cout<<"Does the stack contains number 50? "<<((stack.contains(50)?"yes":"no"))<<endl;
}

void testEnqueue(){
Queue stack;
cout<<"Testing is empty function: "<< ((stack.isEmpty())?"is empty":"is not empty")<<endl;
cout<<"Testing enqueue function in queue"<<endl;
cout<<"Value of front when queue is empty: "<<stack.peek()<<endl;
cout<<"Adding number 60..."<<endl;
stack.enqueue(60);
cout<<"Value of the front Node: "<<stack.peek()<<endl;
cout<<"Adding number 45..."<<endl;
stack.enqueue(45);
cout<<"Value of the front Node: "<<stack.peek()<<endl;
cout<<"Testing is empty function: "<< ((stack.isEmpty())?"is empty":"is not empty")<<endl;

}

void testDequeue(){
Queue stack;
stack.enqueue(60);
stack.enqueue(45);
cout<<"Testing dequeue function. Number 45 followed by number 60 were enqueued into the queue"<<endl;
cout<<"Front initially: "<<stack.peek()<<endl;
stack.dequeue();
cout<<"Front after dequeue: "<< stack.peek()<<endl;
stack.dequeue();
cout<<"Dequeue a second time: "<< stack.peek()<<endl;

}

void testQueueContains(){
Queue stack;
stack.enqueue(60);
stack.enqueue(45);
cout<<"Testing contains function. Number 45 followed by number 60 were pushed into the stack"<<endl;
cout<<"Does the queue contains number 60? "<<((stack.contains(60)?"yes":"no"))<<endl;
cout<<"Does the queue contains number 45? "<<((stack.contains(45)?"yes":"no"))<<endl;
cout<<"Does the queue contains number 50? "<<((stack.contains(50)?"yes":"no"))<<endl;
}

int main(){
    testEnqueue();
    testDequeue();
    testQueueContains();
    testPush();
    testPop();
    testStackContains();
    return 0;
}


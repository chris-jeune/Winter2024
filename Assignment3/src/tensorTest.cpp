#include "RankOneTensor.h"
#include <iostream>
#include <fstream>

using namespace std;

void testTensorStreamOperator(){
   	RankOneTensor t1(3);
	t1.loadData();

	cout << t1 << endl;

	RankOneTensor t2(3);
	t2.loadData();
	cout << t2 <<endl;


	cout<< t1+t2<< endl<< "Hello Coen244";

}

void testAssignment(){
	RankOneTensor t1(3);
	t1.loadData();

	cout << t1 << endl;

	RankOneTensor t2(3);
	t2.loadData();
	cout << t2 <<endl;

	RankOneTensor t3=t2;
	cout<<t3<<endl;

	t3=t1;
	cout<<t3<<endl;

}

void testFileStreamUsingOperator(){
	ofstream outFile("rank1tensor.txt");
	if(!outFile.is_open()){
		cerr<<"Error opening file!"<<endl;
		exit(1);
	}
	RankOneTensor t(2);
	t.loadData();

	cout<<t<<endl;
	outFile<<t<<endl;

	outFile.close();
	cout<<"Data written to rank1tensor.txt"<<endl;
}

void testInput(){
	RankOneTensor t1(3);
	cin>>t1;
	cout<< t1;
}

void testIncrementDecrement(){
	RankOneTensor t1(3);
	t1.loadData();
	cout<< t1;

	cout<<t1++;

	cout<<++t1;

	cout<<t1--;

	cout<< --t1;
}

int main(){
    //testTensorStreamOperator();
	//testAssignment();
	//testFileStreamUsingOperator();
	// testInput();
	testIncrementDecrement();
    return 0;
}
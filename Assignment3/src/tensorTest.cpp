#include "RankOneTensor.h"
#include "RankTwoTensor.h"
#include <iostream>
#include <fstream>

using namespace std;

void testOutputStreamOperator(){
   	RankOneTensor t1(3);
	RankTwoTensor t3(3,2);
	t1.loadData();
	t3.loadData();

	cout << t1 << endl;
	cout<< t3<< endl;

	RankOneTensor t2(3);
	RankTwoTensor t4(3,2);
	t2.loadData();
	t4.loadData();
	cout << t2 <<endl;
	cout<< t4<<endl;

	cout<<"Testing operator+ overloading"<<endl;
	cout<< t1+t2<< "Hello Coen244"<<endl;
	cout<< t3+t4<< "Hello Coen244"<<endl;

}

void testAssignment(){
	RankOneTensor t1(3);
	t1.loadData();

	cout << t1 << endl;

	RankOneTensor t3(2);
	t3.loadData();
	cout<<t3<<endl;

	t3=t1;
	cout<<t3<<endl;

	RankTwoTensor t4(3,2);
	t4.loadData();

	cout<<t4<<endl;

	RankTwoTensor t5(2,3);
	t5.loadData();
	cout<<t5<<endl;

	t5=t4;
	cout<<t5<<endl;
	
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
    // testOutputStreamOperator();
	testAssignment();
	// testFileStreamUsingOperator();
	// testInput();
	// testIncrementDecrement();
    return 0;
}
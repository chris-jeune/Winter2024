#include "BaseTensor.h"
#include "RankOneTensor.h"
#include "RankTwoTensor.h"
#include <iostream>
#include <fstream>

using namespace std;

void testOutputStreamOperator()
{
	RankOneTensor t1(3);
	RankTwoTensor t3(3, 2);
	t1.loadData();
	t3.loadData();

	cout << t1 << endl;
	cout << t3 << endl;

	RankOneTensor t2(3);
	RankTwoTensor t4(3, 2);
	t2.loadData();
	t4.loadData();
	cout << t2 << endl;
	cout << t4 << endl;

	cout << "Testing operator+ overloading" << endl;
	cout << t1 + t2 << "Hello Coen244" << endl;
	cout << t3 + t4 << "Hello Coen244" << endl;
}

void testAssignment()
{
	RankOneTensor t1(3);
	t1.loadData();

	cout << t1 << endl;

	RankOneTensor t3(2);
	t3.loadData();
	cout << t3 << endl;

	t3 = t1;
	cout << t3 << endl;

	RankTwoTensor t4(3, 2);
	t4.loadData();

	cout << t4 << endl;

	RankTwoTensor t5(2, 3);
	t5.loadData();
	cout << t5 << endl;

	t5 = t4;
	cout << t5 << endl;
}

void testFileStreamUsingOperator()
{
	ofstream outFile("rank1tensor.txt");
	ofstream outFile2("rank2tensor.txt");
	if (!outFile.is_open())
	{
		cerr << "Error opening first file!" << endl;
		exit(1);
	}

	if (!outFile2.is_open())
	{
		cerr << "Error opening second file!" << endl;
		exit(1);
	}

	RankOneTensor t(2);
	t.loadData();
	
	RankTwoTensor t2(3, 2);
	t2.loadData();

	cout << t << endl;
	cout << t2 << endl;
	outFile << t << endl;
	outFile2 << t2 << endl;

	outFile.close();
	outFile2.close();
	cout << "Data written to rank1tensor.txt and rank2tensor.txt" << endl;
}

void testInput()
{
	RankOneTensor t1(3);
	cin >> t1;
	cout << t1;
	cout << endl;
	RankTwoTensor t2(3, 2);
	cin >> t2;
	cout << t2;
}

void testIncrementDecrement()
{
	RankOneTensor t1(3);
	RankTwoTensor t2(3, 2);
	t1.loadData();
	t2.loadData();
	cout << "Initial values:" << endl;
	cout << t1;
	cout << t2;

	cout << "\nPost increment" << endl;
	cout << t1++;
	cout << t2++;

	cout << "\nPre increment" << endl;
	cout << ++t1;
	cout << ++t2;

	cout << "\nPost decrement" << endl;
	cout << t1--;
	cout << t2--;

	cout << "\nPre decrement" << endl;
	cout << --t1;
	cout << --t2;
}

void testPlusOperator()
{
	cout << "Testing operator+ overloading" << endl;
	cout << "RankOneTensor" << endl;
	cout << "Same size" << endl;
	{
		RankOneTensor t1(3);
		RankOneTensor t3(3);
		t1.loadData();
		t3.loadData();
		cout << t1;
		cout << t3;
		cout << t1 + t3;
	}

	cout << "\nBigger size" << endl;
	{
		RankOneTensor t1(3);
		RankOneTensor t3(2);
		t1.loadData();
		t3.loadData();
		cout << t1;
		cout << t3;
		cout << t1 + t3;
	}

	cout << "\nSmaller size" << endl;
	{
		RankOneTensor t1(2);
		RankOneTensor t3(3);
		t1.loadData();
		t3.loadData();
		cout << t1;
		cout << t3;
		cout << t1 + t3;
	}

	cout << "RankTwoTensor" << endl;
	cout << "\nSame size" << endl;
	{
		RankTwoTensor t2(3, 2);
		t2.loadData();
		RankTwoTensor t4(3, 2);
		t4.loadData();
		cout << t2;
		cout << t4;
		cout << t2 + t4;
	}

	cout << "\nBigger outer vector" << endl;
	{
		{
			cout << "Same size inner vector" << endl;
			RankTwoTensor t2(3, 2);
			t2.loadData();
			RankTwoTensor t4(2, 2);
			t4.loadData();
			cout << t2;
			cout << t4;
			cout << t2 + t4;
		}

		{
			cout << "\nBigger inner vector" << endl;
			RankTwoTensor t2(3, 2);
			t2.loadData();
			RankTwoTensor t4(2, 3);
			t4.loadData();
			cout << t2;
			cout << t4;
			cout << t2 + t4;
		}

		{
			cout << "\nSmaller inner vector" << endl;
			RankTwoTensor t2(3, 3);
			t2.loadData();
			RankTwoTensor t4(2, 2);
			t4.loadData();
			cout << t2;
			cout << t4;
			cout << t2 + t4;
		}
	}

	cout << "\nSmaller outer vector" << endl;
	{
		{
			cout << "Same size inner vector" << endl;
			RankTwoTensor t2(2, 2);
			t2.loadData();
			RankTwoTensor t4(3, 2);
			t4.loadData();
			cout << t2;
			cout << t4;
			cout << t2 + t4;
		}

		{
			cout << "\nBigger inner vector" << endl;
			RankTwoTensor t2(2, 2);
			t2.loadData();
			RankTwoTensor t4(3, 3);
			t4.loadData();
			cout << t2;
			cout << t4;
			cout << t2 + t4;
		}

		{
			cout << "\nSmaller inner vector" << endl;
			RankTwoTensor t2(2, 2);
			t2.loadData();
			RankTwoTensor t4(3, 1);
			t4.loadData();
			cout << t2;
			cout << t4;
			cout << t2 + t4;
		}
	}
}

void testDynamicCasting()
{
	cout<<"Testing dynamic casting"<<endl;

	BaseTensor *t1= new RankOneTensor(3);
	BaseTensor *t2 = new RankTwoTensor(3, 2);
	RankOneTensor *r1 = new RankOneTensor(3);
	RankTwoTensor *r2 = new RankTwoTensor(3, 2);

    if (dynamic_cast<RankOneTensor *>(t1)) {
		cout << endl << "Dynamic casting from BaseTensor to RankOneTensor successful." << endl;
    } else {
        cout << "Dynamic casting from BaseTensor to RankOneTensor failed." << endl;
    }

    if (dynamic_cast<RankTwoTensor *>(t2)) {
		cout << "Dynamic casting from BaseTensor to RankTwoTensor successful." << endl;
    } else {
        cout << "Dynamic casting from BaseTensor to RankTwoTensor failed." << endl;
    }

    if (dynamic_cast<BaseTensor *>(r1)) {
        cout << "Dynamic casting from RankOneTensor to BaseTensor successful." << endl;
    } else {
        cout << "Dynamic casting from RankOneTensor to BaseTensor failed." << endl;
    }

    if (dynamic_cast<BaseTensor *>(r2)) {
        cout << "Dynamic casting from RankTwoTensor to BaseTensor successful." << endl;
    } else {
        cout << "Dynamic casting from RankTwoTensor to BaseTensor failed." << endl;
    }

	if (dynamic_cast<RankOneTensor *>(r2)) {
		cout << "Dynamic casting from RankTwoTensor to RankOneTensor successful." << endl;
	} else {
		cout << "Dynamic casting from RankTwoTensor to RankOneTensor failed." << endl;
	}

	if (dynamic_cast<RankTwoTensor *>(r1)) {
		cout << "Dynamic casting from RankOneTensor to RankTwoTensor successful." << endl;
	} else {
		cout << "Dynamic casting from RankOneTensor to RankTwoTensor failed." << endl;
	}

    delete t1;
    delete t2;
    delete r1;
    delete r2;
	
}

int main()
{
	// testOutputStreamOperator();
	// testAssignment();
	// testFileStreamUsingOperator();
	// testInput();
	// testIncrementDecrement();
	// testPlusOperator();
	testDynamicCasting();
	return 0;
}
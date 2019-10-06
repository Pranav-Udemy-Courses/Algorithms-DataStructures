/* ------------------------------------------------------------------------------------
			UpperTriangular Header (UpperTriangular.hxx)
------------------------------------------------------------------------------------ */
#pragma once
#include <iostream>

using namespace std;

/* Class UpperTriangular */
class UpperTriangular
{
public:

	/* Default Constructor */
	UpperTriangular();

	/* Parameterized Constructor */
	UpperTriangular(int size);

	/* Destructor */
	~UpperTriangular();

	/* Get Element of Upper Triangular for given index using Column Major Strategy */
	int Get(int i, int j);

	/* Set Element of Upper Triangular at given index using Column Major Strategy */
	void Set(int i, int j, int x);

	/* Display Elements of Upper Triangular */
	void Display();

private:
	int* A = nullptr;  // Array created on heap
	int n;           // Size of matrix nXn
};

/* ------------------------------------------------------------------------------------
		UpperTriangular Implementation (UpperTriangular.cxx)
------------------------------------------------------------------------------------ */
#include "UpperTriangular.hxx"

/* ----------------------------------------- */
UpperTriangular::UpperTriangular() : n(3)
{
	A = new int[(n) * (n + 1) / 2];
}

/* ----------------------------------------- */
UpperTriangular::UpperTriangular(int size) : n(size)
{
	A = new int[(n) * (n + 1) / 2];
}

/* ----------------------------------------- */
UpperTriangular::~UpperTriangular()
{
	delete[] A;
	A = nullptr;
}

/* ----------------------------------------- */
void UpperTriangular::Set(int i, int j, int x)
{
	if (i <= j)
		A[(j * (j - 1) / 2) + (i - 1)] = x;
}

/* ----------------------------------------- */
int UpperTriangular::Get(int i, int j)
{
	if (i <= j)
		return A[(j * (j - 1) / 2) + (i - 1)];
	return 0;
}

/* ----------------------------------------- */
void UpperTriangular::Display()
{
	cout << "The Matrix m is as follows :" << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i <= j)
				cout << A[(j * (j - 1) / 2) + (i - 1)] << "  ";
			else
				cout << "0  ";
		}
		cout << endl;
	}
}

/* ------------------------------------------------------------------------------------
			    Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "UpperTriangular.hxx"
#include <iostream>

using namespace std;

/* Main function */
int main()
{
	int d, x;
	cout << "Enter Dimension : ";
	cin >> d;
	UpperTriangular um(d);
	cout << "Enter all elements " << endl;
	for (int i = 1; i <= d; ++i)
	{
		cout << "Row " << i << " elements : " << endl;
		for (int j = 1; j <= d; ++j)
		{
			cin >> x;
			um.Set(i, j, x);
		}
		cout << endl;
	}
	um.Display();
	cout << "The value at index 2,2 is : " << um.Get(2, 2) << endl;
	system("pause");
	return 0;
}

/*
Output
Enter Dimension : 4
Enter all elements
Row 1 elements :
1
2
3
4

Row 2 elements :
0
2
3
4

Row 3 elements :
0
0
3
4

Row 4 elements :
0
0
0
4

The Matrix m is as follows :
1  2  3  4
0  2  3  4
0  0  3  4
0  0  0  4
The value at index 2,2 is : 2
*/

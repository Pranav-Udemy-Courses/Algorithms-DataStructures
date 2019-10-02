/* ------------------------------------------------------------------------------------
					SymmetricMatrix Header (SymmetricMatrix.hxx)
------------------------------------------------------------------------------------ */
#pragma once
#include <iostream>

using namespace std;

/* Class SymmetricMatrix */
class SymmetricMatrix
{
public:

	/* Default Constructor */
	SymmetricMatrix();

	/* Parameterised Constructor */
	SymmetricMatrix(int size);

	/* Destructor */
	~SymmetricMatrix();

	/* Get Element of Symmetric Matrix for given index using Row Major Strategy */
	int Get(int i, int j);

	/* Set Element of Symmetric Matrix at given index using Row Major Strategy */
	void Set(int i, int j, int x);

	/* Display Elements of Symmetric Matrix */
	void Display();

private:
	int* A = nullptr;  // Array created on heap
	int n;           // Size of matrix nXn
};

/* ------------------------------------------------------------------------------------
				   SymmetricMatrix Implementation (SymmetricMatrix.cxx)
------------------------------------------------------------------------------------ */
#include "SymmetricMatrix.hxx"

/* ----------------------------------------- */
SymmetricMatrix::SymmetricMatrix() : n(3)
{
	A = new int[(n) * (n + 1) / 2];
}

/* ----------------------------------------- */
SymmetricMatrix::SymmetricMatrix(int size) : n(size)
{
	A = new int[(n) * (n + 1) / 2];
}

/* ----------------------------------------- */
SymmetricMatrix::~SymmetricMatrix()
{
	delete[] A;
	A = nullptr;
}

/* ----------------------------------------- */
void SymmetricMatrix::Set(int i, int j, int x)
{
	if (i >= j)
		A[(i * (i - 1) / 2) + (j - 1)] = x;
}

/* ----------------------------------------- */
int SymmetricMatrix::Get(int i, int j)
{
	if (i >= j)
		return A[(i * (i - 1) / 2) + (j - 1)];
	return 0;
}

/* ----------------------------------------- */
void SymmetricMatrix::Display()
{
	cout << "The Matrix sm is as follows :" << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i >= j)
				cout << A[(i * (i - 1) / 2) + (j - 1)] << "  ";  // Row Major Logic for Lower Triangular
			else
				cout << A[(j * (j - 1) / 2) + (i - 1)] << "  ";  // Column Major Logic for Upper Triangular
		}
		cout << endl;
	}
}

/* ------------------------------------------------------------------------------------
							 Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "SymmetricMatrix.hxx"
#include <iostream>

using namespace std;

/* Main function */
int main()
{
	int d, x;
	cout << "Enter Dimension : ";
	cin >> d;
	SymmetricMatrix sm(d);
	cout << "Enter all elements " << endl;
	for (int i = 1; i <= d; ++i)
	{
		cout << "Row " << i << " elements : " << endl;
		for (int j = 1; j <= d; ++j)
		{
			cin >> x;
			sm.Set(i, j, x);
		}
		cout << endl;
	}
	sm.Display();
	cout << "The value at index 2,2 is : " << sm.Get(2, 2) << endl;
	system("pause");
	return 0;
}

/*
Output
Enter Dimension : 4
Enter all elements
Row 1 elements :
1
0
0
0

Row 2 elements :
2
3
0
0

Row 3 elements :
3
4
5
0

Row 4 elements :
4
5
6
7

The Matrix sm is as follows :
1  2  3  4
2  3  4  5
3  4  5  6
4  5  6  7
The value at index 2,2 is : 3
*/

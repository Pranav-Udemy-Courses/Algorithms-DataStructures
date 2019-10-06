/* ------------------------------------------------------------------------------------
			ToeplitzMatrix Header (ToeplitzMatrix.hxx)
------------------------------------------------------------------------------------ */
#pragma once
#include <iostream>

using namespace std;

/* Class ToeplitzMatrix */
class ToeplitzMatrix
{
public:

	/* Default Constructor */
	ToeplitzMatrix();

	/* Parameterised Constructor */
	ToeplitzMatrix(int size);

	/* Destructor */
	~ToeplitzMatrix();

	/* Get Element of Toeplitz Matrix for given index */
	int Get(int i, int j);

	/* Set Element of Toeplitz Matrix at given index */
	void Set(int i, int j, int x);

	/* Display Elements of Toeplitz Matrix */
	void Display();

private:
	int* A = nullptr;  // Array created on heap
	int n;           // Size of matrix nXn
};

/* ------------------------------------------------------------------------------------
		   ToeplitzMatrix Implementation (ToeplitzMatrix.cxx)
------------------------------------------------------------------------------------ */
#include "ToeplitzMatrix.hxx"

/* ----------------------------------------- */
ToeplitzMatrix::ToeplitzMatrix() : n(3)
{
	A = new int[2 * n - 1];
}

/* ----------------------------------------- */
ToeplitzMatrix::ToeplitzMatrix(int size) : n(size)
{
	A = new int[2 * n - 1];
}

/* ----------------------------------------- */
ToeplitzMatrix::~ToeplitzMatrix()
{
	delete[] A;
	A = nullptr;
}

/* ----------------------------------------- */
void ToeplitzMatrix::Set(int i, int j, int x)
{
	if (i <= j)
		A[j - i] = x;
	else
		A[n + i - j - 1] = x;
}

/* ----------------------------------------- */
int ToeplitzMatrix::Get(int i, int j)
{
	if (i <= j)
		return A[j - i];
	else
		return A[(n + i - j - 1)];
}

/* ----------------------------------------- */
void ToeplitzMatrix::Display()
{
	cout << "The Matrix tm is as follows :" << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i <= j)
				cout << A[j - i] << "  ";
			else
				cout << A[(n + i - j - 1)] << "  ";
		}
		cout << endl;
	}
}

/* ------------------------------------------------------------------------------------
				Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "ToeplitzMatrix.hxx"
#include <iostream>

using namespace std;

/* Main function */
int main()
{
	int d, x;
	cout << "Enter Dimension : ";
	cin >> d;
	ToeplitzMatrix tbm(d);
	cout << "Enter all elements " << endl;
	for (int i = 1; i <= d; ++i)
	{
		cout << "Row " << i << " elements : " << endl;
		for (int j = 1; j <= d; ++j)
		{
			cin >> x;
			tbm.Set(i, j, x);
		}
		cout << endl;
	}
	tbm.Display();
	cout << "The value at index 2,2 is : " << tbm.Get(2, 2) << endl;
	system("pause");
	return 0;
}

/*
Output
Enter Dimension : 5
Enter all elements
Row 1 elements :
1
2
3
4
5

Row 2 elements :
6
1
2
3
4

Row 3 elements :
7
6
1
2
3

Row 4 elements :
8
7
6
1
2

Row 5 elements :
9
8
7
6
1

The Matrix tm is as follows :
1  2  3  4  5
6  1  2  3  4
7  6  1  2  3
8  7  6  1  2
9  8  7  6  1
The value at index 2,2 is : 1
*/
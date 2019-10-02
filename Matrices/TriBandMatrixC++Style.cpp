/* ------------------------------------------------------------------------------------
					TriBandMatrix Header (TriBandMatrix.hxx)
------------------------------------------------------------------------------------ */
#pragma once
#include <iostream>

using namespace std;

/* Class TriBandMatrix */
class TriBandMatrix
{
public:

	/* Default Constructor */
	TriBandMatrix();

	/* Parameterised Constructor */
	TriBandMatrix(int size);

	/* Destructor */
	~TriBandMatrix();

	/* Get Element of TriBand Matrix for given index */
	int Get(int i, int j);

	/* Set Element of TriBand Matrix at given index */
	void Set(int i, int j, int x);

	/* Display Elements of TriBand Matrix */
	void Display();

private:
	int* A = nullptr;  // Array created on heap
	int n;           // Size of matrix nXn
};

/* ------------------------------------------------------------------------------------
				   TriBandMatrix Implementation (TriBandMatrix.cxx)
------------------------------------------------------------------------------------ */
#include "TriBandMatrix.hxx"

/* ----------------------------------------- */
TriBandMatrix::TriBandMatrix() : n(3)
{
	A = new int[3 * n - 2];
}

/* ----------------------------------------- */
TriBandMatrix::TriBandMatrix(int size) : n(size)
{
	A = new int[3 * n - 2];
}

/* ----------------------------------------- */
TriBandMatrix::~TriBandMatrix()
{
	delete[] A;
	A = nullptr;
}

/* ----------------------------------------- */
void TriBandMatrix::Set(int i, int j, int x)
{
	if (i - j == -1)
		A[i - 2] = x;
	else if (i - j == 0)
		A[(n - 1 + i - 1)] = x;
	else if (i - j == 1)
		A[(2 * n - 1 + i - 1)] = x;
}

/* ----------------------------------------- */
int TriBandMatrix::Get(int i, int j)
{
	if (i - j == -1)
		return A[i - 2];
	else if (i - j == 0)
		return A[(n - 1 + i - 1)];
	else if (i - j == 1)
		return A[(2 * n - 1 + i - 1)];
	else
		return 0;
}

/* ----------------------------------------- */
void TriBandMatrix::Display()
{
	cout << "The Matrix tbm is as follows :" << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i - j == -1)
				cout << A[i - 2] << "  ";
			else if (i - j == 0)
				cout << A[(n - 1 + i - 1)] << "  ";
			else if (i - j == 1)
				cout << A[(2 * n - 1 + i - 1)] << "  ";
			else
				cout << "0  ";
		}
		cout << endl;
	}
}

/* ------------------------------------------------------------------------------------
							 Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "TriBandMatrix.hxx"
#include <iostream>

using namespace std;

/* Main function */
int main()
{
	int d, x;
	cout << "Enter Dimension : ";
	cin >> d;
	TriBandMatrix tbm(d);
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
Enter Dimension : 4
Enter all elements
Row 1 elements :
1
2
3
4

Row 2 elements :
1
2
3
4

Row 3 elements :
1
2
3
4

Row 4 elements :
1
2
3
4

The Matrix tbm is as follows :
1  2  0  0
1  2  3  0
0  2  3  4
0  0  3  4
The value at index 2,2 is : 2
*/

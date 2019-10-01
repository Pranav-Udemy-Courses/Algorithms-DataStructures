/* ------------------------------------------------------------------------------------ 
                    DiagonalMatrix Header (DiagonalMatrix.hxx)
------------------------------------------------------------------------------------ */
#pragma once
#include <iostream>

using namespace std;

/* Class DiagonalMatrix */
class DiagonalMatrix
{
public:

    /* Default Constructor */
    DiagonalMatrix();

    /* Parameterised Constructor */
    DiagonalMatrix(int size);

    /* Destructor */
    ~DiagonalMatrix();

    /* Get Element of Diagonal Matrix for given index */
    int Get(int i, int j);

    /* Set Element of Diagonal Matrix at given index */
    void Set(int i, int j, int x);

    /* Display Elements of Diagonal Matrix */
    void Display();

private:
    int* A = nullptr;  // Array created on heap
    int n;           // Size of matrix nXn
};

/* ------------------------------------------------------------------------------------
                   DiagonalMatrix Implementation (DiagonalMatrix.cxx)
------------------------------------------------------------------------------------ */
#include "DiagonalMatrix.hxx"

/* ----------------------------------------- */
DiagonalMatrix::DiagonalMatrix() : n(2)
{
    A = new int[n];
}

/* ----------------------------------------- */
DiagonalMatrix::DiagonalMatrix(int size) : n(size)
{
    A = new int[n];
}

/* ----------------------------------------- */
DiagonalMatrix::~DiagonalMatrix()
{
    delete[] A;
    A = nullptr;
}

/* ----------------------------------------- */
void DiagonalMatrix::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

/* ----------------------------------------- */
int DiagonalMatrix::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    return 0;
}

/* ----------------------------------------- */
void DiagonalMatrix::Display()
{
    cout << "The Matrix m is as follows :" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                cout << A[i] << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
}

/* ------------------------------------------------------------------------------------
                             Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "DiagonalMatrix.hxx"
#include <iostream>

using namespace std;

/* Main function */
int main()
{
    DiagonalMatrix d(4);
    d.Set(1, 1, 7);
    d.Set(2, 2, 9);
    d.Set(3, 3, 5);
    d.Set(4, 4, 12);
    d.Display();
    cout << "The value at index 2,2 is : " << d.Get(2, 2) << endl;
    system("pause");
    return 0;
}

/*
Output
The Matrix m is as follows :
7  0  0  0
0  9  0  0
0  0  5  0
0  0  0  12
The value at index 2,2 is : 9
*/
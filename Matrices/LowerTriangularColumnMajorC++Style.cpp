/* ------------------------------------------------------------------------------------
                    LowerTriangular Header (LowerTriangular.hxx)
------------------------------------------------------------------------------------ */
#pragma once
#include <iostream>

using namespace std;

/* Class LowerTriangular */
class LowerTriangular
{
public:

    /* Default Constructor */
    LowerTriangular();

    /* Parameterised Constructor */
    LowerTriangular(int size);

    /* Destructor */
    ~LowerTriangular();

    /* Get Element of Lower Triangular for given index using Column Major Strategy */
    int Get(int i, int j);

    /* Set Element of Lower Triangular at given index using Column Major Strategy */
    void Set(int i, int j, int x);

    /* Display Elements of Lower Triangular */
    void Display();

private:
    int* A = nullptr;  // Array created on heap
    int n;           // Size of matrix nXn
};

/* ------------------------------------------------------------------------------------
                   LowerTriangular Implementation (LowerTriangular.cxx)
------------------------------------------------------------------------------------ */
#include "LowerTriangular.hxx"

/* ----------------------------------------- */
LowerTriangular::LowerTriangular() : n(3)
{
    A = new int[(n) * (n + 1) / 2];
}

/* ----------------------------------------- */
LowerTriangular::LowerTriangular(int size) : n(size)
{
    A = new int[(n) * (n + 1) / 2];
}

/* ----------------------------------------- */
LowerTriangular::~LowerTriangular()
{
    delete[] A;
    A = nullptr;
}

/* ----------------------------------------- */
void LowerTriangular::Set(int i, int j, int x)
{
    if (i >= j)
        A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
}

/* ----------------------------------------- */
int LowerTriangular::Get(int i, int j)
{
    if (i >= j)
        return A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    return 0;
}

/* ----------------------------------------- */
void LowerTriangular::Display()
{
    cout << "The Matrix m is as follows :" << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i >= j)
                cout << A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
}

/* ------------------------------------------------------------------------------------
                             Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "LowerTriangular.hxx"
#include <iostream>

using namespace std;

/* Main function */
int main()
{
    int d, x;
    cout << "Enter Dimension : ";
    cin >> d;
    LowerTriangular lm(d);
    cout << "Enter all elements " << endl;
    for (int i = 1; i <= d; ++i)
    {
        cout << "Row " << i << " elements : " << endl;
        for (int j = 1; j <= d; ++j)
        {
            cin >> x;
            lm.Set(i, j, x);
        }
        cout << endl;
    }
    lm.Display();
    cout << "The value at index 2,2 is : " << lm.Get(2, 2) << endl;
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
1
2
0
0

Row 3 elements :
1
2
3
0

Row 4 elements :
1
2
3
4

The Matrix m is as follows :
1  0  0  0
1  2  0  0
1  2  3  0
1  2  3  4
The value at index 2,2 is : 2
*/
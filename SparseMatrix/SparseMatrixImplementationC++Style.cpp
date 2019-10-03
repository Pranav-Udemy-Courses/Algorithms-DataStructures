/* ------------------------------------------------------------------------------------
                    Element Header (Element.hxx)
------------------------------------------------------------------------------------ */
#include<iostream>

using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

/* ------------------------------------------------------------------------------------
                    SparseMatrix Header (SparseMatrix.hxx)
------------------------------------------------------------------------------------ */
#include "Element.hxx"

using namespace std;

class SparseMatrix
{
public:

    /* Parameterized Constructor */
    SparseMatrix(int m, int n, int num);

    /* Destructor */
    ~SparseMatrix();

    /* Add Operator overloaded */
    SparseMatrix operator +(SparseMatrix& other);

    /* Extraction Operator overloaded */
    friend istream& operator >>(istream& is, SparseMatrix& s);

    /* Insertion Operator overloaded */
    friend ostream& operator <<(ostream& os, const SparseMatrix& s);

    /* Function to Read input from user */
    void ReadInput();

    /* Function to Display elements of Sparse Matrix */
    void Display();

private:
    int m;
    int n;
    int num;
    Element* e = nullptr;
};

/* ------------------------------------------------------------------------------------
                    SparseMatrix Implementation (SparseMatrix.cxx)
------------------------------------------------------------------------------------ */
#include "SparseMatrix.hxx"

/* --------------------------------------------------------- */
SparseMatrix::SparseMatrix(int m, int n, int num)
{
    this->m = m;
    this->n = n;
    this->num = num;
    this->e = new Element[this->num];
}

/* --------------------------------------------------------- */
SparseMatrix::~SparseMatrix()
{
    delete[] e;
    e = nullptr;
}

/* --------------------------------------------------------- */
SparseMatrix SparseMatrix::operator+(SparseMatrix& other)
{
    if (m != other.m || n != other.n)
        return SparseMatrix(0, 0, 0);
    SparseMatrix * result = new SparseMatrix(m, n, num + other.num);
    result->e = new Element[num + other.num];
    int p = 0, q = 0, k = 0;
    while (p < num && q < other.num)
    {
        if (e[p].i < other.e[q].i)  // ith index of this is less than ith index of other (ith index = row index)
            result->e[k++] = e[p++];
        else if (e[p].i > other.e[q].i)  // ith index of this is greater than ith index of other (ith index = row index)
            result->e[k++] = other.e[q++];
        else  // ith index of this is equal to ith index of other (ith index = row index)
        {
            if (e[p].j < other.e[q].j)  // ith index is same but jth index of this is less than jth index of other (ith index = row index, jth index = column index)
                result->e[k++] = e[p++];
            else if (e[p].j > other.e[q].j)  // ith index is same but jth index of this is greater than jth index of other (ith index = row index, jth index = column index)
                result->e[k++] = other.e[q++];
            else  // ith and jth index of this and other are same so first copy element of this into result and then add element.x of other to result
            {
                result->e[k] = e[p++];
                result->e[k++].x += other.e[q++].x;
            }
        }
    }

    for (; p < num;)
        result->e[k++] = e[p++];
    for (; q < other.num;)
        result->e[k++] = other.e[q++];
    result->num = k;
    return *result;
}

/* --------------------------------------------------------- */
void SparseMatrix::ReadInput()
{
    cout << "Enter the Row, Column & Element" << endl;
    for (int i = 0; i < this->num; ++i)
    {
        cin >> e[i].i >> e[i].j >> e[i].x;
    }
}

/* --------------------------------------------------------- */
void SparseMatrix::Display()
{
    int k = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == e[k].i && j == e[k].j)
                cout << e[k++].x << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
}

/* --------------------------------------------------------- */
istream& operator>>(istream & is, SparseMatrix & s)
{
    cout << "Enter the Row, Column & Element" << endl;
    for (int i = 0; i < s.num; ++i)
    {
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
    return is;
}

/* --------------------------------------------------------- */
ostream& operator<<(ostream & os, const SparseMatrix & s)
{
    int k = 0;
    for (int i = 0; i < s.m; ++i)
    {
        for (int j = 0; j < s.n; ++j)
        {
            if (i == s.e[k].i && j == s.e[k].j)
                cout << s.e[k++].x << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
    return os;
}

/* ------------------------------------------------------------------------------------
                             Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include <iostream>
#include "SparseMatrix.hxx"

using namespace std;

/* Main Method */
int main()
{
    SparseMatrix sm1(5, 5, 5);
    sm1.ReadInput();
    SparseMatrix sm2(5, 5, 5);
    cin >> sm2;

    cout << "Printing elements of First Matrix " << endl;
    sm1.Display();
    cout << "Printing elements of Second Matrix\n" << sm2 << endl;
    SparseMatrix res = sm1 + sm2;
    cout << "Printing elements of Result Matrix\n" << res << endl;

    system("pause");
    return 0;
}

/*
Output

Enter the Row, Column & Element
0 0 1
1 1 1
2 2 1
3 3 1
4 4 1

Enter the Row, Column & Element
0 0 4
1 0 8
2 2 4
3 0 9
4 4 4

Printing elements of First Matrix
1  0  0  0  0
0  1  0  0  0
0  0  1  0  0
0  0  0  1  0
0  0  0  0  1

Printing elements of Second Matrix
4  0  0  0  0
8  0  0  0  0
0  0  4  0  0
9  0  0  0  0
0  0  0  0  4

Printing elements of Result Matrix
5  0  0  0  0
8  1  0  0  0
0  0  5  0  0
9  0  0  1  0
0  0  0  0  5
*/

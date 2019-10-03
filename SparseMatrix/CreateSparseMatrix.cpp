#include <iostream>

using namespace std;

/* Structure for an Element */
struct Element
{
    int i;  // Row number of the non-zero element
    int j;  // Column number of the non-zero element
    int x;  // Non-zero element
};

/* Structure for Sparse Matrix */
struct SparseMatrix
{
    int m;  // Number of rows in a Matrix
    int n;  // Number of columns in a Matrix
    int num; // Number of non-zero elements
    Element* e;  // Array of Element
};

/* Create a Sparse Matrix */
void CreateSparseMatrix(SparseMatrix* sm)
{
    cout << "Enter the dimensions of sparse matrix : " << endl;
    cin >> sm->m >> sm->n;
    cout << "Enter the number of non-zero elements : " << endl;
    cin >> sm->num;
    sm->e = new Element[sm->num];  // Array of Elements of size sm->num
    cout << "Enter the Row, Column & Element" << endl;
    for (int i = 0; i < sm->num; ++i)
    {
        cin >> sm->e[i].i >> sm->e[i].j >> sm->e[i].x;
    }
}

/* Display all Elements of Sparse Matrix */
void DisplaySparseMatrix(SparseMatrix sm)
{
    int k = 0;
    cout << "Printing the elements of Sparse Matrix : " << endl;
    for (int i = 0; i < sm.m; ++i)
    {
        for (int j = 0; j < sm.n; ++j)
        {
            if (i == sm.e[k].i && j == sm.e[k].j)
                cout << sm.e[k++].x << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
}

/* Main Method */
int main()
{
    SparseMatrix sm;
    CreateSparseMatrix(&sm);
    DisplaySparseMatrix(sm);
    system("pause");
    return 0;
}

/*
Output
Enter the dimensions of sparse matrix :
3 3
Enter the number of non-zero elements :
4
Enter the Row, Column & Element
0 0 1
1 0 2
2 0 3
2 2 4
Printing the elements of Sparse Matrix :
1  0  0
2  0  0
3  0  4
*/
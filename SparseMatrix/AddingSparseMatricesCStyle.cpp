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

/* Addition of two sparse matrices */
SparseMatrix* AddSparseMatrices(SparseMatrix * sm1, SparseMatrix * sm2)
{
    if (sm1->m != sm2->m || sm1->n != sm2->n)
        return nullptr;
    SparseMatrix * result = new SparseMatrix();
    result->m = sm1->m;
    result->n = sm1->n;
    result->e = new Element[sm1->num + sm2->num];
    int p = 0, q = 0, k = 0;
    while (p < sm1->num && q < sm2->num)
    {
        if (sm1->e[p].i < sm2->e[q].i)  // ith index of sm1 is less than ith index of sm2 (ith index = row index)
            result->e[k++] = sm1->e[p++];
        else if (sm1->e[p].i > sm2->e[q].i)  // ith index of sm1 is greater than ith index of sm2 (ith index = row index)
            result->e[k++] = sm2->e[q++];
        else  // ith index of sm1 is equal to ith index of sm2 (ith index = row index)
        {
            if (sm1->e[p].j < sm2->e[q].j)  // ith index is same but jth index of sm1 is less than jth index of sm2 (ith index = row index, jth index = column index)
                result->e[k++] = sm1->e[p++];
            else if (sm1->e[p].j > sm2->e[q].j)  // ith index is same but jth index of sm1 is greater than jth index of sm2 (ith index = row index, jth index = column index)
                result->e[k++] = sm2->e[q++];
            else  // ith and jth index of sm1 and sm2 are same so first copy element of sm1 into result and then add element.x of sm2 to result
            {
                result->e[k] = sm1->e[p++];
                result->e[k++].x += sm2->e[q++].x;
            }
        }
    }

    for (; p < sm1->num;)
        result->e[k++] = sm1->e[p++];
    for (; q < sm2->num;)
        result->e[k++] = sm2->e[q++];
    result->num = k;
    return result;
}

/* Main Method */
int main()
{
    SparseMatrix sm1;
    CreateSparseMatrix(&sm1);
    SparseMatrix sm2;
    CreateSparseMatrix(&sm2);
    cout << "Printing the elements of First Matrix : " << endl;
    DisplaySparseMatrix(sm1);
    cout << "Printing the elements of Second Matrix : " << endl;
    DisplaySparseMatrix(sm2);
    cout << "Printing the elements of Result Matrix : " << endl;
    SparseMatrix* result = AddSparseMatrices(&sm1, &sm2);
    DisplaySparseMatrix(*result);
    system("pause");
    return 0;
}

/*
Output
Enter the dimensions of sparse matrix :
4 4
Enter the number of non-zero elements :
4
Enter the Row, Column & Element
0 0 1
0 1 1
0 2 1
0 3 1
Enter the dimensions of sparse matrix :
4 4
Enter the number of non-zero elements :
4
Enter the Row, Column & Element
0 0 2
1 0 2
2 0 2
3 0 2
Printing the elements of First Matrix :
1  1  1  1
0  0  0  0
0  0  0  0
0  0  0  0
Printing the elements of Second Matrix :
2  0  0  0
2  0  0  0
2  0  0  0
2  0  0  0
Printing the elements of Result Matrix :
3  1  1  1
2  0  0  0
2  0  0  0
2  0  0  0
*/
#include <iostream>

using namespace std;

/* Structure of Node */
typedef struct Node_t
{
    int data;
    int col;
    Node_t* next;
}Node_s;

/* Initialize Sparse Matrix */
Node_s** Initialize(int noOfRows)
{
    Node_s** A = new Node_s * [noOfRows];
    for (int i = 0; i < noOfRows; ++i)
    {
        A[i] = nullptr;
    }
    return A;
}

/* Create Sparse Matrix */
void Create(Node_s** list, int row, int col, int data)
{
    Node_s* temp = list[row];
    Node_s* t = new Node_s;
    t->data = data;
    t->col = col;
    t->next = nullptr;
    if (temp == nullptr)
    {
        list[row] = t;
        return;
    }
    else
    {
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = t;
    }
}

/* Display a Sparse Matrix */
void Display(Node_s * *list, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        Node_s* temp = *(list + i);
        for (int j = 0; j < col; ++j)
        {
            if (temp != nullptr && temp->col == j)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            else
                cout << "0  ";
        }
        cout << endl;
    }
}

Node_s** AddSparseMatrices(Node_s * *list1, Node_s * *list2, int row, int col)
{
    Node_s** sumList = Initialize(row);
    for (int i = 0; i < row; ++i)
    {
        Node_s* p = *(list1 + i);
        Node_s * q = *(list2 + i);
        for (int j = 0; j < col; ++j)
        {
            if (p != nullptr && q != nullptr && p->col == j && q->col == j)
            {
                Create(sumList, i, j, p->data + q->data);
                p = p->next;
                q = q->next;
            }
            else if (p != nullptr && p->col == j && ((q != nullptr && q->col != j) || (q == nullptr)))
            {
                Create(sumList, i, j, p->data);
                p = p->next;
            }
            else if (q != nullptr && q->col == j && ((p != nullptr && p->col != j) || (p == nullptr)))
            {
                Create(sumList, i, j, q->data);
                q = q->next;
            }
        }
    }
    return sumList;
}

/* Main Method */
int main()
{
    int totrows, row, col, totcols, num, data;
    cout << "Enter the number of rows and columns : ";
    cin >> totrows >> totcols;
    cout << endl;
    cout << "Enter the number of non-zero elements : ";
    cin >> num;
    cout << endl;
    Node_s** array1 = Initialize(totrows);
    for (int i = 0; i < num; ++i)
    {
        cout << "Enter row, col and data for " << i + 1 << " non-zero element of array1 : ";
        cin >> row >> col >> data;
        Create(array1, row, col, data);
    }
    cout << endl;
    cout << "Enter the number of non-zero elements : ";
    cin >> num;
    cout << endl;
    Node_s** array2 = Initialize(totrows);
    for (int i = 0; i < num; ++i)
    {
        cout << "Enter row, col and data for " << i + 1 << " non-zero element of array2 : ";
        cin >> row >> col >> data;
        Create(array2, row, col, data);
    }
    cout << endl;
    cout << "Printing matrix 1 : " << endl << endl;
    Display(array1, totrows, totcols);
    cout << endl;
    cout << endl;
    cout << "Printing matrix 2 : " << endl << endl;
    Display(array2, totrows, totcols);
    cout << endl;
    Node_s** sum = AddSparseMatrices(array1, array2, totrows, totcols);
    cout << "Printing matrix 1 + matrix 2 : " << endl << endl;
    Display(sum, totrows, totcols);
    cout << endl;
    system("pause");
    return 0;
}

/*
Output

Enter the number of rows and columns : 3 4

Enter the number of non-zero elements : 4

Enter row, col and data for 1 non-zero element of array1 : 0 1 5
Enter row, col and data for 2 non-zero element of array1 : 0 3 7
Enter row, col and data for 3 non-zero element of array1 : 1 0 9
Enter row, col and data for 4 non-zero element of array1 : 2 2 4

Enter the number of non-zero elements : 3

Enter row, col and data for 1 non-zero element of array2 : 0 1 5
Enter row, col and data for 2 non-zero element of array2 : 1 3 6
Enter row, col and data for 3 non-zero element of array2 : 2 2 3

Printing matrix 1 :

0  5  0  7
9  0  0  0
0  0  4  0


Printing matrix 2 :

0  5  0  0
0  0  0  6
0  0  3  0

Printing matrix 1 + matrix 2 :

0  10  0  7
9  0  0  6
0  0  7  0

*/
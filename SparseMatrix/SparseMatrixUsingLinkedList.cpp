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
        cout << "Enter row, col and data for " << i + 1 << " non-zero element : ";
        cin >> row >> col >> data;
        Create(array1, row, col, data);
    }
    Display(array1, totrows, totcols);
    system("pause");
    return 0;
}

/*
Output
Enter the number of rows and columns : 3 4

Enter the number of non-zero elements : 5

Enter row, col and data for 1 non-zero element : 0 1 1
Enter row, col and data for 2 non-zero element : 0 3 2
Enter row, col and data for 3 non-zero element : 1 0 3
Enter row, col and data for 4 non-zero element : 2 2 4
Enter row, col and data for 5 non-zero element : 2 3 5
0  1  0  2
3  0  0  0
0  0  4  5
*/
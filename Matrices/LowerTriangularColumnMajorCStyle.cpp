#include <iostream>

using namespace std;

/* Matrix Structure */
struct Matrix
{
    int* A;
    int n;
};

/* Set Element of Lower Triangular Matrix at given index using Column major strategy */
void Set(Matrix* m, int i, int j, int x)
{
    if (i >= j)
        m->A[m->n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
}

/* Get Element of Lower Triangular Matrix for given index using Column major strategy */
int Get(Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}

/* Display Elements of Lower Triangular Matrix using Column major strategy */
void Display(Matrix m)
{
    cout << "The Matrix m is as follows :" << endl;
    for (int i = 1; i <= m.n; ++i)
    {
        for (int j = 1; j <= m.n; ++j)
        {
            if (i >= j)
                cout << m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }

}

/* Main function */
int main()
{
    Matrix m;
    int x;
    cout << "Enter size of matrix" << endl;
    cin >> m.n;
    m.A = (int*)malloc(sizeof(int) * (m.n) * (m.n + 1) / 2);
    cout << "Enter all elements " << endl;
    for (int i = 1; i <= m.n; ++i)
    {
        cout << "Row " << i << " elements : " << endl;
        for (int j = 1; j <= m.n; ++j)
        {
            cin >> x;
            Set(&m, i, j, x);
        }
        cout << endl;
    }
    Display(m);
    cout << "The value at index 2,2 is : " << Get(m, 2, 2) << endl;
    system("pause");
    return 0;
}

/*
Output
Enter size of matrix
4
Enter all elements
Row 1 elements :
2
0
0
0

Row 2 elements :
1
3
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
2  0  0  0
1  3  0  0
1  2  3  0
1  2  3  4
The value at index 2,2 is : 3
*/
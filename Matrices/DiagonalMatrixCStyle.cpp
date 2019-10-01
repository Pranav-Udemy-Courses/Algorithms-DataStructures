#include <iostream>

using namespace std;

/* Matrix Structure */
struct Matrix
{
    int A[10];
    int n;
};

/* Set Element of Diagonal Matrix at given index */
void Set(Matrix* m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}

/* Get Element of Diagonal Matrix for given index */
int Get(Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

/* Display Elements of Diagonal Matrix */
void Display(Matrix m)
{
    cout << "The Matrim m is as follows :" << endl;
    for (int i = 0; i < m.n; ++i)
    {
        for (int j = 0; j < m.n; ++j)
        {
            if (i == j)
                cout << m.A[i] << "  ";
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
    m.n = 4;
    Set(&m, 1, 1, 7);
    Set(&m, 2, 2, 9);
    Set(&m, 3, 3, 5);
    Set(&m, 4, 4, 12);
    Display(m);
    cout << "The value at index 2,2 is : " << Get(m, 2, 2) << endl;
    system("pause");
    return 0;
}

/*
Output
The Matrim m is as follows :
7  0  0  0
0  9  0  0
0  0  5  0
0  0  0  12
The value at index 2,2 is : 9
*/
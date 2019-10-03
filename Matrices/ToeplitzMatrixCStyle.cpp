#include <iostream>

using namespace std;

/* Matrix Structure */
struct Matrix
{
	int* A;
	int n;
};

/* Set Element of Toeplitz Matrix at given index */
void Set(Matrix* m, int i, int j, int x)
{
	if (i <= j)
		m->A[j - i] = x;
	else
		m->A[m->n + i - j - 1] = x;
}

/* Get Element of Toeplitz Matrix for given index */
int Get(Matrix m, int i, int j)
{
	if (i <= j)
		return m.A[j - i];
	else
		return m.A[(m.n + i - j - 1)];
}

/* Display Elements of Toeplitz Matrix */
void Display(Matrix m)
{
	cout << "The Matrix m is as follows :" << endl;
	for (int i = 1; i <= m.n; ++i)
	{
		for (int j = 1; j <= m.n; ++j)
		{
			if (i <= j)
				cout << m.A[j - i] << "  ";
			else
				cout << m.A[(m.n + i - j - 1)] << "  ";
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
	m.A = (int*)malloc(sizeof(int) * 2 * m.n - 1);
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
5
Enter all elements
Row 1 elements :
1
2
3
4
5

Row 2 elements :
6
1
2
3
4

Row 3 elements :
7
6
1
2
3

Row 4 elements :
8
7
6
1
2

Row 5 elements :
9
8
7
6
1

The Matrix m is as follows :
1  2  3  4  5
6  1  2  3  4
7  6  1  2  3
8  7  6  1  2
9  8  7  6  1
The value at index 2,2 is : 1
*/
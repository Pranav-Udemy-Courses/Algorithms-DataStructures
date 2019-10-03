#include <iostream>

using namespace std;

/* Matrix Structure */
struct Matrix
{
	int* A;
	int n;
};

/* Set Element of TriBand Matrix at given index */
void Set(Matrix* m, int i, int j, int x)
{
	if (i - j == -1)
		m->A[i - 2] = x;
	else if (i - j == 0)
		m->A[(m->n - 1 + i - 1)] = x;
	else if (i - j == 1)
		m->A[(2 * m->n - 1 + i - 1)] = x;
}

/* Get Element of TriBand Matrix for given index */
int Get(Matrix m, int i, int j)
{
	if (i - j == -1)
		return m.A[i - 2];
	else if (i - j == 0)
		return m.A[(m.n - 1 + i - 1)];
	else if (i - j == 1)
		return m.A[(2 * m.n - 1 + i - 1)];
	else
		return 0;
}

/* Display Elements of TriBand Matrix */
void Display(Matrix m)
{
	cout << "The Matrix m is as follows :" << endl;
	for (int i = 1; i <= m.n; ++i)
	{
		for (int j = 1; j <= m.n; ++j)
		{
			if (i - j == -1)
				cout << m.A[i - 2] << "  ";
			else if (i - j == 0)
				cout << m.A[(m.n - 1 + i - 1)] << "  ";
			else if (i - j == 1)
				cout << m.A[(2 * m.n - 1 + i - 1)] << "  ";
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
	m.A = (int*)malloc(sizeof(int) * 3 * m.n - 2);
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
1
2
3
4

Row 2 elements :
1
2
3
4

Row 3 elements :
1
2
3
4

Row 4 elements :
1
2
3
4

The Matrix m is as follows :
1  2  0  0
1  2  3  0
0  2  3  4
0  0  3  4
The value at index 2,2 is : 2
*/
#include <iostream>

using namespace std;

/* Matrix Structure */
struct Matrix
{
	int* A;
	int n;
};

/* Set Element of Upper Triangular Matrix at given index using Row major strategy */
void Set(Matrix* m, int i, int j, int x)
{
	if (i <= j)
		m->A[(m->n * (i - 1) - ((i - 2) * (i - 1) / 2)) + (j - i)] = x;
}

/* Get Element of Upper Triangular Matrix for given index using Row major strategy */
int Get(Matrix m, int i, int j)
{
	if (i <= j)
		return m.A[(m.n * (i - 1) - ((i - 2) * (i - 1) / 2)) + (j - i)];
	else
		return 0;
}

/* Display Elements of Upper Triangular Matrix using Row major strategy */
void Display(Matrix m)
{
	cout << "The Matrix m is as follows :" << endl;
	for (int i = 1; i <= m.n; ++i)
	{
		for (int j = 1; j <= m.n; ++j)
		{
			if (i <= j)
				cout << m.A[(m.n * (i - 1) - ((i - 2) * (i - 1) / 2)) + (j - i)] << "  ";
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
1
2
3
4

Row 2 elements :
0
2
3
4

Row 3 elements :
0
0
3
4

Row 4 elements :
0
0
0
4

The Matrix m is as follows :
1  2  3  4
0  2  3  4
0  0  3  4
0  0  0  4
The value at index 2,2 is : 2
*/
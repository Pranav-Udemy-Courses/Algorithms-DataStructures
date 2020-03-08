#include<iostream>

using namespace std;

/* Global Variables */
int GridSize;

/* Print Sudoku Table */
void Print(int** S, bool isSolved)
{
	if(isSolved)
		cout << endl << "The solved sudoku table is : " << endl << endl;
	else
		cout << endl << "The initial sudoku table is : " << endl << endl;
	cout << "-------------------------" << endl;
	for (int i = 0; i < GridSize; ++i)
	{
		cout << "| ";
		for (int j = 0; j < GridSize; ++j)
		{
			if ((j + 1) % 3 == 0)
				cout << S[i][j] << " | ";
			else
				cout << S[i][j] << " ";
		}
		if ((i + 1) % 3 == 0)
			cout << endl << "-------------------------";
		cout << endl;
	}
	cout << endl;
}

/* Check if the given value can be placed without any violation of rules */
bool CanBePlaced(int** S, int row, int col, int val)
{
	int m = 3 * (row / 3);
	int n = 3 * (col / 3);

	/* Check in the current grid if the value already exists */
	for (int i = m; i < m+3; ++i)
	{
		for (int j = n; j < n+3; ++j)
		{
			if (S[i][j] == val)
				return false;
		}
	}
	/* Check in the entire row and column if value already exists */
	for (int i = 0; i < GridSize; ++i)
	{
		if (S[row][i] == val || S[i][col] == val)
			return false;
	}

	return true;
}

/* Find unassigned position in the Grid */
bool FindUnassignedPosition(int** S, int& row, int& col)
{
	for (int i = 0; i < GridSize; ++i)
	{
		for (int j = 0; j < GridSize; ++j)
		{
			if (!S[i][j])
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

/* Sudoku Solver Using Backtracking */
bool SudokuSolver(int** S)
{
	int row, col;
	if (!FindUnassignedPosition(S, row, col))
		return true;

	for (int i = 1; i < 10; ++i)
	{
		if (CanBePlaced(S, row, col, i))
		{
			S[row][col] = i;
			if (SudokuSolver(S))
				return true;
			S[row][col] = 0;
		}
	}
	return false;
}

/* Main Method */
int main()
{
	int num, rowIndex, colIndex, val;
	cout << "Enter the size of Grid : ";
	cin >> GridSize;
	int** S = new int* [GridSize];
	for (int i = 0; i < GridSize; ++i)
		S[i] = new int[GridSize] {0};
	cout << "Enter the number of prefilled numbers : ";
	cin >> num;
	cout << "Note : Row and Column index start from 0" << endl;
	for (int i = 0; i < num; ++i)
	{
		cout << "Enter the row index, column index and value : ";
		cin >> rowIndex >> colIndex >> val;
		S[rowIndex][colIndex] = val;
	}
	Print(S, false);
	if(SudokuSolver(S))
		Print(S,true);
	return 0;
}

/*

Output

Enter the size of Grid : 9
Enter the number of prefilled numbers : 32
Note : Row and Column index start from 0
Enter the row index, column index and value : 0 0 3
Enter the row index, column index and value : 0 2 6
Enter the row index, column index and value : 0 3 5
Enter the row index, column index and value : 0 5 8
Enter the row index, column index and value : 0 6 4
Enter the row index, column index and value : 1 0 5
Enter the row index, column index and value : 1 1 2
Enter the row index, column index and value : 2 1 8
Enter the row index, column index and value : 2 2 7
Enter the row index, column index and value : 2 7 3
Enter the row index, column index and value : 2 8 1
Enter the row index, column index and value : 3 2 3
Enter the row index, column index and value : 3 4 1
Enter the row index, column index and value : 3 7 8
Enter the row index, column index and value : 4 0 9
Enter the row index, column index and value : 4 3 8
Enter the row index, column index and value : 4 4 6
Enter the row index, column index and value : 4 5 3
Enter the row index, column index and value : 4 8 5
Enter the row index, column index and value : 5 1 5
Enter the row index, column index and value : 5 4 9
Enter the row index, column index and value : 5 6 6
Enter the row index, column index and value : 6 0 1
Enter the row index, column index and value : 6 1 3
Enter the row index, column index and value : 6 6 2
Enter the row index, column index and value : 6 7 5
Enter the row index, column index and value : 7 7 7
Enter the row index, column index and value : 7 8 4
Enter the row index, column index and value : 8 2 5
Enter the row index, column index and value : 8 3 2
Enter the row index, column index and value : 8 5 6
Enter the row index, column index and value : 8 6 3

The initial sudoku table is :

-------------------------
| 3 0 6 | 5 0 8 | 4 0 0 |
| 5 2 0 | 0 0 0 | 0 0 0 |
| 0 8 7 | 0 0 0 | 0 3 1 |
-------------------------
| 0 0 3 | 0 1 0 | 0 8 0 |
| 9 0 0 | 8 6 3 | 0 0 5 |
| 0 5 0 | 0 9 0 | 6 0 0 |
-------------------------
| 1 3 0 | 0 0 0 | 2 5 0 |
| 0 0 0 | 0 0 0 | 0 7 4 |
| 0 0 5 | 2 0 6 | 3 0 0 |
-------------------------


The solved sudoku table is :

-------------------------
| 3 1 6 | 5 7 8 | 4 9 2 |
| 5 2 9 | 1 3 4 | 7 6 8 |
| 4 8 7 | 6 2 9 | 5 3 1 |
-------------------------
| 2 6 3 | 4 1 5 | 9 8 7 |
| 9 7 4 | 8 6 3 | 1 2 5 |
| 8 5 1 | 7 9 2 | 6 4 3 |
-------------------------
| 1 3 8 | 9 4 7 | 2 5 6 |
| 6 9 2 | 3 5 1 | 8 7 4 |
| 7 4 5 | 2 8 6 | 3 1 9 |
-------------------------

*/

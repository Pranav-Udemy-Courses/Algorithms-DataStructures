#include <iostream>

using namespace std;

/*
Note:
	Direction :
		1 : Up
		2 : Down
		3 : Left
		4 : Right

	Pipes :
		1 : Up, Down, Left, Right
		2 : Up, Down
		3 : Left, Right
		4 : Up, Right
		5 : Down, Right
		6 : Down, Left
		7 : Up, Left 
*/



/*
	Check if current grid pipe piece can join with it's
	adjacent pipe piece
	Return True if compatible False Otherwise
*/
bool IsCompatible(int orig, int tocomp, int direction)
{
	switch (orig)
	{
	case 1:
		return true;
		break;
	case 2:
		if (direction == 1 && (tocomp == 1 || tocomp == 2 || tocomp == 5 || tocomp == 6))
			return true;
		else if (direction == 2 && (tocomp == 1 || tocomp == 2 || tocomp == 4 || tocomp == 7))
			return true;
		break;
	case 3:
		if (direction == 3 && (tocomp == 1 || tocomp == 3 || tocomp == 4 || tocomp == 5))
			return true;
		else if (direction == 4 && (tocomp == 1 || tocomp == 3 || tocomp == 6 || tocomp == 7))
			return true;
		break;
	case 4:
		if (direction == 1 && (tocomp == 1 || tocomp == 2 || tocomp == 5|| tocomp == 6))
			return true;
		else if (direction == 4 && (tocomp == 1 || tocomp == 3 ||tocomp == 6 || tocomp == 7))
			return true;
		break;
	case 5:
		if (direction == 2 && (tocomp == 1 || tocomp == 2 || tocomp == 4 || tocomp == 7))
			return true;
		else if (direction == 4 && (tocomp == 1 || tocomp == 3 || tocomp == 6 || tocomp == 7))
			return true;
		break;
	case 6:
		if (direction == 3 && (tocomp == 1 || tocomp == 3 || tocomp == 4 || tocomp == 5))
			return true;
		else if (direction == 2 && (tocomp == 1 || tocomp == 2 || tocomp == 4 || tocomp == 7))
			return true;
		break;
	case 7:
		if (direction == 3 && (tocomp == 1 || tocomp == 3 || tocomp == 4 || tocomp == 5))
			return true;
		else if (direction == 1 && (tocomp == 1 || tocomp == 2 || tocomp == 5 || tocomp == 6))
			return true;
		break;
	default:
		break;
	}
	return false;
}

/*
	Check if the adjacent pipe is available or not
	Return True if available and compatible False Otherwise
*/
bool CheckFeasible(int** A,int row, int col, int irow, int icol, int direction)
{
	switch (direction)
	{
	case 1:
		if (irow - 1 >= 0 && A[irow - 1][icol] != 0)
			return IsCompatible(A[irow][icol], A[irow - 1][icol], direction);
		break;
	case 2:
		if (irow + 1 < row && A[irow + 1][icol] != 0)
			return IsCompatible(A[irow][icol], A[irow + 1][icol], direction);
		break;
	case 3:
		if (icol - 1 >= 0 && A[irow][icol - 1] != 0)
			return IsCompatible(A[irow][icol], A[irow][icol - 1], direction);
		break;
	case 4:
		if (icol + 1 < col && A[irow][icol + 1] != 0)
			return IsCompatible(A[irow][icol], A[irow][icol + 1], direction);
		break;
	default:
		break;
	}
	return false;
}

/* Find the maximum number of pipes detected for given length */
int SolveProblem(int** A, int row, int col, int irow, int icol, int len, int** Visited)
{
	if (len == 0 || !((irow >=0 && irow < row) && (icol >=0 && icol < col)) )
		return 0;

	Visited[irow][icol] = 1;
	int up = 0, down = 0, left = 0, right = 0;
	
	if(CheckFeasible(A, row, col, irow, icol, 1) && Visited[irow - 1][icol] == 0)
		up = SolveProblem(A, row, col, irow - 1, icol, len - 1, Visited);
	
	if (CheckFeasible(A, row, col, irow, icol, 2) && Visited[irow + 1][icol] == 0)
		down = SolveProblem(A, row, col, irow + 1, icol, len - 1, Visited);
	
	if (CheckFeasible(A, row, col, irow, icol, 3) && Visited[irow][icol - 1] == 0)
		left = SolveProblem(A, row, col, irow, icol - 1, len - 1, Visited);
	
	if(CheckFeasible(A, row, col, irow, icol, 4) && Visited[irow][icol + 1] == 0)
		right = SolveProblem(A, row, col, irow, icol + 1, len - 1, Visited);
	return (1 + up + down + left + right);
}

/* Read Input */
void ReadInput()
{
	int noTest;
	cin >> noTest;
	for (int i = 0; i < noTest; ++i)
	{
		int row, col, irow, icol, len;
		cin >> row >> col >> irow >> icol >> len;
		int** A = new int* [row];
		int** Visited = new int*[row];
		for (int j = 0; j < row; ++j)
		{
			A[j] = new int[col] {0};
			Visited[j] = new int[col] {0};
		}
		for (int m = 0; m < row; ++m)
		{
			for (int n = 0; n < col; ++n)
			{
				cin >> ws;
				cin >> A[m][n];
			}
		}
		cout << endl << "The maximum number of pipes that can be detected is : " << SolveProblem(A, row, col, irow, icol, len, Visited) << endl << endl;
		for (int j = 0; j < row; ++j)
		{
			delete[] A[j];
			delete[] Visited[j];
		}
	}
}

/* Main Method */
int main()
{
	ReadInput();
	return 0;
}

/*

Output

2
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0

The maximum number of pipes that can be detected is : 5

5 6 2 2 6
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1

The maximum number of pipes that can be detected is : 15

*/

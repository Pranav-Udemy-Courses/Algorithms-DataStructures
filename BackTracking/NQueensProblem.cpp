#include<iostream>
#include<vector>

using namespace std;

/* Global Variables */
int n = 4;
typedef vector<vector<int>> Grid;
vector<vector<int>> G(n, vector<int>(n,-1));

/* Prints the Solution for NQueen problem */
void PrintSolution(const Grid& G)
{
	cout << "The Solution using backtracking is : " << endl;
	for (auto i : G)
	{
		for (auto j : i)
		{
			cout << j << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

/* Checks if the given position is safe for placing Queen or not */
// Note : Since we are placing Queen row by row we only need to worry about upper left and upper right diagonals.
bool IsSafeToPlace(Grid& G, int row, int col)
{
	// Check if there is no other Queen placed in same row
	for (int c = 0; c < n; ++c)
	{
		if (G[row][c] > -1)
			return false;
	}

	// Check if there is no other Queen placed in same column
	for (int r = 0; r < n; ++r)
	{
		if (G[r][col] > -1)
			return false;
	}

	// Check if there is no other Queen in Upper left diagonal
	for (int i = row, j = col; i > -1 && j > -1; --i, --j)
	{
		if (G[i][j] > -1)
			return false;
	}

	// Check if there is no other Queen in Upper right diagonal
	for (int i = row, j = col; i >-1 && j < n; --i, ++j)
	{
		if (G[i][j] > -1)
			return false;
	}
	return true;
}

/* Place the Queen at given location */
void PlaceQueen(Grid& G, int row, int col)
{
	G[row][col] = row;
}

/* Remove the Queen at given location */
void RemoveQueen(Grid& G, int row, int col)
{
	G[row][col] = -1;
}

/* Use backtracking to solve NQueens problem */
bool NQueen(Grid& G, int row)
{
	// Check if all Queens have been placed
	if (row >= n)
	{
		PrintSolution(G);
		return true;
	}

	for (int col = 0; col < n; ++col)
	{
		// Check if it is safe to place the queen at given row and col
		if (IsSafeToPlace(G, row, col))
		{
			// Place the Queen
			PlaceQueen(G, row, col);

			// Check if Solution for row + 1 is viable if yes return true else we need to backtrack
			if (NQueen(G, row + 1))
				return true;
			// Backtrack and remove the queen from the given row and col
			RemoveQueen(G, row, col);
		}
	}
	return false;
}

/* Main Method */
int main()
{
	NQueen(G, 0);
	return 0;
}

/* 
Output 

The Solution using backtracking is : 
-1   0  -1 -1
-1  -1  -1  1
 2  -1  -1 -1
-1  -1   3 -1

*/

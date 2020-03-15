#include<iostream>

using namespace std;

/* Global Variables */
int GridRowSize;
int GridColSize;

/* Print Matrix */
void Print(int** NG)
{
	cout << "\tAfter Bursting Bomb : " << endl;
	for (int i = 0; i < GridRowSize; ++i)
	{
		cout << "\t";
		for (int j = 0; j < GridColSize; ++j)
			cout << NG[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

/* Blast Bomb and Kill all enemies in the current and above 4 rows */
void BlastBomb(int** NG, int currRow)
{
	int startIndex = 0;
	if (currRow - 5 >= 0)
		startIndex = currRow - 5;
	for (int i = startIndex; i < currRow; ++i)
	{
		for (int j = 0; j < GridColSize; ++j)
		{
			if (NG[i][j] == 2)
				NG[i][j] = 0;
		}
	}
	Print(NG);
}

/* Coins Collection Recursive Routine */
int CoinsCollectionUtil(int** NG, int currRow, int currCol)
{
	if (currRow < 0 || currCol < 0 || currCol >= GridColSize || NG[currRow][currCol] == 2)
		return 0;

	int left=0, right=0, none=0;
	if (currRow - 1 >= 0 && currCol - 1 >= 0)
	{
		left = CoinsCollectionUtil(NG, currRow - 1, currCol - 1);
		if (NG[currRow - 1][currCol - 1] == 0)
			--left;
	}
	if (currRow - 1 >=0 && currCol + 1 < GridColSize)
	{
		right = CoinsCollectionUtil(NG, currRow - 1, currCol + 1);
		if (NG[currRow - 1][currCol + 1] == 0)
			--right;
	}

	if (currRow - 1 >= 0)
	{
		none = CoinsCollectionUtil(NG, currRow - 1, currCol);
		if (NG[currRow -1][currCol] == 0)
			--none;
	}

	int ans = left > right ? left : right;
	return ans > none ? 1 + ans : 1 + none;
}

/* Collect Maximum Possible Coins */
int CollectMaxCoins(int** G)
{
	int ans = -1;
	int n = (GridColSize) / 2;
	for (int m = GridRowSize-1; m >= 0 ; --m)
	{
		cout << "Case " << m << " : " << endl;

		int** NG = new int* [GridRowSize];
		for (int i = 0; i < GridRowSize; ++i)
			NG[i] = new int[GridColSize] {0};
		for (int i = 0; i < GridRowSize; ++i)
		{
			for (int j = 0; j < GridColSize; ++j)
				NG[i][j] = G[i][j];
		}
		BlastBomb(NG, m);
		int res = CoinsCollectionUtil(NG, GridRowSize - 1, n);
		--res;
		cout << "Answer after Case : " << m << " : " << res << endl << endl;
		ans = ans > res ? ans : res;
		for (int i = 0; i < GridRowSize; ++i)
			delete[] NG[i];
	}
	return ans;
}

/* Main Method */
int main()
{
	cin >> GridRowSize >> GridColSize;
	int** G = new int* [GridRowSize];
	for (int i = 0; i < GridRowSize; ++i)
		G[i] = new int[GridColSize] {0};
	for (int i = 0; i < GridRowSize; ++i)
	{
		for (int j = 0; j < GridColSize; ++j)
		{
			cin >> G[i][j];
		}
	}
	cout << "The maximum coins collected can be : " << CollectMaxCoins(G) << endl;
	for (int i = 0; i < GridRowSize; ++i)
		delete[] G[i];
	return 0;
}

/*

Output :

8 5
1 2 2 2 1
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
1 1 0 0 1
0 0 0 0 0

The maximum coins collected can be : 6

*/

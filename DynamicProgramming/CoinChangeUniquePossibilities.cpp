#include<iostream>
#include <vector>

using namespace std;

/* Print Table for Understanding Coin Change Problem using DP */
void PrintTable(const vector<vector<int>>& A, const vector<int>& coinsDenomVec, int amount)
{
	cout << endl << "   ";
	for (int j = 0; j < amount + 1; ++j)
		cout << j << "  ";
	cout << endl;
	for (int i = 0; i < coinsDenomVec.size(); ++i)
	{
		cout << coinsDenomVec[i] << "  ";
		for (int j = 0; j < amount + 1; ++j)
		{
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}
}

/* Coin Change Unique Possibilities */
int CoinChangeUnique(const vector<int>& coinsDenomVec, int amount)
{
	vector<vector<int>> A(coinsDenomVec.size(), vector<int>(amount + 1, 0));
	for (int i = 1; i < coinsDenomVec.size(); ++i)
	{
		for (int j = 0; j < amount + 1; ++j)
		{
			if (j == 0)
			{
				A[i][j] = 1;
			}
			else
			{
				if (i >= j)
					A[i][j] = A[i - 1][j];
				else
				{
					if (j - coinsDenomVec[i] >= 0)
						A[i][j] = A[i - 1][j] + A[i][j - coinsDenomVec[i]];
					else
						A[i][j] = A[i - 1][j];
				}
			}
		}
	}
	PrintTable(A, coinsDenomVec, amount);
	return A[coinsDenomVec.size() - 1][amount];
}

/* Main Method */
int main()
{
	vector<int> coinsDenominationsVec{ 0 };
	int typesOfCoin, denom, amount;
	cout << "Enter the types of coin : ";
	cin >> typesOfCoin;
	for (size_t i = 0; i < typesOfCoin; i++)
	{
		cout << "Enter the " << i + 1 << " denomination : ";
		cin >> denom;
		coinsDenominationsVec.push_back(denom);
	}
	cout << "Enter the amount for coin change : ";
	cin >> amount;
	cout << "The number of unique possibilities are : " << CoinChangeUnique(coinsDenominationsVec, amount) << endl;
	return 0;
}

/*

Output

Enter the types of coin : 3
Enter the 1 denomination : 2
Enter the 2 denomination : 5
Enter the 3 denomination : 10
Enter the amount for coin change : 12

    0  1  2  3  4  5  6  7  8  9  10  11  12
0   0  0  0  0  0  0  0  0  0  0  0   0   0
2   1  0  1  0  1  0  1  0  1  0  1   0   1
5   1  0  1  0  1  1  1  1  1  1  2   1   2
10  1  0  1  0  1  1  1  1  1  1  3   1   3

The number of unique possibilities are : 3

*/

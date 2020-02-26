#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Print Table for better understanding of EggDropping Problem */
void PrintTable(vector<vector<int>>& A, int eggNum, int floorNum)
{
	cout << endl << "A  ";
	for (int i = 0; i <= floorNum; ++i)
		cout << i << "  ";
	cout << endl;
	for (int i = 0; i <= eggNum; ++i)
	{
		cout << i << "  ";
		for (int j = 0; j <= floorNum; ++j)
		{
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

/* EggDropping problem using DP */
int EggDropping(int floorNum, int eggNum)
{
	vector<vector<int>> A(eggNum + 1, vector<int>(floorNum + 1, 0));
	for (int i = 0; i <= floorNum; ++i)
		A[1][i] = i;
	for (int i = 2; i <= eggNum; ++i)
	{
		for (int j = 1; j <= floorNum; ++j)
		{
			if (i > j)
				A[i][j] = A[i - 1][j];
			else
			{
				int minChances = INT_MAX;
				for (int k = 1; k <= j; ++k)
				{
					int maxChances = 1 + max(A[i - 1][k - 1], A[i][j - k]);
					minChances = min(minChances, maxChances);
				}
				A[i][j] = minChances;
			}
		}
	}
	PrintTable(A, eggNum, floorNum);
	return A[eggNum][floorNum];
}

/* Main Method */
int main()
{
	int numOfFloors, numOfEggs;
	cout << "Enter the number of floors : ";
	cin >> numOfFloors;
	cout << "Enter the number of eggs : ";
	cin >> numOfEggs;
	cout << "The minimum number of attempts required to determine the fate for floor " << numOfFloors << " with " << numOfEggs << " eggs is : " << EggDropping(numOfFloors, numOfEggs) << endl << endl;
	return 0;
}

/*

Output

Enter the number of floors : 5
Enter the number of eggs : 3

A  0  1  2  3  4  5
0  0  0  0  0  0  0
1  0  1  2  3  4  5
2  0  1  2  2  3  3
3  0  1  2  2  3  3

The minimum number of attempts required to determine the fate for floor 5 with 3 eggs is : 3

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/* Print the Table for understanding of Knapsack logic */
void PrintTable(const vector<vector<int>>& A, int rows, int cols, const vector<int>& profit, const vector<int>& weight)
{
	cout << endl;
	cout << "P  W  | ";
	for (int i = 0; i < cols; ++i)
		cout << i << "  ";
	cout << endl;
	for (int i = 0; i < rows; ++i)
	{
		cout << profit[i] << "  " << weight[i] << "  | ";
		for (int j = 0; j < cols; ++j)
			cout << A[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}

/* Result of final objects to be selected */
vector<int> Result(const vector<vector<int>>& A, int numberOfItems,int rows, int cols, const vector<int>& weight)
{
	stack<bool> s;
	vector<int> ans;
	int t = cols - 1;
	for (int i = rows - 1; i > 0; --i)
	{
		bool include = true;
		for (int j = t; j > 0; --j)
		{
			if (A[i][t] == A[i - 1][j])
			{
				include = false;
				break;
			}
		}
		if (t <= 0)
			include = false;
		if (include)
			t -= weight[i];
		s.push(include);
	}
	while (!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}

/* Knapsack to find the maximum profit */
int Knapsack(int maximumWeight, int numberOfItems, const vector<int>& profit, const vector<int>& weight)
{
	int col = maximumWeight + 1;
	int row = numberOfItems + 1;
	vector<vector<int>> A(row, vector<int>(col, 0) );
	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if (weight[i] > j)
				A[i][j] = A[i - 1][j];
			else
			{
				if(j - weight[i] >= 0)
					A[i][j] = max(A[i - 1][j], A[i - 1][j - weight[i]] + profit[i]);
				else
					A[i][j] = A[i - 1][j];
			}
		}
	}
	PrintTable(A, row, col, profit, weight);
	auto res = Result(A, numberOfItems, row, col, weight);
	cout << "Weights vs Included :" << endl;
	for (int i = 0; i < numberOfItems; ++i)
	{
		cout << weight[i + 1] << " is included ? : " << res[i] << endl;
	}
	return A[row - 1][col - 1];
}

/* Main Method */
int main()
{
	vector<int> profit{ 0 };
	vector<int> weight{ 0 };
	int n, prf, wt, max_wt;
	cout << "Enter the maximum weight of the bag : ";
	cin >> max_wt;
	cout << "Enter the number of items : ";
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cout << "Enter the weight for object " << i << " : ";
		cin >> wt;
		weight.push_back(wt);
		cout << "Enter the profit for object " << i << " : ";
		cin >> prf;
		profit.push_back(prf);
	}
	cout << endl <<"The maximum possible weight that can be filled using DP knapsack is : " << Knapsack(max_wt, n, profit, weight) << endl << endl;
	return 0;
}

/*

Output

Enter the maximum weight of the bag : 8
Enter the number of items : 4
Enter the weight for object 1 : 2
Enter the profit for object 1 : 1
Enter the weight for object 2 : 3
Enter the profit for object 2 : 2
Enter the weight for object 3 : 4
Enter the profit for object 3 : 5
Enter the weight for object 4 : 5
Enter the profit for object 4 : 6

P  W  | 0  1  2  3  4  5  6  7  8
---------------------------------
0  0  | 0  0  0  0  0  0  0  0  0
1  2  | 0  0  1  1  1  1  1  1  1
2  3  | 0  0  1  2  2  3  3  3  3
5  4  | 0  0  1  2  5  5  6  7  7
6  5  | 0  0  1  2  5  6  6  7  8

Weights vs Included :
2 is included ? : 0
3 is included ? : 1
4 is included ? : 0
5 is included ? : 1

The maximum possible weight that can be filled using DP knapsack is : 8

*/
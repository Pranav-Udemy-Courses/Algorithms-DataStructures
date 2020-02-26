#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

/* Print LBS table for understanding */
void PrintLBSTable(const vector<int>& numVec, const vector<int>& LHSVec, const vector<int>& RHSVec)
{
	cout << endl << "Input Array : ";
	for (int i = 0; i < numVec.size(); ++i)
		cout << numVec[i] << "  ";
	cout << endl << "LHS Occur   : ";
	for (int i = 0; i < LHSVec.size(); ++i)
		cout << LHSVec[i] << "  ";
	cout << endl << "RHS Occur   : ";
	for (int i = 0; i < RHSVec.size(); ++i)
		cout << RHSVec[i] << "  ";
	cout << endl << endl;
}

/* Longest Bitonic Subsequence using DP */
int LBS(const vector<int> & numVec)
{
	vector<int> LHSVec(numVec.size(), 1);
	for (int i = 1; i < numVec.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (numVec[j] < numVec[i])
				LHSVec[i] = max(LHSVec[i], 1 + LHSVec[j]);
		}
	}
	vector<int> RHSVec(numVec.size(), 1);
	for (int i = numVec.size() - 2; i >= 0; --i)
	{
		for (int j = numVec.size() - 1; j > i; --j)
		{
			if (numVec[j] < numVec[i])
				RHSVec[i] = max(RHSVec[i], 1 + RHSVec[j]);
		}
	}
	PrintLBSTable(numVec, LHSVec, RHSVec);
	int max = INT_MIN;
	for (int i = 0; i < LHSVec.size(); ++i)
	{
		if (LHSVec[i] + RHSVec[i] > max)
			max = LHSVec[i] + RHSVec[i];
	}
	return max-1; // Since the common number will be included twice
}

/* Main Method */
int main()
{
	vector<int> numVec;
	int numberOfEnteries, entryValue;
	cout << "Enter the number of entries : ";
	cin >> numberOfEnteries;
	for (int i = 0; i < numberOfEnteries; ++i)
	{
		cout << "Enter the value for entry " << i + 1 << " : ";
		cin >> entryValue;
		numVec.push_back(entryValue);
	}
	cout << "The Longest bitonic subsequence is of length : " << LBS(numVec) << endl << endl;
	return 0;
}

/*

Note : Bitonic sequence means which first increases and then decreases

Output

Enter the number of entries : 8
Enter the value for entry 1 : 2
Enter the value for entry 2 : -1
Enter the value for entry 3 : 4
Enter the value for entry 4 : 3
Enter the value for entry 5 : 5
Enter the value for entry 6 : -1
Enter the value for entry 7 : 3
Enter the value for entry 8 : 2

Input Array : 2  -1  4  3  5  -1  3  2
LHS Occur   : 1   1  2  2  3   1  2  2
RHS Occur   : 2   1  3  2  3   1  2  1

The Longest bitonic subsequence is of length : 5

*/
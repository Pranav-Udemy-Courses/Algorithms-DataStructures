#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

/* Print LIS table for understanding */
void PrintLISTable(const vector<int>& numVec, const vector<int>& lisVec)
{
	cout << endl << "Array : ";
	for (int i =0; i < numVec.size(); ++i)
		cout << numVec[i] << "  ";
	cout << endl << "Occur : ";
	for (int i = 0; i < numVec.size(); ++i)
		cout << lisVec[i] << "  ";
	cout << endl << endl;
}

/* Longest Increasing Subsequence using DP */
int LIS(const vector<int>& numVec)
{
	vector<int> lisVec(numVec.size(), 1);
	for (int i = 1; i < numVec.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (numVec[j] < numVec[i])
				lisVec[i] = max(lisVec[i], 1 + lisVec[j]);
		}
	}
	PrintLISTable(numVec, lisVec);
	int max = INT_MIN;
	for (int i = 0; i < lisVec.size(); ++i)
	{
		if (lisVec[i] > max)
			max = lisVec[i];
	}
	return max;
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
	cout << "The Longest common subsequence is of length : " << LIS(numVec) << endl << endl;
	return 0;
}

/*

Output

Enter the number of entries : 11
Enter the value for entry 1 : 5
Enter the value for entry 2 : 6
Enter the value for entry 3 : 2
Enter the value for entry 4 : 3
Enter the value for entry 5 : 4
Enter the value for entry 6 : 1
Enter the value for entry 7 : 9
Enter the value for entry 8 : 9
Enter the value for entry 9 : 8
Enter the value for entry 10 : 9
Enter the value for entry 11 : 5

Array : 5  6  2  3  4  1  9  9  8  9  5
Occur : 1  2  1  2  3  1  4  4  4  5  4

The Longest common subsequence is of length : 5

*/
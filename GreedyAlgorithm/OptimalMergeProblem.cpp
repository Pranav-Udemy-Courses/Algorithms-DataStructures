#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/* Method to retrieve two lowest value elements */
void GetLowerValues(vector<int>& sizesVec, int& first, int& second)
{
	first = sizesVec[0];
	second = INT_MAX;
	for (int i = 1; i < sizesVec.size(); ++i)
	{
		if (sizesVec[i] <= first)
		{
			second = first;
			first = sizesVec[i];
		}
		else if (sizesVec[i] > first&& sizesVec[i] < second)
			second = sizesVec[i];
	}
	sizesVec.erase(remove(sizesVec.begin(), sizesVec.end(), first), sizesVec.end());
	sizesVec.erase(remove(sizesVec.begin(), sizesVec.end(), second), sizesVec.end());
}

/* Method to perform optimal merge */
int OptimalMerge(vector<int>& sizesVec)
{
	int merges = 0;
	int first = 0;
	int second = 0;
	while (sizesVec.size() > 1)
	{
		GetLowerValues(sizesVec, first, second);
		sizesVec.push_back(first + second);
		merges += first + second;
	}
	return merges;
}

/* Main Method */
int main()
{
	vector<int> sizesVec1{ 20,30,10,5,30 };
	cout << "The Optimal Merge Pattern for 20, 30, 10, 5, 30 is : " << OptimalMerge(sizesVec1) << endl;
	vector<int> sizesVec2{ 6,5,2,3 };
	cout << "The Optimal Merge Pattern for 6, 5, 2, 3 is : " << OptimalMerge(sizesVec2) << endl;
	return 0;
}

/*
Output
The Optimal Merge Pattern for 20, 30, 10, 5, 30 is : 205
The Optimal Merge Pattern for 6, 5, 2, 3 is : 31
*/

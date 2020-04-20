#include <iostream>
#include <vector>

using namespace std;

/* Method to find target using BinarySearch */
int BinSearch(vector<int>& nums, int target, int lo, int hi)
{
	if (lo > hi)
		return -1;

	int mid = (lo + hi) / 2;
	if (target == nums[mid])
		return mid;
	if (target < nums[mid])
		return BinSearch(nums, target, lo, mid - 1);
	else if (target > nums[mid])
		return BinSearch(nums, target, lo + 1, hi);
	else
		return -1;
}

/* Method to find the pivot element */
int FindPivot(vector<int> & nums, int target)
{
	if (nums.empty())
		return -1;

	if (nums[0] <= nums[nums.size() - 1])
		return 0;

	int start = 0;
	int end = nums.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (nums[mid] > nums[mid + 1])
			return mid + 1;
		if (nums[start] <= nums[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
}

/* Search wrapper to find the index for given target */
int search(vector<int> & nums, int target)
{
	if (nums.empty())
		return -1;

	int pivot = FindPivot(nums, target);
	if (pivot > 0 && target >= nums[0] && target <= nums[pivot - 1])
	{
		return BinSearch(nums, target, 0, pivot - 1);
	}
	else
	{
		return BinSearch(nums, target, pivot, nums.size() - 1);
	}
}

/* Main Method */
int main()
{
	vector<int> nums{ 4,5,6,7,0,1,2 };
	cout << "The input list is as follows : 4 5 6 7 0 1 2" << endl;
	cout << "The index for target = 0 is : " << search(nums, 0) << endl;
	cout << "The index for target = 5 is : " << search(nums, 5) << endl;
	cout << "The index for target = 9 is : " << search(nums, 9) << endl;
	return 0;
}

/* 
Output

The input list is as follows : 4 5 6 7 0 1 2
The index for target = 0 is : 4
The index for target = 5 is : 1
The index for target = 9 is : -1

*/

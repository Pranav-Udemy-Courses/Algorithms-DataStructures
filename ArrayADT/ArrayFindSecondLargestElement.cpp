#include <iostream>

using namespace std;

// Find the Second Largest Element of an Array
void SecondLargest(int arr[], int size)
{
	if (size < 2)
	{
		cout << "Array of atleast size two is needed" << endl;
		return;
	}

	int first=INT_MIN, second=INT_MIN;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > second)
		{
			first = second;
			second = arr[i];
		}
		else if (arr[i] > first && arr[i] != second)
			first = arr[i];
	}
	if (first == INT_MIN)
		cout << "No Second Largest Element present" << endl;
	else
		cout << "The Second Largest Element is : " << first << endl;
}

// Main Method
int main()
{
	int arr[] = { 12, 35, 1, 10, 34, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	SecondLargest(arr, n);
	return 0;
}

/*

Output

The Second Largest Element is : 34

*/

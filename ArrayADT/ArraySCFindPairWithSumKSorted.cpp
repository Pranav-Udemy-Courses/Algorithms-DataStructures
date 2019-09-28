#include <iostream>  

using namespace std;

/* Data Structure of Array*/
struct Array
{
	int p[10]; // An array created in Stack section of the Main memory  
	int size; // Tells size of array  
	int length; // Tells how many elements are currently there inside array  
};

/* Display elements of Array*/
void Display(Array arr)
{
	cout << "Printing array elements : " << endl;
	for (int m = 0; m < arr.length; ++m)
	{
		cout << arr.p[m] << "   ";
	}
	cout << endl;
}

/* Finding pairs with sum k for sorted array */
void FindPairSorted(Array arr, int k)
{
	cout << "Printing the pairs with sum k for sorted array " << endl;
	int i = 0, j = arr.length - 1;
	while (i < j)
	{
		if (arr.p[i] + arr.p[j] > k)
			j--;
		else if (arr.p[i] + arr.p[j] < k)
			i++;
		else
		{
			cout << arr.p[i] << " + " << arr.p[j] << " = " << k << endl;
			i++;
			j--;
		}
	}
}

int main()
{
	Array arr1 = { {1,3,4,5,6,8,9,10,12,14}, 10, 10 };
	Display(arr1);
	int k;
	cout << "Enter the value of sum k : ";
	cin >> k;
	FindPairSorted(arr1, k);
	system("pause");
	return 0;
}

/*
Output
Printing array elements :
1   3   4   5   6   8   9   10   12   14
Enter the value of sum k : 15
Printing the pairs with sum k for sorted array
1 + 14 = 15
3 + 12 = 15
5 + 10 = 15
6 + 9 = 15
*/
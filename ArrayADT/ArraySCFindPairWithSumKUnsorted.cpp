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

/* Gets the maximum element of Array*/
int GetMax(Array arr)
{
	int max = arr.p[0];
	for (int i = 1; i < arr.length; ++i)
	{
		if (arr.p[i] > max)
			max = arr.p[i];
	}
	return max;
}

/* Finding pairs with sum k using Traditional method */
void FindPairTraditional(Array arr, int k)
{
	cout << "Printing the pairs using traditional method " << endl;
	for (int i = 0; i < arr.length - 1; ++i)
	{
		for (int j = i + 1; j < arr.length; ++j)
		{
			if (arr.p[i] + arr.p[j] == k)
			{
				cout << arr.p[i] << " + " << arr.p[j] << " = " << k << endl;
			}
		}
	}
}

/* Finding pairs with sum k using Hashing method */
void FindPairHashing(Array arr, int k)
{
	int size = GetMax(arr) + 1;
	int* hashArray = new int[size] {0};
	cout << "Printing the pairs using hashing method " << endl;
	for (int i = 0; i < arr.length; ++i)
	{
		if (arr.p[i] >= k)continue;
		if(hashArray[k-arr.p[i]] > 0)
			cout << arr.p[i] << " + " << k - arr.p[i] << " = " << k << endl;
		hashArray[arr.p[i]]++;
	}
}

int main()
{
	Array arr1 = { {6,3,8,10,16,7,5,2,9,14}, 10, 10 };
	Display(arr1);
	int k;
	cout << "Enter the value of sum k : ";
	cin >> k;
	FindPairTraditional(arr1, k);
	FindPairHashing(arr1, k);
	system("pause");
	return 0;
}

/*
Output
Printing array elements :
6   3   8   10   16   7   5   2   9   14
Enter the value of sum k : 10
Printing the pairs using traditional method
3 + 7 = 10
8 + 2 = 10
Printing the pairs using hashing method
7 + 3 = 10
2 + 8 = 10
*/
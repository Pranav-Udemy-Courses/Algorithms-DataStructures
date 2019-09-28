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

/* Find duplicates and their count in unsorted array using traditional method */
void DuplicateUnsortedTrad(Array arr)
{
	cout << "The duplicate elements using traditional method are :" << endl;
	for (int i = 0; i < arr.length; ++i)
	{
		int count = 1;
		if (arr.p[i] != -1)
		{
			for (int j = i + 1; j < arr.length; ++j)
			{
				if (arr.p[i] == arr.p[j])
				{
					count++;
					arr.p[j] = -1;
				}
			}
		}
		if (count > 1)
			cout << "The number " << arr.p[i] << " is repeated " << count << " times" << endl;
	}

}

/* Find duplicates and their count in unsorted array using hashing */
void DuplicatesUnsortedHashing(Array arr)
{
	cout << "The duplicate elements using Hashing method are :" << endl;
	int size = GetMax(arr) + 1;
	int* hashArray = new int[size] {0};
	for (int i = 0; i < arr.length; ++i)
	{
		hashArray[arr.p[i]]++;
	}

	for (int i = 1; i < size; ++i)
	{
		if(hashArray[i]>1)
			cout << "The number " << i << " is repeated " << hashArray[i] << " times" << endl;
	}
	delete[] hashArray;
}

int main()
{
	Array arr1 = { {4,7,2,1,1,7,7,4}, 10, 8 };
	Display(arr1);
	DuplicateUnsortedTrad(arr1);
	DuplicatesUnsortedHashing(arr1);
	system("pause");
	return 0;
}

/*
Output
Printing array elements :
4   7   2   1   1   7   7   4
The duplicate elements using traditional method are :
The number 4 is repeated 2 times
The number 7 is repeated 3 times
The number 1 is repeated 2 times
The duplicate elements using Hashing method are :
The number 1 is repeated 2 times
The number 4 is repeated 2 times
The number 7 is repeated 3 times
*/
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
		cout << arr.p[m] << endl;
	}
}



/* Finds duplicate elements and its count in an array */
void DuplicateElementsHashing(Array arr1)
{
	int lastElement = arr1.p[arr1.length - 1];
	int* hashArray = new int[lastElement + 1]{0};
	cout << "The Duplicate elements are : " << endl;
	for (int i = 0; i < arr1.length; ++i)
	{
		hashArray[arr1.p[i]]++;
	}
	for (int i = 1; i < lastElement+1; ++i)
	{
		if (hashArray[i] > 1)
		{
			cout << "The number " << i << " is repeated " << hashArray[i] << " times " << endl;
		}
	}
}

int main()
{
	Array arr1 = { {1,2,2,3,4,5,5,5}, 10, 8 };
	Display(arr1);
	DuplicateElementsHashing(arr1);
	system("pause");
	return 0;
}

/*
Output
Printing array elements :
1
2
2
3
4
5
5
5
The Duplicate elements are :
The number 2 is repeated 2 times
The number 5 is repeated 3 times
*/
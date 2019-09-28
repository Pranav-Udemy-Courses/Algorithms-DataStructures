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
void DuplicateElements(Array arr1)
{
	
	cout << "The Duplicate elements are : " << endl;
	for (int i = 0; i < arr1.length - 1; ++i)
	{
		if (arr1.p[i] == arr1.p[i + 1])
		{
			int j = i + 1;
			while (arr1.p[j] == arr1.p[i])j++;
			cout << arr1.p[i] << " is repeated " << j-i << " times " << endl;
			i = j - 1;
		}
	}
}

int main()
{
	Array arr1 = { {1,2,2,3,4,5,5,5}, 10, 8 };
	Display(arr1);
	DuplicateElements(arr1);
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
2 is repeated 2 times
5 is repeated 3 times
*/
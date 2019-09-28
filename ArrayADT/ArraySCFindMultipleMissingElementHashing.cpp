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

int GetMaximum(Array arr)
{
	int max = arr.p[0];
	for (int i = 1; i < arr.length; ++i)
	{
		if (arr.p[i] > max)
			max = arr.p[i];
	}
	return max;
}

/* Finds multiple missing elements in an array */
void MissingElementUsingHash(Array arr1)
{
	const int max = GetMaximum(arr1);
	int* hashArr = new int[max+1] {0};
	for (int i = 0; i < arr1.length; ++i)
	{
		hashArr[arr1.p[i]]++;
	}
	cout << "The missing elements are : ";
	for (int i = 1; i <= max; ++i)
	{
		if (hashArr[i] == 0)
			cout << i << "  ";
	}
	cout << endl;
	delete[] hashArr;
}

int main()
{
	Array arr1 = { {1,2,3,5,6,9}, 10, 6 };
	Display(arr1);
	MissingElementUsingHash(arr1);
	system("pause");
	return 0;
}

/*
Output
Printing array elements :
1
2
3
5
6
9
The missing elements are : 4  7  8
*/
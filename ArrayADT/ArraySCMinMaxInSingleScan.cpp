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

/* Finds min and max in an array */
void FindMinMax(Array arr)
{
	int min=arr.p[0], max = arr.p[0];
	for (int i = 1; i < arr.length; ++i)
	{
		if (arr.p[i] < min)
			min = arr.p[i];
		else if (arr.p[i] > max)
			max = arr.p[i];
	}
	cout << "Mininum is : " << min << endl;
	cout << "Maximum is : " << max << endl;
}

int main()
{
	Array arr1 = { {5,8,3,9,6,10,7,-1,4}, 10, 9 };
	Display(arr1);
	FindMinMax(arr1);
	system("pause");
	return 0;
}

/*
Output
Printing array elements :
5   8   3   9   6   10   7   -1   4
Mininum is : -1
Maximum is : 10
*/
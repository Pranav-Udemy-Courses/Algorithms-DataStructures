#include <iostream>

using namespace std;

/*-------------------------------------
   Display list
   Complexity : O(n)
-------------------------------------*/
void Display(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << "   ";
	}
	cout << endl << endl;
}

/*-----------------------------------------
   Sort the elements using Insertion Sort
   Complexity : O(n) best case
				O(n^2) worst case
-----------------------------------------*/
void InsertionSort(int a[], int size)
{
	cout << "The list prior sorting : ";
	Display(a, size);
	for (int i = 1; i < size; ++i)
	{
		int j = i - 1, x = a[i];
		while (j > -1 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
	cout << "The list after sorting : ";
	Display(a, size);
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int a[]{ 8,5,7,3,2 };
	InsertionSort(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
}

/*
Output

The list prior sorting : 8   5   7   3   2

The list after sorting : 2   3   5   7   8

*/

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

/*-------------------------------------
   Swap the elements
   Complexity : O(1)
-------------------------------------*/
void Swap(int* n1, int* n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/*-------------------------------------
   Sort the elements using Selection Sort
   Complexity : O(n^2) worst case
-------------------------------------*/
void SelectionSort(int a[], int size)
{
	cout << "The list prior sorting : ";
	Display(a, size);
	for (int i = 0; i < size - 1; ++i)
	{
		int k = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (a[j] < a[k])
				k = j;
		}
		Swap(&a[i], &a[k]);
	}
	cout << "The list after sorting : ";
	Display(a, size);
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int a[]{ 8,5,7,3,2,9 };
	SelectionSort(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
}

/*
Output

The list prior sorting : 8   5   7   3   2   9

The list after sorting : 2   3   5   7   8   9

*/

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
   Sort the elements using Bubble Sort
   Complexity : O(n) best case
				O(n^2) worst case
-------------------------------------*/
void BubbleSort(int a[], int size)
{
	cout << "The list prior sorting : ";
	Display(a, size);
	for (int i = 0; i < size - 1; ++i)
	{
		bool flag = false;
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = true;
			}
		}
		if (!flag)break;
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
	BubbleSort(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
}

/*
Output

The list prior sorting : 8   5   7   3   2

The list after sorting : 2   3   5   7   8

*/

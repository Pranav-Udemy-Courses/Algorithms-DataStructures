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
   Sort the elements using Shell Sort
   Complexity : O(n*log(n))
-----------------------------------------*/
void ShellSort(int a[], int size)
{
	cout << "The list prior sorting : ";
	Display(a, size);
	int gap, i, j;
	for (gap = size / 2; gap >= 1; gap /= 2)
	{
		for (i = gap; i < size; ++i)
		{
			int temp = a[i];
			j = i - gap;
			while (j >= 0 && a[j] > temp)
			{
				a[j + gap] = a[j];
				j = j - gap;
			}
			a[j + gap] = temp;
		}
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
	ShellSort(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
}

/*
Output

The list prior sorting : 8   5   7   3   2

The list after sorting : 2   3   5   7   8

*/

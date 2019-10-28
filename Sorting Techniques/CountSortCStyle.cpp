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
   Get Maximum Element
   Complexity : O(n)
-------------------------------------*/
int GetMax(int a[], int size)
{
	int max = INT32_MIN;
	for (int i = 0; i < size; ++i)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

/*-----------------------------------------
   Sort the elements using Count Sort
   Complexity : O(n) best case
-----------------------------------------*/
void CountSort(int a[], int size)
{
	cout << "The list prior sorting : ";
	Display(a, size);
	int maxElement = GetMax(a, size) + 1;
	int* p = new int[maxElement] {0};
	for (int i = 0; i < size; ++i)
		p[a[i]]++;
	int i = 0, j = 0;
	while (j < size)
	{
		if (p[i] > 0)
		{
			a[j++] = i;
			p[i]--;
		}
		else
			i++;
	}
	cout << "The list after sorting : ";
	Display(a, size);
	delete p;
	p = nullptr;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int a[]{ 8,5,7,3,2,8,5,3,3,8,8 };
	CountSort(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
}

/*
Output

The list prior sorting : 8   5   7   3   2   8   5   3   3   8   8

The list after sorting : 2   3   3   3   5   5   7   8   8   8   8

*/

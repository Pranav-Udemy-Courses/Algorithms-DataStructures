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
   Sort the elements using Quick Sort
   Complexity : O(log(n)) best case
		O(n^2) worst case
-------------------------------------*/
int Partition(int a[], int l, int h)
{
	int i = l;
	int j = h;
	int pivot = a[l];

	do
	{
		do
		{
			++i;
		} while (a[i] <= pivot);
		do
		{
			--j;
		} while (a[j] > pivot);
		if (i < j)
			Swap(&a[i], &a[j]);
	} while (i < j);
	Swap(&a[l], &a[j]);
	return j;
}

void QuickSort(int a[], int l, int h)
{
	int j = 0;
	if (l < h)
	{
		j = Partition(a, l, h);
		QuickSort(a, l, j);
		QuickSort(a, j + 1, h);
	}
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int a[]{ 8,5,7,3,2,9,INT32_MAX };
	cout << "List prior sorting : ";
	Display(a, (sizeof(a) / sizeof(int)) - 1);
	QuickSort(a, 0, 5);
	cout << "List after sorting : ";
	Display(a, (sizeof(a) / sizeof(int)) - 1);
	system("pause");
	return 0;
}

/*
Output

List prior sorting : 8   5   7   3   2   9

List after sorting : 2   3   5   7   8   9

*/

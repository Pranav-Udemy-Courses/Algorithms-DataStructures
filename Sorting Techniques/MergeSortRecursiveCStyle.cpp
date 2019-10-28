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
   Merge the elements
   Complexity : O(n)
-------------------------------------*/
void Merge(int a[], int low, int mid, int hi)
{
	int i = low, j = mid + 1, k = 0;
	int b[100];

	while (i <= mid && j <= hi)
	{
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= hi)
		b[k++] = a[j++];
	k = 0;
	for (int l = low; l <= hi; l++)
		a[l] = b[k++];
}

/*------------------------------------------------
   Sort the elements using Merge Sort Recursively
   Complexity : O(n*log(n))
------------------------------------------------*/
void MergeSortRec(int a[], int lo, int hi)
{
	if (lo < hi)
	{
		int mid = (lo + hi) / 2;
		MergeSortRec(a, lo, mid);
		MergeSortRec(a, mid + 1, hi);
		Merge(a, lo, mid, hi);
	}
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int a[]{ 8,5,7,3,2,9 };
	int size = sizeof(a) / sizeof(int);
	cout << "The list prior sorting : ";
	Display(a, size);
	MergeSortRec(a, 0, size - 1);
	cout << "The list after using Merge Sort Recursive for sorting : ";
	Display(a, size);
	system("pause");
	return 0;
}

/*
Output

The list prior sorting : 8   5   7   3   2   9

The list after using Merge Sort Recursive for sorting : 2   3   5   7   8   9

*/

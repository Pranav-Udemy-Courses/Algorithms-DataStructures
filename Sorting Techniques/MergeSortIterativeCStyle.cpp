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
   Sort the elements using Merge Sort Iteratively
   Complexity : O(n*log(n))
------------------------------------------------*/
void MergeSortItr(int a[], int size)
{
	cout << "The list prior sorting : ";
	Display(a, size);
	int p, l, h, mid, i;
	for (p = 2; p <= size; p *= 2)
	{
		for (i = 0; i + p - 1 <= size; i = i + p)
		{
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			Merge(a, l, mid, h);
		}
	}
	if (p / 2 < size)
		Merge(a, 0, (p / 2) - 1, size);
	cout << "The list after using Merge Sort Iterative for sorting : ";
	Display(a, size);
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int a[]{ 8,5,7,3,2,9 };
	MergeSortItr(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
}

/*
Output

The list prior sorting : 8   5   7   3   2   9

The list after using Merge Sort Iterative for sorting : 2   3   5   7   8   9

*/

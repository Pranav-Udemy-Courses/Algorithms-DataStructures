#include <iostream>

using namespace std;

/*-------------------------------------
   Create a Max Heap Using Heapify
   Complexity : O(n)
-------------------------------------*/
void Heapify(int a[], int size)
{
	for (int i = size - 1; i > 0; --i)
	{
		int j = i * 2;
		while (j <= size - 2)
		{
			if (a[j + 1] > a[j])
				j = j + 1;
			if (a[j] > a[i])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				i = j;
				j = j * 2;
			}
			else
				break;
		}
	}
}

/*-------------------------------------
   Create a Max Heap
   Complexity : O(log(n))
-------------------------------------*/
void InsertInHeap(int a[], int n)
{
	int temp = a[n];
	while (n > 1 && temp > a[n / 2])
	{
		a[n] = a[n / 2];
		n = n / 2;
	}
	a[n] = temp;
}

/*-------------------------------------
   Delete Max Element from Array
   Complexity : O(log(n))
-------------------------------------*/
void DeleteFromHeap(int a[], int n)
{
	int i = 1;
	int j = i * 2;
	int x = a[1];
	a[1] = a[n];
	while (j < n - 1)
	{
		if (a[j + 1] > a[j])
			j++;
		if (a[j] > a[i])
		{
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i = j;
			j = j * 2;
		}
		else
			break;
	}
	a[n] = x;
}


/*-------------------------------------
   Heap Sort the Elements of Array
   Complexity : O(log(n))
-------------------------------------*/
void HeapSort(int a[], int size)
{
	cout << "The list prior sorting : ";
	for (int i = 1; i < size; ++i)
		cout << a[i] << " ";
	cout << endl;

	for (int i = 2; i < size; ++i)
	{
		InsertInHeap(a, i);
	}

	for (int i = size - 1; i > 1; i--)
	{
		DeleteFromHeap(a, i);
	}

	cout << "The list after sorting : ";
	for (int i = 1; i < size; ++i)
		cout << a[i] << " ";
	cout << endl;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int a[]{ 0,10,20,30,25,5,40,35 };
	Heapify(a, 8);
	cout << "The Heapified list is : ";
	for (int i = 1; i < 8; ++i)
		cout << a[i] << "  ";
	cout << endl;
	system("pause");
	return 0;
}

/*
Output
The Heapified list is : 40  25  35  20  5  30  10
*/

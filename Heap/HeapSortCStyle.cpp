#include <iostream>

using namespace std;

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
   Complexity : O(nlog(n))
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
	HeapSort(a, 8);
	system("pause");
	return 0;
}

/*
Output
The list prior sorting : 10 20 30 25 5 40 35
The list after sorting : 5 10 20 25 30 35 40
*/

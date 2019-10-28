#include <iostream>

using namespace std;

/*-------------------------------------
	Structure of Node
-------------------------------------*/
typedef struct Node_t
{
	int data;
	Node_t* next;
}Node_s;

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

/*-------------------------------------
   Insert in the Beginning of Node
   Complexity : O(1)
-------------------------------------*/
Node_s* Insert(Node_s* head, int value)
{
	Node_s* temp = new Node_s;
	temp->next = head;
	temp->data = value;
	head = temp;
	return head;
}

/*-------------------------------------
   Delete from the Beginning of Node
   Complexity : O(1)
-------------------------------------*/
Node_s* Delete(Node_s* head)
{
	if (head == nullptr)
		return nullptr;
	Node_s* temp = head;
	head = head->next;
	delete temp;
	return head;
}

/*-----------------------------------------
   Sort the elements using Bin/Bucket Sort
   Complexity : O(n) best case
-----------------------------------------*/
void BinSort(int a[], int size)
{
	cout << "The list prior sorting : ";
	Display(a, size);
	int maxElement = GetMax(a, size) + 1;
	Node_s** p = new Node_s * [maxElement] {nullptr};
	for (int i = 0; i < size; ++i)
	{
		p[a[i]] = Insert(p[a[i]], a[i]);
	}
	int i = 0, j = 0;
	while (j < size)
	{
		if (p[i] != nullptr)
		{
			a[j++] = p[i]->data;
			p[i] = Delete(p[i]);
		}
		else
			i++;
	}
	cout << "The list after Bucket sort is : ";
	Display(a, size);
	for (int i = 0; i < maxElement; ++i)
		delete p[i];
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int a[]{ 8,5,7,3,2,8,5,3,3,8,8 };
	BinSort(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
}

/*
Output

The list prior sorting : 8   5   7   3   2   8   5   3   3   8   8

The list after Bucket/Bin sort is : 2   3   3   3   5   5   7   8   8   8   8

*/

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
   Get Digits of Maximum Element
   Complexity : O(n)
-------------------------------------*/
int GetMaxDigits(int a[], int size)
{
	int max = INT32_MIN;
	for (int i = 0; i < size; ++i)
	{
		if (a[i] > max)
			max = a[i];
	}
	int digit = 1;
	while (max / 10 != 0)
	{
		max /= 10;
		digit++;
	}
	return digit;
}

/*-------------------------------------
   Insert in the Beginning of Node
   Complexity : O(1)
-------------------------------------*/
Node_s* Insert(Node_s* head, int value)
{
	if (head == nullptr)
	{
		Node_s* temp = new Node_s;
		temp->next = head;
		temp->data = value;
		head = temp;
		return head;
	}
	Node_s* t = head;
	while (head->next != nullptr)
		head = head->next;

	Node_s* temp = new Node_s;
	temp->next = nullptr;
	temp->data = value;
	head->next = temp;
	return t;
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
   Sort the elements using Radix Sort
   Complexity : O(n) best case
-----------------------------------------*/
void RadixSort(int a[], int size)
{
	cout << "The list prior sorting : ";
	Display(a, size);
	int maxDigit = GetMaxDigits(a, size);
	Node_s** p = new Node_s * [10]{ nullptr };
	int div = 1;
	while (maxDigit != 0)
	{
		for (int i = 0; i < size; ++i)
		{
			int pos = (a[i] / div) % 10;
			p[pos] = Insert(p[pos], a[i]);
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
		div *= 10;
		maxDigit--;
	}
	cout << "The list after Radix sort is : ";
	Display(a, size);
	for (int i = 0; i < 10; ++i)
		delete p[i];
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int a[]{ 8,1455,7,3,2,8,55,3,3,138,8 };
	RadixSort(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
}

/*
Output

The list prior sorting : 8   1455   7   3   2   8   55   3   3   138   8

The list after Radix sort is : 2   3   3   3   7   8   8   8   55   138   1455

*/

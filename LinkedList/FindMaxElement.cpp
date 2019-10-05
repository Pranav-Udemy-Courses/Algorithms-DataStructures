#include <iostream>

using namespace std;

/* Structure of Node */
typedef struct Node_t
{
	int data;  // Data to be stored
	Node_t* next;  // Pointer to the next node
}Node_s;

// Global Variable Node_s*
Node_s* head = nullptr;

/* Create a linked list */
void Create(int a[], int len)
{
	Node_s* t, * last;
	head = new Node_s;
	head->data = a[0];
	head->next = nullptr;
	last = head;

	for (int i = 1; i < len; ++i)
	{
		t = new Node_s;
		t->data = a[i];
		t->next = nullptr;
		last->next = t;
		last = last->next;
	}
}

/* Display the linked list */
void Display()
{
	Node_s* temp = head;
	while (temp != nullptr)
	{
		cout << "| " << temp->data << " | " << temp->next << " | -------> ";
		temp = temp->next;
	}
	cout << endl;
}

/* Find Maximum Element in a linked list */
int FindMax(Node_s* temp)
{
	int max = INT_MIN;
	while (temp != nullptr)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	return max;
}

/* Find Maximum Element in a linked list recursively */
int FindMaxRec(Node_s* temp)
{
	static int max = INT_MIN;
	if (temp != nullptr)
	{
		if (temp->data > max)
			max = temp->data;
		return FindMaxRec(temp->next);
	}
	return max;
}

/* Find Maximum Element in a linked list recursively without static variable */
int FindMaxRecNew(Node_s* temp)
{
	int x;
	if (temp == nullptr)
		return INT_MIN;
	x = FindMaxRecNew(temp->next);
	return x > temp->data ? x : temp->data;
}

/* Main Method */
int main()
{
	int a[]{ 2,11,5,7,9 };
	Create(a, 5);
	cout << "Display using loop : ";
	Display();
	cout << "The maximum element using loop is : " << FindMax(head) << endl;
	cout << "The maximum element using recursion and static variable is : " << FindMaxRec(head) << endl;
	cout << "The maximum element using recursion without static variable is : " << FindMaxRecNew(head) << endl;
	system("pause");
	return 0;
}

/*
Output
Display using loop : | 2 | 00A8DEF0 | -------> | 11 | 00A8DCC0 | -------> | 5 | 00A8DFD0 | -------> | 7 | 00A8DE10 | -------> | 9 | 00000000 | ------->
The maximum element using loop is : 11
The maximum element using recursion and static variable is : 11
The maximum element using recursion without static variable is : 11
*/

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

/* Display Linked list recursively using Tail Recursion */
void DisplayRec(Node_s* temp)
{
	if (temp != nullptr)
	{
		cout << "| " << temp->data << " | " << temp->next << " | -------> ";
		DisplayRec(temp->next);
	}
}

/* Display Reversed Linked list recursively using Head Recursion */
void DisplayReverseRec(Node_s* temp)
{
	if (temp != nullptr)
	{
		DisplayReverseRec(temp->next);
		cout << "| " << temp->next << " | " << temp->data << " | <------- ";
	}
}

/* Main Method */
int main()
{
	int a[]{ 2,5,7,9 };
	Create(a, 4);
	cout << "Display using loop : ";
	Display();
	cout << "Display using recursion : ";
	DisplayRec(head);
	cout << endl;
	cout << "Reverse display using recursion : ";
	DisplayReverseRec(head);
	cout << endl;
	system("pause");
	return 0;
}

/*
Output
Display using loop : | 2 | 0104DAB8 | -------> | 5 | 0104DC40 | -------> | 7 | 0104DAF0 | -------> | 9 | 00000000 | ------->
Display using recursion : | 2 | 0104DAB8 | -------> | 5 | 0104DC40 | -------> | 7 | 0104DAF0 | -------> | 9 | 00000000 | ------->
Reverse display using recursion : | 00000000 | 9 | <------- | 0104DAF0 | 7 | <------- | 0104DC40 | 5 | <------- | 0104DAB8 | 2 | <-------
*/
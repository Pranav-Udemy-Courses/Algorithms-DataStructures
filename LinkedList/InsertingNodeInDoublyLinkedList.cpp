#include <iostream>

using namespace std;

/* Structure of Node */
typedef struct Node_t
{
	Node_t* prev;  // Pointer to the previous node
	int data; // Data to be stored
	Node_t* next;  // Pointer to the next node
}Node_s;

/* Global pointer */
Node_s* head = nullptr;

/* Display a Doubly Linked List */
void Display(Node_s* start)
{
	if (start == nullptr)
		return;
	Node_s* temp = start;
	while (temp != nullptr)
	{
		cout << " | " << temp->prev << " | " << temp->data << " | " << temp->next << " | -------> ";
		temp = temp->next;
	}
	cout << endl;
}

/* Find the Length of Doubly Linked List */
int Length(Node_s* start)
{
	if (start == nullptr)
		return 0;
	int count = 1;
	while (start->next != nullptr)
	{
		count++;
		start = start->next;
	}
	return count;
}

/* Insert a Node at Beginning of Doubly Linked List */
void InsertAtBeginning(Node_s* start, int x)
{
	Node_s* t = new Node_s;
	t->data = x;
	t->prev = nullptr;
	t->next = head;
	if (head == nullptr)
	{
		head = t;
		return;
	}
	else
	{
		head->prev = t;
		head = t;
	}
}

/* Insert a Node at any given Index of Doubly Linked List */
void InsertAtIndex(Node_s* start, int x, int index)
{
	if (index < 0 || index > Length(start))
		return;
	if (index == 0 || start == nullptr)
	{
		InsertAtBeginning(start, x);
		return;
	}

	for (int i = 0; i <= index - 2; ++i)
	{
		start = start->next;
	}

	Node_s* t = new Node_s;
	t->data = x;
	t->next = start->next;
	t->prev = start;
	if (start->next != nullptr)
		start->next->prev = t;
	start->next = t;
}

/* Main Method */
int main()
{
	InsertAtIndex(head, 3, 0);
	InsertAtIndex(head, 1, 0);
	InsertAtIndex(head, 5, 2);
	InsertAtIndex(head, 9, 3);
	InsertAtIndex(head, 7, 3);
	cout << "Displaying Doubly Linked List : ";
	Display(head);
	cout << endl;
	cout << "The Length of Doubly Linked List is : " << Length(head) << endl << endl;
	system("pause");
	return 0;
}

/*
Output

Displaying Doubly Linked List :  | 00000000 | 1 | 0164DC30 | ------->  | 0164DB18 | 3 | 0164DD10 | ------->  | 0164DC30 | 5 | 0164DD80 | ------->  | 0164DD10 | 7 | 0164D798 | ------->  | 0164DD80 | 9 | 00000000 | ------->

The Length of Doubly Linked List is : 5

*/
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

/* Deleting a node at Beginning of Doubly Linked List */
int DeleteAtBeginning(Node_s* start)
{
	if (start == nullptr)
		return -1;
	Node_s* nodeToDelete = head;
	head = head->next;
	int nodeValue = nodeToDelete->data;
	delete nodeToDelete;
	nodeToDelete = nullptr;
	if (head != nullptr)
		head->prev = nullptr;
	return nodeValue;
}

/* Deleting a node at any given Index of Doubly Linked List */
int DeleteAtIndex(Node_s* start, int index)
{
	if (start == nullptr || index < 0 || index > Length(start))
		return -1;
	if (index == 0)
		return DeleteAtBeginning(start);
	for (int i = 0; i <= index - 2; ++i)
	{
		start = start->next;
	}
	Node_s* nodeToDelete = start->next;
	if (nodeToDelete->next != nullptr)
	{
		start->next = nodeToDelete->next;
		nodeToDelete->next->prev = start;
	}
	else
	{
		start->next = nullptr;
	}
	int nodeValue = nodeToDelete->data;
	delete nodeToDelete;
	nodeToDelete = nullptr;
	return nodeValue;
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
	int value = DeleteAtIndex(head, 3);
	cout << "Displaying Modified Doubly Linked List : ";
	Display(head);
	cout << endl;
	cout << "The Length of Doubly Linked List is : " << Length(head) << endl << endl;
	cout << "The Deleted Node at index 3 of Doubly Linked List is : " << value << endl << endl;
	system("pause");
	return 0;
}

/*
Output

Displaying Doubly Linked List :  | 00000000 | 1 | 003EDDA0 | ------->  | 003EDE48 | 3 | 003EDC88 | ------->  | 003EDDA0 | 5 | 003EDF98 | ------->  | 003EDC88 | 7 | 003EDE80 | ------->  | 003EDF98 | 9 | 00000000 | ------->

The Length of Doubly Linked List is : 5

Displaying Modified Doubly Linked List :  | 00000000 | 1 | 003EDDA0 | ------->  | 003EDE48 | 3 | 003EDC88 | ------->  | 003EDDA0 | 5 | 003EDE80 | ------->  | 003EDC88 | 9 | 00000000 | ------->

The Length of Doubly Linked List is : 4

The Deleted Node at index 3 of Doubly Linked List is : 7

*/
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

/* Create a Circularly Doubly Linked List */
void Create(int A[], int len)
{
	if (len == 0)
		return;

	Node_s* last = head;
	Node_s* t = new Node_s;
	t->prev = t;
	t->data = A[0];
	t->next = t;
	last = head = t;

	for (int i = 1; i < len; ++i)
	{
		t = new Node_s;
		t->next = head;
		t->prev = last;
		t->data = A[i];
		last->next = t;
		last = last->next;
	}
	head->prev = t; // Or head->prev = last
}

void Reverse(Node_s* start)
{
	if (start == nullptr)
		return;
	Node_s* temp = nullptr;
	do
	{
		temp = start->next;
		start->next = start->prev;
		start->prev = temp;
		start = temp;
	} while (start != head);
	head = head->next;
}

/* Display a Doubly Circular Linked List */
void Display(Node_s* start)
{
	if (start == nullptr)
		return;
	Node_s* temp = start;
	do
	{
		cout << " | " << temp->prev << " | " << temp->data << " | " << temp->next << " | -------> ";
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}

/* Main Method */
int main()
{
	int A[]{ 3,5,7,9 };
	Create(A, 4);
	cout << endl << "Displaying Doubly Circular Linked List : ";
	Display(head);
	cout << endl;
	cout << endl << "Displaying Reversed Doubly Circular Linked List : ";
	Reverse(head);
	Display(head);
	cout << endl;
	system("pause");
	return 0;
}

/*
Output

Displaying Doubly Circular Linked List :  | 012E5DF0 | 3 | 012E5798 | ------->  | 012E5920 | 5 | 012E5E28 | ------->  | 012E5798 | 7 | 012E5DF0 | ------->  | 012E5E28 | 9 | 012E5920 | ------->

Displaying Reversed Doubly Circular Linked List :  | 012E5920 | 9 | 012E5E28 | ------->  | 012E5DF0 | 7 | 012E5798 | ------->  | 012E5E28 | 5 | 012E5920 | ------->  | 012E5798 | 3 | 012E5DF0 | ------->

*/
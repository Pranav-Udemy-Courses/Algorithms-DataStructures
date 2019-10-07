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

/* Create a Doubly Linked List */
void Create(int a[], int len)
{
	if (len < 1)
		return;
	head = new Node_s;
	head->prev = nullptr;
	head->data = a[0];
	head->next = nullptr;
	Node_s* last = head;

	for (int i = 1; i < len; ++i)
	{
		Node_s* temp = new Node_s;
		temp->data = a[i];
		temp->prev = last;
		temp->next = last->next;
		last->next = temp;
		last = last->next;
	}
}

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

/* Main Method */
int main()
{
	int a[]{ 3,5,7,9 };
	Create(a, 4);
	cout << "Displaying Doubly Linked List : ";
	Display(head);
	cout << endl;
	cout << "The Length of Doubly Linked List is : " << Length(head) << endl << endl;
	system("pause");
	return 0;
}

/*
Output

Displaying Doubly Linked List :  | 00000000 | 3 | 0019E1A8 | ------->  | 0019DDB8 | 5 | 0019E090 | ------->  | 0019E1A8 | 7 | 0019DCD8 | ------->  | 0019E090 | 9 | 00000000 | ------->

The Length of Doubly Linked List is : 4

*/
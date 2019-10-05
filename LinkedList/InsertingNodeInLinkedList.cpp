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

/* Insert a node at the Beginning of Linked List */
Node_s* InsertAtBeginning(Node_s* temp, int x)
{
	Node_s* newNode = new Node_s;
	newNode->data = x;
	newNode->next = head;
	head = newNode;
	return head;
}

/* Insert a node at the end of Linked List */
Node_s* InsertAtEnd(Node_s* temp, int x)
{
	if (temp == nullptr)
		return InsertAtBeginning(temp, x);

	while (temp->next != nullptr)
		temp = temp->next;
	Node_s* newNode = new Node_s;
	newNode->data = x;
	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}

/* Insert node at any given index */
Node_s* InsertAtIndex(Node_s* temp, int x, int index)
{
	if (index == 0)
		return InsertAtBeginning(temp, x);
	for (int i = 0; i <= index - 2; ++i)
		temp = temp->next;
	Node_s* newNode = new Node_s;
	newNode->data = x;
	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}

/* Main Method */
int main()
{
	int a[]{ 2,11,5,7,9 };
	Create(a, 5);
	cout << "Display original linked list : ";
	Display();
	cout << endl;
	cout << "Display after inserting at 4th index i.e. after 7 : ";
	InsertAtIndex(head, 8, 4);
	Display();
	cout << endl;
	cout << "Display after inserting node at beginning : ";
	InsertAtBeginning(head, 6);
	Display();
	cout << endl;
	cout << "Display after inserting node at end : ";
	InsertAtEnd(head, 15);
	Display();
	system("pause");
	return 0;
}

/*
Output
Display original linked list : | 2 | 0015E098 | -------> | 11 | 0015E0D0 | -------> | 5 | 0015DF80 | -------> | 7 | 0015DA08 | -------> | 9 | 00000000 | ------->

Display after inserting at 4th index i.e. after 7 : | 2 | 0015E098 | -------> | 11 | 0015E0D0 | -------> | 5 | 0015DF80 | -------> | 7 | 0015DB58 | -------> | 8 | 0015DA08 | -------> | 9 | 00000000 | ------->

Display after inserting node at beginning : | 6 | 0015DA40 | -------> | 2 | 0015E098 | -------> | 11 | 0015E0D0 | -------> | 5 | 0015DF80 | -------> | 7 | 0015DB58 | -------> | 8 | 0015DA08 | -------> | 9 | 00000000 | ------->

Display after inserting node at end : | 6 | 0015DA40 | -------> | 2 | 0015E098 | -------> | 11 | 0015E0D0 | -------> | 5 | 0015DF80 | -------> | 7 | 0015DB58 | -------> | 8 | 0015DA08 | -------> | 9 | 0015DC38 | -------> | 15 | 00000000 | ------->
*/

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

/* Insert a node at the Beginning of Linked List */
Node_s* InsertAtBeginning(Node_s* temp, int x)
{
	Node_s* newNode = new Node_s;
	newNode->data = x;
	newNode->next = head;
	head = newNode;
	return head;
}

/* Insert node in a Sorted linked list */
Node_s* InsertInSortedList(Node_s* temp, int x)
{
	if (temp == nullptr || temp->data > x)
		return InsertAtBeginning(temp, x);
	Node_s* prev = nullptr;
	while (temp->data < x)
	{
		prev = temp;
		temp = temp->next;
	}
	Node_s* newNode = new Node_s;
	newNode->data = x;
	newNode->next = temp; // Or prev->next both are same
	prev->next = newNode;
	return head;
}

/* Main Method */
int main()
{
	InsertAtEnd(head, 3);
	InsertAtEnd(head, 5);
	InsertAtEnd(head, 7);
	InsertAtEnd(head, 9);
	cout << "Displaying Original link list : ";
	Display();
	cout << endl;
	InsertInSortedList(head, 6);
	cout << "Displaying link list after inserting 6 : ";
	Display();
	cout << endl;
	InsertInSortedList(head, 1);
	cout << "Displaying link list after inserting 1 : ";
	Display();
	cout << endl;
	system("pause");
	return 0;
}

/*
Output
Displaying Original link list : | 3 | 000CD8E0 | -------> | 5 | 000CD8A8 | -------> | 7 | 000CDDE8 | -------> | 9 | 00000000 | ------->

Displaying link list after inserting 6 : | 3 | 000CD8E0 | -------> | 5 | 000CD918 | -------> | 6 | 000CD8A8 | -------> | 7 | 000CDDE8 | -------> | 9 | 00000000 | ------->

Displaying link list after inserting 1 : | 1 | 000CD870 | -------> | 3 | 000CD8E0 | -------> | 5 | 000CD918 | -------> | 6 | 000CD8A8 | -------> | 7 | 000CDDE8 | -------> | 9 | 00000000 | ------->
*/

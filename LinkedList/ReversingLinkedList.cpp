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

/* Reversing a Linked List Iteratively */
Node_s* ReverseLinkedListItr(Node_s* temp)
{
	if (temp == nullptr)
		return temp;

	Node_s* prev = nullptr;
	while (temp != nullptr)
	{
		Node_s* next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
	return head;
}


/* Reversing a Linked List Recursively using Tail Recursion */
Node_s* ReverseLinkedListRecTail(Node_s* temp)
{
	static Node_s* previous = nullptr;
	if (temp == nullptr)
	{
		head = previous;
		return head;
	}

	Node_s* next = temp->next;
	temp->next = previous;
	previous = temp;
	return ReverseLinkedListRecTail(next);
}

/* Reversing a Linked List Recursively using Head Recursion */
void ReverseLinkedListRecHead(Node_s* curr, Node_s* prev)
{
	if (curr == nullptr)
	{
		head = prev;
		return;
	}

	ReverseLinkedListRecHead(curr->next, curr);
	curr->next = prev;
}

/* Main Method */
int main()
{
	InsertAtEnd(head, 3);
	InsertAtEnd(head, 5);
	InsertAtEnd(head, 6);
	InsertAtEnd(head, 9);
	cout << "Displaying Original link list : ";
	Display();
	cout << endl;
	ReverseLinkedListItr(head);
	cout << "Displaying link list after reversing iteratively : ";
	Display();
	cout << endl;
	ReverseLinkedListRecTail(head);
	cout << "Displaying link list after reversing recursively using static node and tail recursion : ";
	Display();
	cout << endl;
	ReverseLinkedListRecHead(head, nullptr);
	cout << "Displaying link list after reversing recursively using head recursion : ";
	Display();
	cout << endl;
	system("pause");
	return 0;
}

/*
Output
Displaying Original link list : | 3 | 000CDFE0 | -------> | 5 | 000CDD08 | -------> | 6 | 000CE210 | -------> | 9 | 00000000 | ------->

Displaying link list after reversing iteratively : | 9 | 000CDD08 | -------> | 6 | 000CDFE0 | -------> | 5 | 000CDEC8 | -------> | 3 | 00000000 | ------->

Displaying link list after reversing recursively using static node and tail recursion : | 3 | 000CDFE0 | -------> | 5 | 000CDD08 | -------> | 6 | 000CE210 | -------> | 9 | 00000000 | ------->

Displaying link list after reversing recursively using head recursion : | 9 | 000CDD08 | -------> | 6 | 000CDFE0 | -------> | 5 | 000CDEC8 | -------> | 3 | 00000000 | ------->
*/

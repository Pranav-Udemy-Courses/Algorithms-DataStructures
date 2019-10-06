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

/* Remove Duplicates from Sorted Linked List */
Node_s* RemoveDuplicatesSorted(Node_s* temp)
{
	if (temp == nullptr || temp->next == nullptr)
		return head;
	while (temp != nullptr && temp->next != nullptr)
	{
		if (temp->next->data == temp->data)
		{
			Node_s* toDelete = temp->next;
			temp->next = toDelete->next;
			delete toDelete;
			toDelete = nullptr;
		}
		temp = temp->next;
	}
	return head;
}

/* Main Method */
int main()
{
	InsertAtEnd(head, 3);
	InsertAtEnd(head, 5);
	InsertAtEnd(head, 5);
	InsertAtEnd(head, 6);
	InsertAtEnd(head, 9);
	InsertAtEnd(head, 9);
	cout << "Displaying Original link list : ";
	Display();
	cout << endl;
	RemoveDuplicatesSorted(head);
	cout << "Displaying link list after removing duplicates : ";
	Display();
	cout << endl;
	system("pause");
	return 0;
}

/*
Output
Displaying Original link list : | 3 | 00CCE480 | -------> | 5 | 00CCE4B8 | -------> | 5 | 00CCE170 | -------> | 6 | 00CCE6B0 | -------> | 9 | 00CCE4F0 | -------> | 9 | 00000000 | ------->

Displaying link list after removing duplicates : | 3 | 00CCE480 | -------> | 5 | 00CCE170 | -------> | 6 | 00CCE6B0 | -------> | 9 | 00000000 | ------->
*/

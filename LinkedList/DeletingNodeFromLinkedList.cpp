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

/* Delete node at the beginning of Linked List */
Node_s* DeleteAtBeginning(Node_s* temp)
{
	if (temp == nullptr)
		return nullptr;
	head = temp->next;
	delete temp;
	temp = nullptr;
	return head;
}

/* Deleting a node for given element in a Linked List */
Node_s* DeleteNodeForElement(Node_s* temp, int x)
{
	if (temp == nullptr || temp->data == x)
		return DeleteAtBeginning(temp);
	while (temp->next != nullptr && temp->next->data != x)
		temp = temp->next;
	if (temp->next == nullptr)
		return nullptr;
	else
	{
		Node_s* toDelete = temp->next;
		temp->next = toDelete->next;
		delete toDelete;
		toDelete = nullptr;
		return head;
	}
}

/* Deleting a node at given index */
Node_s* DeleteNodeAtIndex(Node_s* temp, int index)
{
	if (temp == nullptr || index == 0)
		return DeleteAtBeginning(temp);
	for (int i = 0; i <= index - 2; ++i)
	{
		temp = temp->next;
	}
	Node_s* toDelete = temp->next;
	temp->next = toDelete->next;
	delete toDelete;
	toDelete = nullptr;
	return head;
}

/* Main Method */
int main()
{
	InsertAtEnd(head, 3);
	InsertAtEnd(head, 5);
	InsertAtEnd(head, 6);
	InsertAtEnd(head, 7);
	InsertAtEnd(head, 9);
	cout << "Displaying Original link list : ";
	Display();
	cout << endl;
	DeleteAtBeginning(head);
	cout << "Displaying link list after deleting first node : ";
	Display();
	cout << endl;
	DeleteNodeForElement(head, 6);
	cout << "Displaying link list after deleting node with element 6 : ";
	Display();
	cout << endl;
	DeleteNodeForElement(head, 9);
	cout << "Displaying link list after deleting last node : ";
	Display();
	cout << endl;
	InsertAtEnd(head, 11);
	InsertAtEnd(head, 13);
	InsertAtEnd(head, 15);
	cout << "Displaying Original link list : ";
	Display();
	cout << endl;
	DeleteNodeAtIndex(head, 2);
	cout << "Displaying link list after deleting node at index 2 : ";
	Display();
	cout << endl;
	DeleteNodeAtIndex(head, 3);
	cout << "Displaying link list after deleting node at index 3 : ";
	Display();
	cout << endl;
	system("pause");
	return 0;
}

/*
Output
Displaying Original link list : | 3 | 0007D918 | -------> | 5 | 0007DEC8 | -------> | 6 | 0007DAA0 | -------> | 7 | 0007D800 | -------> | 9 | 00000000 | ------->

Displaying link list after deleting first node : | 5 | 0007DEC8 | -------> | 6 | 0007DAA0 | -------> | 7 | 0007D800 | -------> | 9 | 00000000 | ------->

Displaying link list after deleting node with element 6 : | 5 | 0007DAA0 | -------> | 7 | 0007D800 | -------> | 9 | 00000000 | ------->

Displaying link list after deleting last node : | 5 | 0007DAA0 | -------> | 7 | 00000000 | ------->

Displaying Original link list : | 5 | 0007DAA0 | -------> | 7 | 0007DA30 | -------> | 11 | 0007DBF0 | -------> | 13 | 0007DC28 | -------> | 15 | 00000000 | ------->

Displaying link list after deleting node at index 2 : | 5 | 0007DAA0 | -------> | 7 | 0007DBF0 | -------> | 13 | 0007DC28 | -------> | 15 | 00000000 | ------->

Displaying link list after deleting node at index 3 : | 5 | 0007DAA0 | -------> | 7 | 0007DBF0 | -------> | 13 | 00000000 | ------->
*/

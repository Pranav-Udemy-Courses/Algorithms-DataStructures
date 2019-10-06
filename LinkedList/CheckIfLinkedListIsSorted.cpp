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

/* Check if given linked list is sorted or not */
bool IsSorted(Node_s* temp)
{
	if (temp == nullptr || temp->next == nullptr)
		return true;
	while (temp->next != nullptr)
	{
		if (temp->data > temp->next->data)
			return false;
		temp = temp->next;
	}
	return true;
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
	cout << "The original list is sorted ? : " << std::boolalpha << IsSorted(head) << endl;
	cout << endl;
	InsertAtEnd(head, 2);
	cout << "Displaying Original link list : ";
	Display();
	cout << endl;
	cout << "The original list is sorted ? : " << std::boolalpha << IsSorted(head) << endl;
	cout << endl;
	system("pause");
	return 0;
}

/*
Output
Displaying Original link list : | 3 | 001EEE80 | -------> | 5 | 001EEF28 | -------> | 6 | 001EF040 | -------> | 7 | 001EEC88 | -------> | 9 | 00000000 | ------->

The original list is sorted ? : true

Displaying Original link list : | 3 | 001EEE80 | -------> | 5 | 001EEF28 | -------> | 6 | 001EF040 | -------> | 7 | 001EEC88 | -------> | 9 | 001EEF60 | -------> | 2 | 00000000 | ------->

The original list is sorted ? : false
*/

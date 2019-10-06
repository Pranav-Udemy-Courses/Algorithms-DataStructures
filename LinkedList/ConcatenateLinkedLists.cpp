#include <iostream>

using namespace std;

/* Structure of Node */
typedef struct Node_t
{
	int data;  // Data to be stored
	Node_t* next;  // Pointer to the next node
}Node_s;

// Global Variable Node_s*
Node_s* list1 = nullptr;
Node_s* list2 = nullptr;

/* Display the linked list */
void Display(Node_s* list)
{
	Node_s* temp = list;
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
	newNode->next = temp;
	temp = newNode;
	return temp;
}

/* Insert a node at the end of Linked List */
Node_s* InsertAtEnd(Node_s* temp, int x)
{
	Node_s* tempHead = temp;
	if (temp == nullptr)
		return InsertAtBeginning(temp, x);

	while (temp->next != nullptr)
		temp = temp->next;
	Node_s* newNode = new Node_s;
	newNode->data = x;
	newNode->next = temp->next;
	temp->next = newNode;
	return tempHead;
}

/* Concatenate Two Linked Lists */
Node_s* ConcatenateLinkedLists(Node_s* first, Node_s* second)
{
	Node_s* result = first;
	while (first->next != nullptr)
		first = first->next;
	first->next = second;
	return result;
}

/* Main Method */
int main()
{
	list1 = InsertAtEnd(list1, 10);
	list1 = InsertAtEnd(list1, 20);
	list1 = InsertAtEnd(list1, 30);
	list1 = InsertAtEnd(list1, 40);
	cout << "Displaying link list 1 : ";
	Display(list1);
	cout << endl;

	list2 = InsertAtEnd(list2, 15);
	list2 = InsertAtEnd(list2, 25);
	list2 = InsertAtEnd(list2, 35);
	cout << "Displaying link list 2 : ";
	Display(list2);
	cout << endl;

	Node_s* result = ConcatenateLinkedLists(list1, list2);
	cout << "Displaying concatenated linked list : ";
	Display(result);
	cout << endl;

	system("pause");
	return 0;
}

/*
Output
Displaying link list 1 : | 10 | 00F1E008 | -------> | 20 | 00F1E040 | -------> | 30 | 00F1E078 | -------> | 40 | 00000000 | ------->

Displaying link list 2 : | 15 | 00F1E388 | -------> | 25 | 00F1E3C0 | -------> | 35 | 00000000 | ------->

Displaying concatenated linked list : | 10 | 00F1E008 | -------> | 20 | 00F1E040 | -------> | 30 | 00F1E078 | -------> | 40 | 00F1E1C8 | -------> | 15 | 00F1E388 | -------> | 25 | 00F1E3C0 | -------> | 35 | 00000000 | ------->
*/

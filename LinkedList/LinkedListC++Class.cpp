/* ------------------------------------------------------------------------------------
				Node Header (Node.hxx)
------------------------------------------------------------------------------------ */
#include<iostream>

using namespace std;

/* Class Node */
class Node
{
public:
	int data;  // The data to be stored
	Node* next;  // Pointer to next node
};

/* ------------------------------------------------------------------------------------
			LinkedList Header (LinkedList.hxx)
------------------------------------------------------------------------------------ */
#include "Node.hxx"

/* Linked List Class */
class LinkedList
{
public:

	// Default Constructor
	LinkedList();

	// Parameterized Constructor
	LinkedList(int A[], int len);

	// Destructor
	~LinkedList();

	// Display Linked List
	void Display();

	// Insert node in Linked List
	void Insert(int index, int x);

	// Delete node in Linked List
	int Delete(int index);

	// Number of nodes in Linked List
	int Length();

private:
	Node* head;  // Object of class Node

	// Insert at Beginning
	void InsertAtBeginning(int x);

	// Delete at Beginning
	int DeleteAtBeginning();
};

/* ------------------------------------------------------------------------------------
			LinkedList Implementation (LinkedList.cxx)
------------------------------------------------------------------------------------ */
#include "LinkedList.hxx"

/* ----------------------------------- */
LinkedList::LinkedList()
{
	head = nullptr;
}

/* ----------------------------------- */
LinkedList::LinkedList(int A[], int len)
{
	Node* last, * t;
	head = new Node();
	head->data = A[0];
	head->next = nullptr;
	last = head;

	for (int i = 1; i < len; ++i)
	{
		t = new Node();
		t->data = A[i];
		t->next = nullptr;
		last->next = t;
		last = t;
	}
}

/* ----------------------------------- */
LinkedList::~LinkedList()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}

/* ----------------------------------- */
void LinkedList::Display()
{
	if (head == nullptr)
		return;
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << "| " << temp->data << " | " << temp->next << " | ------> ";
		temp = temp->next;
	}
	cout << endl << endl;
}

/* ----------------------------------- */
void LinkedList::InsertAtBeginning(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = head;
	head = newNode;
}

/* ----------------------------------- */
void LinkedList::Insert(int index, int x)
{
	if (head == nullptr || index == 0)
	{
		InsertAtBeginning(x);
		return;
	}
	Node* temp = head;
	for (int i = 0; i <= index - 2; ++i)
	{
		temp = temp->next;
	}
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = temp->next;
	temp->next = newNode;
}

/* ----------------------------------- */
int LinkedList::DeleteAtBeginning()
{
	Node* nodeToDelete = head;
	int nodeValue = head->data;
	head = head->next;
	delete nodeToDelete;
	nodeToDelete = nullptr;
	return nodeValue;
}

/* ----------------------------------- */
int LinkedList::Delete(int index)
{
	if (head == nullptr)
		return -1;
	if (index == 0)
		return DeleteAtBeginning();

	Node* temp = head;
	for (int i = 0; i <= index - 2; ++i)
	{
		temp = temp->next;
	}
	Node* nodeToDelete = temp->next;
	int nodeValue = nodeToDelete->data;
	temp->next = nodeToDelete->next;
	delete nodeToDelete;
	nodeToDelete = nullptr;
	return nodeValue;
}

/* ----------------------------------- */
int LinkedList::Length()
{
	if (head == nullptr)
		return -1;
	int count = 1;
	Node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

/* ------------------------------------------------------------------------------------
				Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "LinkedList.hxx"

using namespace std;

/* Main Method */
int main()
{
	LinkedList list;
	list.Insert(0, 3);
	list.Insert(1, 5);
	list.Insert(2, 7);
	list.Insert(3, 9);
	list.Display();
	cout << "Total number of nodes are : " << list.Length() << endl << endl;
	cout << "Deleted node at index 2 is : " << list.Delete(2) << endl << endl;
	list.Display();
	cout << "Total number of nodes are : " << list.Length() << endl << endl;
	system("pause");
	return 0;
}

/*
Output
| 3 | 0046DD28 | ------> | 5 | 0046DC10 | ------> | 7 | 0046D820 | ------> | 9 | 00000000 | ------>

Total number of nodes are : 4

Deleted node at index 2 is : 7

| 3 | 0046DD28 | ------> | 5 | 0046D820 | ------> | 9 | 00000000 | ------>

Total number of nodes are : 3

*/

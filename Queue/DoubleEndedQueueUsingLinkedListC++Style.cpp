/* ------------------------------------------------------------------------------------
			  Node Header (Node.hxx)
------------------------------------------------------------------------------------ */
#include <iostream>

using namespace std;

/* Class Node */
class Node
{
public:
	int data;  // Data to be stored
	Node* next;  // Pointer to the next node
};

/* ------------------------------------------------------------------------------------
			EnqueueDequeue Header (EnqueueDequeue.hxx)
------------------------------------------------------------------------------------ */
#include "Node.hxx"

/* Class EnqueueDequeue */
class EnqueueDequeue
{
public:

	// Constructor
	EnqueueDequeue();

	// Destructor
	~EnqueueDequeue();

	// Enqueue Beginning
	void EnqueueBeginning(int x);

	// Enqueue End
	void EnqueueEnd(int x);

	// Dequeue Beginning
	int DequeueBeginning();

	// Dequeue End
	int DequeueEnd();

	// Is Queue Empty
	bool IsEmpty();

	// Is Queue Full
	bool IsFull();

	// Display Elements of Queue
	void Display();

private:
	Node* head; // Pointer to first node
	Node* tail; // Pointer to last node
};

/* ------------------------------------------------------------------------------------
			EnqueueDequeue Implementation (EnqueueDequeue.cxx)
------------------------------------------------------------------------------------ */
#include "EnqueueDequeue.hxx"

/* ----------------------------------- */
EnqueueDequeue::EnqueueDequeue()
{
	head = tail = nullptr;
}

/* ----------------------------------- */
EnqueueDequeue::~EnqueueDequeue()
{
	Node* temp = nullptr;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	temp = head = tail = nullptr;
}

/* ----------------------------------- */
void EnqueueDequeue::EnqueueBeginning(int x)
{
	Node* temp = new Node;
	temp->data = x;
	if (IsEmpty())
	{
		temp->next = nullptr;
		head = tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

/* ----------------------------------- */
void EnqueueDequeue::EnqueueEnd(int x)
{
	Node* temp = new Node;
	temp->data = x;
	if (IsEmpty())
	{
		temp->next = nullptr;
		head = tail = temp;
	}
	else
	{
		temp->next = nullptr;
		tail->next = temp;
		tail = tail->next;
	}
}

/* ----------------------------------- */
int EnqueueDequeue::DequeueBeginning()
{
	if (IsEmpty())
		return -1;
	Node* temp = head;
	head = head->next;
	int x = temp->data;
	delete temp;
	temp = nullptr;
	if (head == nullptr)
		tail = nullptr;
	return x;
}

/* ----------------------------------- */
int EnqueueDequeue::DequeueEnd()
{
	if (IsEmpty())
		return -1;

	if (head == tail)
	{
		int x = head->data;
		delete head;
		head = tail = nullptr;
		return x;
	}
	Node* p = head;
	Node* q = nullptr;
	while (p != tail)
	{
		q = p;
		p = p->next;
	}
	q->next = nullptr;
	int x = p->data;
	delete p;
	tail = q;
	return x;
}

/* ----------------------------------- */
bool EnqueueDequeue::IsEmpty()
{
	if (head == tail && head == nullptr)
		return true;
	return false;
}

/* ----------------------------------- */
bool EnqueueDequeue::IsFull()
{
	Node* temp = new Node;
	if (temp == nullptr)
		return true;
	delete temp;
	temp = nullptr;
	return false;
}

/* ----------------------------------- */
void EnqueueDequeue::Display()
{
	cout << "Printing elements of queue : ";
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
	cout << endl;
}

/* ------------------------------------------------------------------------------------
			  Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "EnqueueDequeue.hxx"

/* Main Method */
int main()
{
	EnqueueDequeue ed;
	ed.EnqueueEnd(5);
	ed.Display();
	ed.EnqueueBeginning(3);
	ed.Display();
	ed.EnqueueBeginning(1);
	ed.EnqueueEnd(7);
	ed.Display();
	cout << "Removing the element from end : " << ed.DequeueEnd() << endl;
	ed.Display();
	cout << "Removing the element from front : " << ed.DequeueBeginning() << endl;
	ed.Display();
	cout << "Removing the element from end : " << ed.DequeueEnd() << endl;
	ed.Display();
	cout << "Removing the element from front : " << ed.DequeueBeginning() << endl;
	ed.Display();
	cout << "Removing the element from front : " << ed.DequeueBeginning() << endl;
	system("pause");
	return 0;
}

/*
Output
Printing elements of queue : 5
Printing elements of queue : 3  5
Printing elements of queue : 1  3  5  7
Removing the element from end : 7
Printing elements of queue : 1  3  5
Removing the element from front : 1
Printing elements of queue : 3  5
Removing the element from end : 5
Printing elements of queue : 3
Removing the element from front : 3
Printing elements of queue :
Removing the element from front : -1
*/

/* ------------------------------------------------------------------------------------
			  Node Header (Node.hxx)
------------------------------------------------------------------------------------ */
#include <iostream>

using namespace std;

/* Class Node */
class Node
{
public:
	int data; // Data to be stored
	Node* next; // Pointer to next node
};

/* ------------------------------------------------------------------------------------
			  Queue Header (Queue.hxx)
------------------------------------------------------------------------------------ */
#include "Node.hxx"

/* Class Queue */
class Queue
{
public:

	// Default Constructor
	Queue();

	// Destructor
	~Queue();

	// Add an element in Queue
	void Enqueue(int x);

	// Remove an element from Queue
	int Dequeue();

	// Check if Queue is Empty
	bool IsEmpty();

	// Check if Queue is Full
	bool IsFull();

	// Display Elements of Queue
	void Display();

private:
	Node* head; // Pointer to start of linked list
	Node* tail; // Pointer to end of linked list
};

/* ------------------------------------------------------------------------------------
			Queue Implementation (Queue.cxx)
------------------------------------------------------------------------------------ */
#include "Queue.hxx"

/* ----------------------------------- */
Queue::Queue()
{
	head = tail = nullptr;
}

/* ----------------------------------- */
Queue::~Queue()
{
	Node* t = nullptr;
	while (head != nullptr)
	{
		t = head;
		head = head->next;
		delete t;
	}
	t = nullptr;
}

/* ----------------------------------- */
void Queue::Enqueue(int x)
{
	if (IsFull())
		return;
	Node* t = new Node;
	t->data = x;
	t->next = nullptr;
	if (IsEmpty())
	{
		head = tail = t;
	}
	else
	{
		tail->next = t;
		tail = t;
	}
}

/* ----------------------------------- */
int Queue::Dequeue()
{
	if (IsEmpty())
		return -1;
	Node* t = head;
	head = head->next;
	int x = t->data;
	delete t;
	t = nullptr;
	if (head == nullptr)
		tail = nullptr;
	return x;
}

/* ----------------------------------- */
bool Queue::IsEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}

/* ----------------------------------- */
bool Queue::IsFull()
{
	Node* t = new Node;
	if (t == nullptr)
		return true;
	delete t;
	return false;
}

/* ----------------------------------- */
void Queue::Display()
{
	cout << "The Elements in Queue are : ";
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
#include "Queue.hxx"

/* Main Method */
int main()
{
	Queue q;
	q.Enqueue(3);
	q.Enqueue(5);
	q.Enqueue(7);
	q.Enqueue(9);
	q.Enqueue(11);
	q.Display();
	cout << "The removed element from queue is : " << q.Dequeue() << endl;
	cout << "The removed element from queue is : " << q.Dequeue() << endl;
	q.Display();
	system("pause");
	return 0;
}

/*
Output
The Elements in Queue are : 3  5  7  9  11
The removed element from queue is : 3
The removed element from queue is : 5
The Elements in Queue are : 7  9  11
*/

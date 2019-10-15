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

	// Remove an element with higher priority from Queue
	int DequeuePrior();

	// Get Index of Larger Element
	int GetIndexOfLarger();

	// Remove at Index
	int DeleteAtIndex(int index);

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
int Queue::DequeuePrior()
{
	if (IsEmpty())
		return -1;
	int index = GetIndexOfLarger();
	return DeleteAtIndex(index);
}

/* ----------------------------------- */
int Queue::GetIndexOfLarger()
{
	Node* temp = head;
	int index = 0;
	int i = 0;
	int max = temp->data;
	while (temp != nullptr)
	{
		if (temp->data > max)
		{
			max = temp->data;
			index = i;
		}
		temp = temp->next;
		++i;
	}
	return index;
}

/* ----------------------------------- */
int Queue::DeleteAtIndex(int index)
{
	Node* temp = nullptr;
	int x = -1;
	if (index == 0)
	{
		temp = head;
		head = head->next;
		x = temp->data;
		delete temp;
	}
	else
	{
		Node* t = head;
		for (int i = 0; i <= index - 2; ++i)
			t = t->next;
		temp = t->next;
		t->next = temp->next;
		x = temp->data;
		delete temp;
	}
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
	q.Enqueue(11);
	q.Enqueue(7);
	q.Enqueue(9);
	q.Enqueue(5);
	q.Display();
	cout << "The removed element from queue is : " << q.DequeuePrior() << endl;
	cout << "The removed element from queue is : " << q.DequeuePrior() << endl;
	q.Display();
	system("pause");
	return 0;
}

/*
Output
The Elements in Queue are : 3  11  7  9  5
The removed element from queue is : 11
The removed element from queue is : 9
The Elements in Queue are : 3  7  5
*/

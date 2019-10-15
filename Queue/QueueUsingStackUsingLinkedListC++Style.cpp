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
			  Stack Header (Stack.hxx)
------------------------------------------------------------------------------------ */
#include "Node.hxx"

/* Class Stack */
class Stack
{
private:
	Node* head; // Pointer to start of stack
public:

	// Default Constructor
	Stack();

	// Destructor
	~Stack();

	// Push an Element on Stack
	void Push(int x);

	// Remove an Element from Stack
	int Pop();

	// Check if Stack is Empty
	bool IsEmpty();
};

/* ------------------------------------------------------------------------------------
			Stack Implementation (Stack.cxx)
------------------------------------------------------------------------------------ */
#include "Stack.hxx"

/* ----------------------------------- */
Stack::Stack()
{
	head = nullptr;
}

/* ----------------------------------- */
Stack::~Stack()
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
void Stack::Push(int x)
{
	Node* t = new Node;
	t->data = x;
	t->next = head;
	head = t;
}

/* ----------------------------------- */
int Stack::Pop()
{
	if (IsEmpty())
		return -1;
	Node* t = head;
	head = head->next;
	int x = t->data;
	delete t;
	return x;
}

/* ----------------------------------- */
bool Stack::IsEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}

/* ------------------------------------------------------------------------------------
			  Queue Header (Queue.hxx)
------------------------------------------------------------------------------------ */
#include "Stack.hxx"

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

private:
	Stack s1; // Pointer to start of linked list
	Stack s2; // Pointer to end of linked list
};

/* ------------------------------------------------------------------------------------
			Queue Implementation (Queue.cxx)
------------------------------------------------------------------------------------ */
#include "Queue.hxx"

/* ----------------------------------- */
Queue::Queue()
{

}

/* ----------------------------------- */
Queue::~Queue()
{

}

/* ----------------------------------- */
void Queue::Enqueue(int x)
{
	s1.Push(x);
}

/* ----------------------------------- */
int Queue::Dequeue()
{
	int x = -1;
	if (s2.IsEmpty())
	{
		if (s1.IsEmpty())
			return -1;
		while (!s1.IsEmpty())
		{
			s2.Push(s1.Pop());
		}
		x = s2.Pop();
	}
	else
	{
		x = s2.Pop();
	}
	return x;
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
	q.Enqueue(7);
	q.Enqueue(9);
	q.Enqueue(11);
	cout << "The removed element from queue is : " << q.Dequeue() << endl;
	cout << "The removed element from queue is : " << q.Dequeue() << endl;
	system("pause");
	return 0;
}

/*
Output
The Elements in Queue are : 3  7  9  11
The removed element from queue is : 3
The removed element from queue is : 7
*/

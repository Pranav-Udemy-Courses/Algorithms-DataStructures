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
	void Enqueue(int x, int prior);

	// Add an element in Queue1
	void Enqueue1(int x);

	// Add an element in Queue2
	void Enqueue2(int x);

	// Remove an element from Queue
	int Dequeue();

	// Remove an element from Queue1
	int Dequeue1();

	// Remove an element from Queue2
	int Dequeue2();

	// Check if Queue1 is Empty
	bool IsEmpty1();

	// Check if Queue2 is Empty
	bool IsEmpty2();

	// Check if Queue1 is Full
	bool IsFull1();

	// Check if Queue2 is Full
	bool IsFull2();

	// Display Elements of Queue
	void Display();

private:
	Node* p1Head; // Pointer to start of Queue2
	Node* p2Head; // Pointer to start of Queue2
	Node* p1Tail; // Pointer to end of Queue1
	Node* p2Tail; // Pointer to end of Queue2
};

/* ------------------------------------------------------------------------------------
			Queue Implementation (Queue.cxx)
------------------------------------------------------------------------------------ */
#include "Queue.hxx"

/* ----------------------------------- */
Queue::Queue()
{
	p1Head = p2Head = p1Tail = p2Tail = nullptr;
}

/* ----------------------------------- */
Queue::~Queue()
{
	Node* t = nullptr;
	while (p1Head != nullptr)
	{
		t = p1Head;
		p1Head = p1Head->next;
		delete t;
	}
	while (p2Head != nullptr)
	{
		t = p2Head;
		p2Head = p2Head->next;
		delete t;
	}
	t = nullptr;
}

/* ----------------------------------- */
void Queue::Enqueue1(int x)
{
	if (IsFull1())
		return;
	Node* t = new Node;
	t->data = x;
	t->next = nullptr;
	if (IsEmpty1())
	{
		p1Head = p1Tail = t;
	}
	else
	{
		p1Tail->next = t;
		p1Tail = t;
	}
}

/* ----------------------------------- */
void Queue::Enqueue2(int x)
{
	if (IsFull2())
		return;
	Node* t = new Node;
	t->data = x;
	t->next = nullptr;
	if (IsEmpty2())
	{
		p2Head = p2Tail = t;
	}
	else
	{
		p2Tail->next = t;
		p2Tail = t;
	}
}

/* ----------------------------------- */
void Queue::Enqueue(int x, int prior)
{
	if (prior == 1)
		Enqueue1(x);
	else if (prior == 2)
		Enqueue2(x);
}

/* ----------------------------------- */
int Queue::Dequeue1()
{
	if (IsEmpty1())
		return -1;
	Node* t = p1Head;
	p1Head = p1Head->next;
	int x = t->data;
	delete t;
	t = nullptr;
	if (p1Head == nullptr)
		p1Tail = nullptr;
	return x;
}

/* ----------------------------------- */
int Queue::Dequeue2()
{
	if (IsEmpty2())
		return -1;
	Node* t = p2Head;
	p2Head = p2Head->next;
	int x = t->data;
	delete t;
	t = nullptr;
	if (p2Head == nullptr)
		p2Tail = nullptr;
	return x;
}

/* ----------------------------------- */
int Queue::Dequeue()
{
	if (!IsEmpty1())
		return Dequeue1();
	return Dequeue2();
}

/* ----------------------------------- */
bool Queue::IsEmpty1()
{
	if (p1Head == nullptr)
		return true;
	return false;
}

/* ----------------------------------- */
bool Queue::IsEmpty2()
{
	if (p2Head == nullptr)
		return true;
	return false;
}

/* ----------------------------------- */
bool Queue::IsFull1()
{
	Node* t = new Node;
	if (t == nullptr)
		return true;
	delete t;
	return false;
}

/* ----------------------------------- */
bool Queue::IsFull2()
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
	cout << "The Elements in Queue1 are : ";
	Node* temp = p1Head;
	while (temp != nullptr)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
	cout << endl;
	temp = p2Head;
	cout << "The Elements in Queue2 are : ";
	while (temp != nullptr)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
	cout << endl << endl;
}

/* ------------------------------------------------------------------------------------
			  Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "Queue.hxx"

/* Main Method */
int main()
{
	Queue q;
	q.Enqueue(3, 1);
	q.Enqueue(5, 2);
	q.Enqueue(7, 2);
	q.Enqueue(9, 1);
	q.Display();
	cout << "Removing element from Queue : " << q.Dequeue() << endl << endl;
	cout << "Removing element from Queue : " << q.Dequeue() << endl << endl;
	cout << "Removing element from Queue : " << q.Dequeue() << endl << endl;
	q.Display();
	q.Enqueue(11, 1);
	q.Display();
	cout << "Removing element from Queue : " << q.Dequeue() << endl << endl;
	q.Display();
	system("pause");
	return 0;
}

/*
Output
The Elements in Queue1 are : 3  9
The Elements in Queue2 are : 5  7

Removing element from Queue : 3

Removing element from Queue : 9

Removing element from Queue : 5

The Elements in Queue1 are :
The Elements in Queue2 are : 7

The Elements in Queue1 are : 11
The Elements in Queue2 are : 7

Removing element from Queue : 11

The Elements in Queue1 are :
The Elements in Queue2 are : 7
*/

/* ------------------------------------------------------------------------------------
			  Queue Header (Queue.hxx)
------------------------------------------------------------------------------------ */
#include<iostream>

using namespace std;

/* Queue Class */
class Queue
{
public:

	// Parametrized Constructor
	Queue(int size = 10);

	// Add an Element to Queue
	void Enqueue(int x);

	// Remove an Element from Queue
	int Dequeue();

	// Display the Elements of Queue
	void Display();

	// Check if Queue is Full
	bool IsFull();

	// Check if Queue is Empty
	bool IsEmpty();

private:
	int size; // Size of the Queue
	int front; // Pointer for deletion
	int rear; // Pointer for insertion
	int* Q; // Array of integers
};

/* ------------------------------------------------------------------------------------
			Queue Implementation (Queue.cxx)
------------------------------------------------------------------------------------ */
#include "Queue.hxx"

/* ----------------------------------- */
Queue::Queue(int size)
{
	this->size = size;
	this->front = -1;
	this->rear = -1;
	this->Q = new int[size];
}

/* ----------------------------------- */
void Queue::Enqueue(int x)
{
	if (IsFull())
		return;
	this->rear++;
	this->Q[this->rear] = x;
}

/* ----------------------------------- */
int Queue::Dequeue()
{
	if (IsEmpty())
		return -1;
	this->front++;
	return this->Q[this->front];
}

/* ----------------------------------- */
void Queue::Display()
{
	cout << "The Elements of Queue are : ";
	for (int i = this->front + 1; i <= this->rear; ++i)
		cout << this->Q[i] << "  ";
	cout << endl;
}

/* ----------------------------------- */
bool Queue::IsFull()
{
	if (this->rear == this->size - 1)
		return true;
	return false;
}

/* ----------------------------------- */
bool Queue::IsEmpty()
{
	if (this->front == this->rear)
		return true;
	return false;
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
	q.Display();
	cout << "Removed Element from Queue is : " << q.Dequeue() << endl;
	cout << "Removed Element from Queue is : " << q.Dequeue() << endl;
	q.Display();
	system("pause");
	return 0;
}

/*
Output
The Elements of Queue are : 3  5  7
Removed Element from Queue is : 3
Removed Element from Queue is : 5
The Elements of Queue are : 7
*/

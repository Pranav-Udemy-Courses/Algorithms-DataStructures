/* ------------------------------------------------------------------------------------
			CircularQueue Header (CircularQueue.hxx)
------------------------------------------------------------------------------------ */
#include<iostream>

using namespace std;

/* CircularQueue Class */
class CircularQueue
{
public:

	// Parametrized Constructor
	CircularQueue(int size = 5);

	// Add an Element to CircularQueue
	void Enqueue(int x);

	// Remove an Element from CircularQueue
	int Dequeue();

	// Display the Elements of CircularQueue
	void Display();

	// Check if CircularQueue is Full
	bool IsFull();

	// Check if CircularQueue is Empty
	bool IsEmpty();

private:
	int size; // Size of the CircularQueue
	int front; // Pointer for deletion
	int rear; // Pointer for insertion
	int* Q; // Array of integers
};

/* ------------------------------------------------------------------------------------
		CircularQueue Implementation (CircularQueue.cxx)
------------------------------------------------------------------------------------ */
#include "CircularQueue.hxx"

/* ----------------------------------- */
CircularQueue::CircularQueue(int size)
{
	this->size = size;
	this->front = 0;
	this->rear = 0;
	this->Q = new int[size];
}

/* ----------------------------------- */
void CircularQueue::Enqueue(int x)
{
	if (IsFull())
		return;
	this->rear = (this->rear + 1) % this->size;
	this->Q[this->rear] = x;
}

/* ----------------------------------- */
int CircularQueue::Dequeue()
{
	if (IsEmpty())
		return -1;
	this->front = (this->front + 1) % this->size;
	return this->Q[this->front];
}

/* ----------------------------------- */
void CircularQueue::Display()
{
	cout << "The Elements of CircularQueue are : ";
	int fr = this->front + 1;
	do
	{
		cout << this->Q[fr] << "  ";
		fr = (fr + 1) % this->size;
	} while (fr != (this->rear + 1) % this->size);

	cout << endl;
}

/* ----------------------------------- */
bool CircularQueue::IsFull()
{
	if ((this->rear + 1) % (this->size) == this->front)
		return true;
	return false;
}

/* ----------------------------------- */
bool CircularQueue::IsEmpty()
{
	if (this->front == this->rear)
		return true;
	return false;
}

/* ------------------------------------------------------------------------------------
			  Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "CircularQueue.hxx"

/* Main Method */
int main()
{
	CircularQueue q;
	q.Enqueue(3);
	q.Enqueue(5);
	q.Enqueue(7);
	q.Enqueue(9);
	q.Display();
	cout << "Removed Element from CircularQueue is : " << q.Dequeue() << endl;
	cout << "Removed Element from CircularQueue is : " << q.Dequeue() << endl;
	q.Display();
	q.Enqueue(11);
	q.Enqueue(13);
	q.Display();
	system("pause");
	return 0;
}

/*
Output
The Elements of CircularQueue are : 3  5  7  9
Removed Element from CircularQueue is : 3
Removed Element from CircularQueue is : 5
The Elements of CircularQueue are : 7  9
The Elements of CircularQueue are : 7  9  11  13
*/

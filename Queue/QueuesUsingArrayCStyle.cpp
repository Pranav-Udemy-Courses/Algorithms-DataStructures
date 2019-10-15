#include <iostream>

using namespace std;

/*-------------------------------------
		  Structure of Queue
-------------------------------------*/
typedef struct Queue_t
{
	int size; // Size of array
	int front; // Pointer for deletion/dequeue
	int rear; // Pointer for insertion/enqueue
	int* Q; // Array of integers
}Queue_s;

/*-------------------------------------
			Create Queue
-------------------------------------*/
Queue_s Create()
{
	Queue_s q;
	q.front = q.rear = -1;
	cout << "Enter the size of Queue : ";
	cin >> q.size;
	q.Q = new int[q.size];
	return q;
}

/*-------------------------------------
	Determine if Queue is Empty
-------------------------------------*/
bool IsEmpty(Queue_s q)
{
	if (q.front == q.rear)
		return true;
	return false;
}

/*-------------------------------------
	Determine if Queue is Full
-------------------------------------*/
bool IsFull(Queue_s q)
{
	if (q.rear == q.size - 1)
		return true;
	return false;
}

/*-------------------------------------
   Add an Element to a Queue
-------------------------------------*/
void Enqueue(Queue_s* q, int x)
{
	if (IsFull(*q))
		return;
	q->rear++;
	q->Q[q->rear] = x;
}

/*-------------------------------------
   Remove an Element from a Queue
-------------------------------------*/
int Dequeue(Queue_s* q)
{
	int x = -1;
	if (IsEmpty(*q))
		return x;
	q->front++;
	x = q->Q[q->front];
	return x;
}

/*-------------------------------------
   Display the Elements of Queue
-------------------------------------*/
void Display(Queue_s q)
{
	cout << "The Elements of Queue are : ";
	while (!IsEmpty(q))
	{
		cout << Dequeue(&q) << " ";
	}
	cout << endl;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	Queue_s que = Create();
	Enqueue(&que, 3);
	Enqueue(&que, 5);
	Enqueue(&que, 7);
	Display(que);
	cout << "The Element removed from Queue is : " << Dequeue(&que) << endl;
	cout << "The Element removed from Queue is : " << Dequeue(&que) << endl;
	Display(que);
	system("pause");
	return 0;
}

/*
Output
Enter the size of Queue : 4
The Elements of Queue are : 3 5 7
The Element removed from Queue is : 3
The Element removed from Queue is : 5
The Elements of Queue are : 7
*/

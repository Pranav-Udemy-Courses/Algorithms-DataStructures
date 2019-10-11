#include <iostream>

using namespace std;

/*-------------------------------------
		 Structure of Stack
-------------------------------------*/
typedef struct Stack_t
{
	int data; // Data to be Stored
	Stack_t* top; // Pointer to next Node
}Stack_s;


/*-------------------------------------
   Determine if Stack is Empty
-------------------------------------*/
bool IsEmpty(Stack_s* st)
{
	if (st == nullptr)
		return true;
	return false;
}

/*-------------------------------------
   Determine if Stack is Full
-------------------------------------*/
bool IsFull()
{
	Stack_s* t = new Stack_s;
	if (t == nullptr)
		return true;
	delete t;
	t = nullptr;
	return false;
}

/*-------------------------------------
	 Determine Length of Stack
-------------------------------------*/
int Length(Stack_s* st)
{
	int count = 0;
	if (IsEmpty(st))
		return count;
	while (st != nullptr)
	{
		count++;
		st = st->top;
	}
	return count;
}

/*-------------------------------------------------
   Find the Element at given position in a Stack
-------------------------------------------------*/
int Peek(Stack_s* st, int index)
{
	if (IsEmpty(st) || index > Length(st))
		return -1;
	for (int i = 0; i <= index - 2; ++i)
		st = st->top;
	return st->data;
}

/*-------------------------------------
   Push an Element on to a Stack
-------------------------------------*/
Stack_s* Push(Stack_s* st, int x)
{
	if (IsFull())
		return nullptr;
	Stack_s* t = new Stack_s;
	t->top = st;
	t->data = x;
	st = t;
	return st;
}

/*-------------------------------------
   Popping an Element from a Stack
-------------------------------------*/
Stack_s* Pop(Stack_s* st)
{
	if (IsEmpty(st))
		return nullptr;
	Stack_s* t = st->top;
	int x = st->data;
	delete st;
	st = t;
	return st;
}

/*-------------------------------------
   Top Element of a Stack
-------------------------------------*/
int StackTop(Stack_s* st)
{
	if (IsEmpty(st))
		return -1;
	return st->data;
}

/*-------------------------------------
   Display the Elements of Stack
-------------------------------------*/
void Display(Stack_s* st)
{
	cout << "The Stack is : ";
	while (st != nullptr)
	{
		cout << st->data << "  ";
		st = st->top;
	}
	cout << endl;
}

/*-------------------------------------
			Main Method
-------------------------------------*/
int main()
{
	Stack_s* stk = nullptr;
	stk = Push(stk, 10);
	stk = Push(stk, 20);
	stk = Push(stk, 30);
	stk = Push(stk, 40);
	Display(stk);
	cout << "Displaying the top element of Stack : " << StackTop(stk) << endl;
	cout << "Peeking into 2nd Element : " << Peek(stk, 2) << endl;
	stk = Pop(stk);
	Display(stk);
	system("pause");
	return 0;
}
/*
Output
The Stack is : 40  30  20  10
Displaying the top element of Stack : 40
Peeking into 2nd Element : 30
The Stack is : 30  20  10
*/

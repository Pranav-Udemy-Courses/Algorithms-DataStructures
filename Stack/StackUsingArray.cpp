#include <iostream>

using namespace std;

/*-------------------------------------
          Structure of Stack
-------------------------------------*/
typedef struct Stack_t
{
	int top;  // Point to top of stack
	int size; // Size of Stack
	int* s;   // Array of Integers
}Stack_s;

/*-------------------------------------
	  Create Stack
-------------------------------------*/
void Create(Stack_s* st)
{
	st->top = -1;
	cout << "Enter the size of Stack : ";
	cin >> st->size;
	st->s = new int[st->size];
}

/*-------------------------------------
    Determine if Stack is Empty
-------------------------------------*/
bool IsEmpty(Stack_s st)
{
	if (st.top == -1)
		return true;
	return false;
}

/*-------------------------------------
    Determine if Stack is Full
-------------------------------------*/
bool IsFull(Stack_s st)
{
	if (st.top == st.size - 1)
		return true;
	return false;
}

/*-------------------------------------------------
   Find the Element at given position in a Stack
-------------------------------------------------*/
int Peek(Stack_s st, int pos)
{
	if (IsEmpty(st) || st.top - pos + 1 < 0)
		return -1;
	return st.s[st.top - pos + 1];
}

/*-------------------------------------
   Push an Element on to a Stack
-------------------------------------*/
void Push(Stack_s* st, int x)
{
	if (IsFull(*st))
		cout << "Stack Overflow ..." << endl;
	else
	{
		st->top++;
		st->s[st->top] = x;
	}
}

/*-------------------------------------
   Popping an Element from a Stack
-------------------------------------*/
int Pop(Stack_s* st)
{
	if (IsEmpty(*st))
	{
		cout << "Stack Underflow ..." << endl;
		return -1;
	}
	return st->s[st->top--];
}

/*-------------------------------------
      Top Element of a Stack
-------------------------------------*/
int StackTop(Stack_s st)
{
	if (IsEmpty(st))
		return -1;
	return st.s[st.top];
}

/*-------------------------------------
   Display the Elements of Stack
-------------------------------------*/
void Display(Stack_s st)
{
	cout << "The Stack is : ";
	while (!IsEmpty(st))
	{
		cout << st.s[st.top--] << "  ";
	}
	cout << endl;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	Stack_s stack;
	Create(&stack);
	Push(&stack, 3);
	Push(&stack, 5);
	Push(&stack, 7);
	Display(stack);
	cout << "Peeking into 2nd Element : " << Peek(stack, 2) << endl;
	cout << "Popping out the top element : " << Pop(&stack) << endl;
	cout << "The top Element of Stack is : " << StackTop(stack) << endl;
	system("pause");
	return 0;
}
/*
Output
Enter the size of Stack : 5
The Stack is : 7  5  3
Peeking into 2nd Element : 5
Popping out the top element : 7
The top Element of Stack is : 5
*/

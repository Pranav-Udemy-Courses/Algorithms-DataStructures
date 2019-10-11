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
	Node* next; // Pointer to the next node
};

/* ------------------------------------------------------------------------------------
				Stack Header (Stack.hxx)
------------------------------------------------------------------------------------ */
#include "Node.hxx"

class Stack
{
public:

	// Check if Stack is Empty
	bool IsEmpty();

	// Check if Stack is Full
	bool IsFull();

	// Push Data on Stack
	void Push(int x);

	// Pop the Data from Stack
	int Pop();

	// Get the Value at given Position
	int Peek(int pos);

	// Get the Topmost Element of Stack
	int StackTop();

	// Display Elements of Stack
	void Display();

	// Default Constructor
	Stack();

	// Destructor
	~Stack();

private:
	Node* head;
};

/* ------------------------------------------------------------------------------------
			   Stack Implementation (Stack.cxx)
------------------------------------------------------------------------------------ */
#include "Stack.hxx"

/* ------------------------ */
Stack::Stack()
{
	head = nullptr;
}

/* ------------------------ */
Stack::~Stack()
{
	Node* temp = nullptr;
	while (head != nullptr)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	delete temp;
	temp = nullptr;
}

/* ------------------------ */
bool Stack::IsEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}

/* ------------------------ */
bool Stack::IsFull()
{
	Node* temp = new Node;
	if (temp == nullptr)
		return true;
	delete temp;
	temp = nullptr;
	return false;
}

/* ------------------------ */
void Stack::Push(int x)
{
	if (IsFull())
		return;
	Node* temp = new Node;
	temp->data = x;
	temp->next = head;
	head = temp;
}

/* ------------------------ */
int Stack::Pop()
{
	if (IsEmpty())
		return -1;
	Node* temp = head->next;
	int x = head->data;
	delete head;
	head = temp;
	return x;
}

/* ------------------------ */
void Stack::Display()
{
	cout << "The Stack is : ";
	if (IsEmpty())
		return;
	Node* start = head;
	while (start != nullptr)
	{
		cout << start->data << "  ";
		start = start->next;
	}
	cout << endl;
}

/* ------------------------ */
int Stack::Peek(int pos)
{
	if (IsEmpty())
		return -1;
	Node* temp = head;
	for (int i = 0; i <= pos - 2; ++i)
		temp = temp->next;
	return temp->data;
}

/* ------------------------ */
int Stack::StackTop()
{
	if (IsEmpty())
		return -1;
	return head->data;
}

/* ------------------------------------------------------------------------------------
			   Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "Stack.hxx"

/* Main Method */
int main()
{
	Stack s;
	cout << "Is the Stack Empty ? : " << std::boolalpha << s.IsEmpty() << endl;
	s.Push(10);
	s.Push(20);
	s.Push(30);
	s.Push(40);
	s.Display();
	cout << "Popping out the top element : " << s.Pop() << endl;
	s.Display();
	cout << "The top Element of Stack is : " << s.StackTop() << endl;
	cout << "The Element at 2nd Position is : " << s.Peek(2) << endl;
	system("pause");
	return 0;
}

/*
Output
Is the Stack Empty ? : true
The Stack is : 40  30  20  10
Popping out the top element : 40
The Stack is : 30  20  10
The top Element of Stack is : 30
The Element at 2nd Position is : 20
*/

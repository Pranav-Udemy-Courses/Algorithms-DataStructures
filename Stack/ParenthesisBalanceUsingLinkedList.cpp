#include <iostream>

using namespace std;

/*-------------------------------------
	Structure of Stack
-------------------------------------*/
typedef struct Stack_t
{
	char c; // Data to be Stored
	Stack_t* next; // Pointer to next Node
}Stack_s;

/*-------------------------------------
   Determine if Stack is Empty
-------------------------------------*/
bool IsEmpty(Stack_s* s)
{
	if (s == nullptr)
		return true;
	return false;
}


/*-------------------------------------
   Determine if Stack is Full
-------------------------------------*/
bool IsFull()
{
	Stack_s* temp = new Stack_s;
	if (temp == nullptr)
		return true;
	delete temp;
	temp = nullptr;
	return false;
}

/*-------------------------------------
   Top Element of a Stack
-------------------------------------*/
char StackTop(Stack_s* s)
{
	if (IsEmpty(s))
		return '!';
	return s->c;
}

/*-------------------------------------
   Push an Element on to a Stack
-------------------------------------*/
Stack_s* Push(Stack_s* s, char ch)
{
	if (IsFull())
		return nullptr;
	Stack_s* t = new Stack_s;
	t->c = ch;
	t->next = s;
	s = t;
	return s;
}

/*-------------------------------------
   Popping an Element from a Stack
-------------------------------------*/
Stack_s* Pop(Stack_s* s, char& c)
{
	if (IsEmpty(s))
		return nullptr;
	Stack_s* n = s->next;
	c = s->c;
	delete s;
	s = n;
	return s;
}

/*-------------------------------------
   Display the Elements of Stack
-------------------------------------*/
void Display(Stack_s* s)
{
	if (IsEmpty(s))
		return;
	cout << "Displaying the Stack : ";
	Stack_s* temp = s;
	while (temp != nullptr)
	{
		cout << temp->c << " ";
		temp = temp->next;
	}
	cout << endl;
}

/*-------------------------------------
   Check if Parenthesis are Balanced
-------------------------------------*/
bool IsBalanced(Stack_s* s, const char* ch)
{
	for (int i = 0; ch[i] != '\0'; ++i)
	{
		if (ch[i] == '(')
			s = Push(s, ch[i]);
		else if (ch[i] == ')')
		{
			char c = '!';
			s = Pop(s, c);
			if (c == '!')
				return false;
		}
	}
	return IsEmpty(s) ? true : false;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	Stack_s* stk = nullptr;
	const char* c2 = "(a+b)*(c+d))";
	cout << "Is the String " << c2 << " Balanced ? : " << boolalpha << IsBalanced(stk, c2) << endl;
	const char* c1 = "(a+b)*(c+d)";
	cout << "Is the String " << c1 << " Balanced ? : " << boolalpha << IsBalanced(stk, c1) << endl;
	const char* c3 = "(a+b)*((c+d)";
	cout << "Is the String " << c3 << " Balanced ? : " << boolalpha << IsBalanced(stk, c3) << endl;
	system("pause");
	return 0;
}

/*
Output
Is the String (a+b)*(c+d)) Balanced ? : false
Is the String (a+b)*(c+d) Balanced ? : true
Is the String (a+b)*((c+d) Balanced ? : false
*/

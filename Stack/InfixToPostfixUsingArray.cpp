#include<iostream>

using namespace std;

/*-------------------------------------
	Structure of Stack
-------------------------------------*/
typedef struct Stack_t
{
	char* ch;
	int top;
	int size;
}Stack_s;


/*-------------------------------------
	  Create Stack
-------------------------------------*/
Stack_s Create(const char* str)
{
	Stack_s s;
	s.size = strlen(str);
	s.ch = new char[s.size];
	s.top = -1;
	return s;
}

/*-------------------------------------
     Determine if Stack is Empty
-------------------------------------*/
bool IsEmpty(const Stack_s& s)
{
	if (s.top == -1)
		return true;
	return false;
}

/*-------------------------------------
     Determine if Stack is Full
-------------------------------------*/
bool IsFull(const Stack_s& s)
{
	if (s.top == s.size - 1)
		return true;
	return false;
}

/*-------------------------------------
   Push an Element on to a Stack
-------------------------------------*/
void Push(Stack_s* s, char c)
{
	if (IsFull(*s))
		return;
	s->top++;
	s->ch[s->top] = c;
}

/*-------------------------------------
   Popping an Element from a Stack
-------------------------------------*/
char Pop(Stack_s* s)
{
	if (IsEmpty(*s))
		return '\0';
	return s->ch[s->top--];
}

/*-------------------------------------
   Display the Elements of Stack
-------------------------------------*/
void Display(Stack_s s)
{
	if (IsEmpty(s))
		return;
	while (!IsEmpty(s))
		cout << s.ch[s.top--] << " ";
	cout << endl;
}

/*-----------------------------------------
Check if the given character is an Operator
-----------------------------------------*/
bool IsOperator(char c)
{
	if (c == '*' || c == '/' || c == '-' || c == '+')
		return true;
	return false;
}

/*-------------------------------------
   Get Precedence of the character
-------------------------------------*/
int GetPrecedence(char c)
{
	if (c == '*' || c == '/')
		return 2;
	else if (c == '-' || c == '+')
		return 1;
	return 0;
}

/*-------------------------------------
      Convert Infix to Postfix
-------------------------------------*/
const char* PostFixCon(const char* str)
{
	Stack_s s = Create(str);
	char* st = new char[s.size + 1];
	int j = 0;
	for (int i = 0; i < s.size; ++i)
	{
		if (IsOperator(str[i]))
		{
			if (GetPrecedence(str[i]) > GetPrecedence(s.ch[s.top]))
				Push(&s, str[i]);
			else
			{
				while (!IsEmpty(s) && (GetPrecedence(str[i]) <= GetPrecedence(s.ch[s.top])))
				{
					st[j++] = Pop(&s);
				}
				Push(&s, str[i]);
			}
		}
		else
		{
			st[j++] = str[i];
		}
	}
	while (!IsEmpty(s))
		st[j++] = Pop(&s);
	st[j] = '\0';
	return st;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	cout << "Postfix for given expression a+b*c-d is " << PostFixCon("a+b*c-d") << endl;
	cout << "Postfix for given expression a/b*c-d is " << PostFixCon("a/b*c-d") << endl;
	cout << "Postfix for given expression a+b-c/d is " << PostFixCon("a+b-c/d") << endl;
	system("pause");
	return 0;
}

/*
Output
Postfix for given expression a+b*c-d is abc*+d-
Postfix for given expression a/b*c-d is ab/c*d-
Postfix for given expression a+b-c/d is ab+cd/-
*/

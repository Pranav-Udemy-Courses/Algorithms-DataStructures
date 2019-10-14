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
	if (c == '*' || c == '/' || c == '-' || c == '+' || c == '^' || c == '(' || c == ')')
		return true;
	return false;
}

/*-------------------------------------
   Get Precedence of the character Out
-------------------------------------*/
int GetPrecedenceOut(char c)
{
	if (c == '*' || c == '/')
		return 3;
	else if (c == '-' || c == '+')
		return 1;
	else if (c == '^')
		return 6;
	else if (c == '(')
		return 7;
	return 0;
}

/*-------------------------------------
   Get Precedence of the character In
-------------------------------------*/
int GetPrecedenceIn(char c)
{
	if (c == '*' || c == '/')
		return 4;
	else if (c == '-' || c == '+')
		return 2;
	else if (c == '^')
		return 5;
	else if (c == '(')
		return 0;
	return 0;
}

/*------------------------------------------
Convert Infix to Postfix using Associativity
------------------------------------------*/
const char* PostFixConAssoc(const char* str)
{
	Stack_s s = Create(str);
	char* st = new char[s.size + 1];
	int i = 0, j = 0;
	while (i < s.size)
	{
		if (IsOperator(str[i]))
		{
			if (GetPrecedenceOut(str[i]) > GetPrecedenceIn(s.ch[s.top]))
				Push(&s, str[i++]);
			else
			{
				if (!IsEmpty(s))
				{
					if (GetPrecedenceOut(str[i]) < GetPrecedenceIn(s.ch[s.top]))
					{
						st[j++] = Pop(&s);
					}
					else
					{
						Pop(&s);
						++i;
					}
				}
			}
		}
		else
		{
			st[j++] = str[i++];
		}
	}
	while (!IsEmpty(s))
	{
		char x = Pop(&s);
		if (x != '(')
			st[j++] = x;
	}
	st[j] = '\0';
	return st;
}

/*------------------------------------------
	  Evaluate Postfix Expression
------------------------------------------*/
int Eval(const char* str)
{
	Stack_s s = Create(str);
	int num1, num2, res;
	for (int i = 0; i < s.size; ++i)
	{
		if (IsOperator(str[i]))
		{
			num2 = Pop(&s) - '0';
			num1 = Pop(&s) - '0';
			switch (str[i])
			{
			case '+':
				res = num1 + num2;
				Push(&s, res + '0');
				break;
			case '-':
				res = num1 - num2;
				Push(&s, res + '0');
				break;
			case '*':
				res = num1 * num2;
				Push(&s, res + '0');
				break;
			case '/':
				res = num1 / num2;
				Push(&s, res + '0');
				break;
			}
		}
		else
			Push(&s, str[i]);

	}
	return Pop(&s) - '0';
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	const char* postfix = PostFixConAssoc("3*5+6/2-4");
	cout << "Postfix for given expression 3*5+6/2-4 is " << postfix << endl;
	cout << "The Postfix evaluates to : " << Eval(postfix) << endl;
	system("pause");
	return 0;
}

/*
Output
Postfix for given expression 3*5+6/2-4 is 35*62/+4-
The Postfix evaluates to : 14
*/

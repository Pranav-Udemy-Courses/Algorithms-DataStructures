#include <iostream>

using namespace std;

/* Structure of Node */
typedef struct Node_t
{
	int coeff;  // Coefficient of the term
	int pow;  // Power of the term
	Node_t* next;  // Pointer to the next node
}Node_s;

/* Find Power of a number recursively */
int PowRec(int num, int pow)
{
	if (pow == 0)
		return 1;
	return num * PowRec(num, pow - 1);
}

/* Evaluate the Polynomial */
int Evaluate(Node_s* head, int x)
{
	if (head == nullptr)
		return 0;
	int sum = 0;
	while (head != nullptr)
	{
		sum += head->coeff * PowRec(x, head->pow);
		head = head->next;
	}
	return sum;
}

/* Insert Node at the Beginning of List */
Node_s* InsertAtBeginning(Node_s* head, int coeff, int pow)
{
	Node_s* t = new Node_s;
	t->coeff = coeff;
	t->pow = pow;
	t->next = head;
	head = t;
	return head;
}

Node_s* tail = nullptr;
/* Add Node at the End */
Node_s* InsertAtEnd(Node_s* head, int coeff, int pow)
{
	Node_s* t = nullptr;
	if (head == nullptr)
	{
		t = InsertAtBeginning(head, coeff, pow);
		tail = t;
		return t;
	}
	else
	{
		t = new Node_s;
		t->coeff = coeff;
		t->pow = pow;
		t->next = nullptr;
		tail->next = t;
		tail = tail->next;
		return head;
	}
}

/* Add two Polynomials using Linked Lists */
Node_s* AddPoly(Node_s* poly1, Node_s* poly2)
{
	Node_s* res = nullptr;
	while (poly1 != nullptr && poly2 != nullptr)
	{
		if (poly1->pow > poly2->pow)
		{
			res = InsertAtEnd(res, poly1->coeff, poly1->pow);
			poly1 = poly1->next;
		}
		else if (poly1->pow < poly2->pow)
		{
			res = InsertAtEnd(res, poly2->coeff, poly2->pow);
			poly2 = poly2->next;
		}
		else
		{
			res = InsertAtEnd(res, poly1->coeff + poly2->coeff, poly1->pow);
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
	}
	while (poly1 != nullptr)
	{
		res = InsertAtEnd(res, poly1->coeff, poly1->pow);
		poly1 = poly1->next;
	}
	while (poly2 != nullptr)
	{
		res = InsertAtEnd(res, poly2->coeff, poly2->pow);
		poly2 = poly2->next;
	}
	return res;
}

/* Display the Polynomial */
void Display(Node_s* head)
{
	if (head == nullptr)return;

	while (head != nullptr)
	{
		cout << head->coeff << "x^" << head->pow << " + ";
		head = head->next;
	}
	cout << "0" << endl;
}

/* Main Method */
int main()
{
	Node_s* poly1 = nullptr;
	Node_s* poly2 = nullptr;
	cout << "Enter the number of non-zero terms in polynomial 1 : ";
	int n, coeff, pow;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter the coefficient, power of " << i + 1 << " term : ";
		cin >> coeff >> pow;
		poly1 = InsertAtEnd(poly1, coeff, pow);
	}
	cout << "Displaying the polynomial : ";
	Display(poly1);
	cout << "Above polynomial for give value 2 evaluates to : " << Evaluate(poly1, 2) << endl;
	cout << endl << endl;
	cout << "Enter the number of non-zero terms in polynomial 2 : ";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter the coefficient, power of " << i + 1 << " term : ";
		cin >> coeff >> pow;
		poly2 = InsertAtEnd(poly2, coeff, pow);
	}
	cout << endl << endl;
	cout << "Displaying Polynomial 1 : ";
	Display(poly1);
	cout << "Displaying Polynomial 2 : ";
	Display(poly2);
	cout << "Displaying Polynomial 1 + Polynomial 2 : ";
	Node_s* res = AddPoly(poly1, poly2);
	Display(res);
	system("pause");
	return 0;
}

/*
Output
Enter the number of non-zero terms in polynomial 1 : 3
Enter the coefficient, power of 1 term : 3 2
Enter the coefficient, power of 2 term : 2 1
Enter the coefficient, power of 3 term : 4 0
Displaying the polynomial : 3x^2 + 2x^1 + 4x^0 + 0
Above polynomial for give value 2 evaluates to : 20

Enter the number of non-zero terms in polynomial 2 : 4
Enter the coefficient, power of 1 term : 2 4
Enter the coefficient, power of 2 term : 3 3
Enter the coefficient, power of 3 term : 4 2
Enter the coefficient, power of 4 term : 5 1
Above polynomial for give value 1 evaluates to : 16

Displaying Polynomial 1 : 3x^2 + 2x^1 + 4x^0 + 0
Displaying Polynomial 2 : 2x^4 + 3x^3 + 4x^2 + 5x^1 + 0
Displaying Polynomial 1 + Polynomial 2 : 2x^4 + 3x^3 + 7x^2 + 7x^1 + 4x^0 + 0
*/

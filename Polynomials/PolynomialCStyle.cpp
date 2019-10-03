#include <iostream>

using namespace std;

/* Structure for each Term */
struct Term
{
	int coeff;  // coefficient of the number
	int pow;  // power of the number
};

/* Structure of Polynomial */
struct Polynomial
{
	int n;  // Number of non-zero terms
	Term* t;  // Array of terms created on Heap
};

/* Create a Polynomial */
void CreatePolynomial(Polynomial* p)
{
	cout << "Enter the number of non-zero terms : ";
	cin >> p->n;
	p->t = new Term[p->n];
	for (int i = 0; i < p->n; ++i)
	{
		cout << "Enter the coefficient and power for " << i + 1 << " term" << endl;
		cin >> p->t[i].coeff >> p->t[i].pow;
	}
}

/* Display a Polynomial */
void DisplayPolynomial(Polynomial p)
{
	for (int i = 0; i < p.n; ++i)
	{
		cout << p.t[i].coeff << "x^" << p.t[i].pow << " + ";
	}
	cout << "0" << endl;
}

/* Find Power of a given number */
int PowRec(int x, int pow)
{
	if (pow < 1)
		return 1;
	return PowRec(x, pow - 1) * x;
}

/* Evaluate value of polynomial for given x */
int EvaluatePolynomial(Polynomial p, int x)
{
	int sum = 0;
	for (int i = 0; i < p.n; ++i)
	{
		sum += PowRec(x, p.t[i].pow) * p.t[i].coeff;
	}
	return sum;
}

/* Add two polynomials */
Polynomial* AddPolynomials(Polynomial p1, Polynomial p2)
{
	int i = 0, j = 0, k = 0;
	Polynomial* res = new Polynomial();
	res->t = new Term[p1.n + p2.n];

	while (i < p1.n && j < p2.n)
	{
		if (p1.t[i].pow > p2.t[j].pow)
			res->t[k++] = p1.t[i++];
		else if (p1.t[i].pow < p2.t[j].pow)
			res->t[k++] = p2.t[j++];
		else
		{
			res->t[k].pow = p1.t[i].pow;
			res->t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
		}
	}
	for (; i < p1.n;)
		res->t[k++] = p1.t[i++];
	for (; j < p2.n;)
		res->t[k++] = p2.t[j++];
	res->n = k;
	return res;
}

/* Main Method */
int main()
{
	Polynomial p;
	CreatePolynomial(&p);
	cout << "The Polynomial p is : ";
	DisplayPolynomial(p);
	int n;
	cout << "Enter the value of x to evaluate p : ";
	cin >> n;
	cout << "The Polynomial evaluates to : " << EvaluatePolynomial(p, n) << endl;

	Polynomial p1, p2;
	CreatePolynomial(&p1);
	CreatePolynomial(&p2);
	cout << "The Polynomial p1 is : ";
	DisplayPolynomial(p1);
	cout << "The Polynomial p2 is : ";
	DisplayPolynomial(p2);
	Polynomial* res = AddPolynomials(p1, p2);
	cout << "The Polynomial p1 + p2 is : ";
	DisplayPolynomial(*res);
	system("pause");
	return 0;
}

/*
Output
Enter the number of non-zero terms : 3
Enter the coefficient and power for 1 term
2 3
Enter the coefficient and power for 2 term
4 1
Enter the coefficient and power for 3 term
6 0
The Polynomial p is : 2x^3 + 4x^1 + 6x^0 + 0
Enter the value of x to evaluate p : 2
The Polynomial evaluates to : 30
Enter the number of non-zero terms : 4
Enter the coefficient and power for 1 term
4 3
Enter the coefficient and power for 2 term
3 2
Enter the coefficient and power for 3 term
2 1
Enter the coefficient and power for 4 term
1 0
Enter the number of non-zero terms : 3
Enter the coefficient and power for 1 term
4 2
Enter the coefficient and power for 2 term
3 1
Enter the coefficient and power for 3 term
7 0
The Polynomial p1 is : 4x^3 + 3x^2 + 2x^1 + 1x^0 + 0
The Polynomial p2 is : 4x^2 + 3x^1 + 7x^0 + 0
The Polynomial p1 + p2 is : 4x^3 + 7x^2 + 5x^1 + 8x^0 + 0
*/
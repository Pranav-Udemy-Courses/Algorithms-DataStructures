/* ------------------------------------------------------------------------------------
                    Term Header (Term.hxx)
------------------------------------------------------------------------------------ */
#include <iostream>

using namespace std;

/* Class of Term*/
class Term
{
public:
    int coeff; // coefficient of the number
    int pow; // power of the number
};

/* ------------------------------------------------------------------------------------
                    Polynomial Header (Polynomial.hxx)
------------------------------------------------------------------------------------ */
#include "Term.hxx"

class Polynomial
{
public:
    /* Parameterized Constructor */
    Polynomial(int n);

    /* Destructor */
    ~Polynomial();

    /* Evaluate Polynomial for given value of x */
    int Evaluate(int x);

    /* Add Operator overloaded */
    Polynomial* operator+(const Polynomial& other);

    /* Extraction Operator overloaded */
    friend istream& operator>>(istream& is, Polynomial& p);

    /* Insertion Operator overloaded */
    friend ostream& operator<<(ostream& os, const Polynomial& p);

private:

    int n; // Number of non-zero terms
    Term* t = nullptr; // Array of terms created on Heap

    /* Returns the power of given number */
    int PowRec(int num, int pow);
};

/* ------------------------------------------------------------------------------------
                    Polynomial Implementation (Polynomial.cxx)
------------------------------------------------------------------------------------ */
#include "Polynomial.hxx"

/* --------------------------------------------------------- */
Polynomial::Polynomial(int n)
{
    this->n = n;
    this->t = new Term[n];
}

/* --------------------------------------------------------- */
Polynomial::~Polynomial()
{
    delete[] t;
    t = nullptr;
}

/* --------------------------------------------------------- */
int Polynomial::Evaluate(int x)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += PowRec(x, t[i].pow) * t[i].coeff;
    }
    return sum;
}

/* --------------------------------------------------------- */
istream& operator>>(istream& is, Polynomial& p)
{
    p.t = new Term[p.n];
    for (int i = 0; i < p.n; ++i)
    {
        cout << "Enter the coefficient and power for " << i + 1 << " term" << endl;
        cin >> p.t[i].coeff >> p.t[i].pow;
    }
    return is;
}

/* --------------------------------------------------------- */
ostream& operator<<(ostream& os, const Polynomial& p)
{
    for (int i = 0; i < p.n; ++i)
    {
        cout << p.t[i].coeff << "x^" << p.t[i].pow << " + ";
    }
    cout << "0" << endl;
    return os;
}

/* --------------------------------------------------------- */
Polynomial* Polynomial::operator+(const Polynomial& other)
{
    int i = 0, j = 0, k = 0;
    Polynomial* res = new Polynomial(n + other.n);
    res->t = new Term[n + other.n];

    while (i < n && j < other.n)
    {
        if (t[i].pow > other.t[j].pow)
            res->t[k++] = t[i++];
        else if (t[i].pow < other.t[j].pow)
            res->t[k++] = other.t[j++];
        else
        {
            res->t[k].pow = t[i].pow;
            res->t[k++].coeff = t[i++].coeff + other.t[j++].coeff;
        }
    }
    for (; i < n;)
        res->t[k++] = t[i++];
    for (; j < other.n;)
        res->t[k++] = other.t[j++];
    res->n = k;
    return res;
}

/* --------------------------------------------------------- */
int Polynomial::PowRec(int num, int pow)
{
    if (pow == 0)
        return 1;
    return PowRec(num, pow - 1) * num;
}

/* ------------------------------------------------------------------------------------
                    Main File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "Polynomial.hxx"

using namespace std;

/* Main Method */
int main()
{
    int n, n1, n2, x;
    cout << "Enter the number of non-zero terms : ";
    cin >> n;
    Polynomial p(n);
    cin >> p;
    cout << p;
    cout << "Enter the value of x to be evaluated for polynomial p : ";
    cin >> x;
    cout << "Value of polynomial p for given value x evaluates to : " << p.Evaluate(x) << endl;

    cout << "Enter the number of non-zero terms for p1: ";
    cin >> n1;
    Polynomial p1(n1);
    cin >> p1;

    cout << "Enter the number of non-zero terms for p2: ";
    cin >> n2;
    Polynomial p2(n2);
    cin >> p2;

    cout << "Printing polynomial p1 : " << p1;
    cout << "Printing polynomial p2 : " << p2;
    cout << "Printing polynomial p1 + p2 : " << *(p1 + p2);
    system("pause");
    return 0;
}

/*
Output
Enter the number of non-zero terms : 3
Enter the coefficient and power for 1 term
3 2
Enter the coefficient and power for 2 term
2 1
Enter the coefficient and power for 3 term
4 0
3x^2 + 2x^1 + 4x^0 + 0
Enter the value of x to be evaluated for polynomial p : 2
Value of polynomial p for given value x evaluates to : 20
Enter the number of non-zero terms for p1: 4
Enter the coefficient and power for 1 term
4 3
Enter the coefficient and power for 2 term
3 2
Enter the coefficient and power for 3 term
2 1
Enter the coefficient and power for 4 term
4 0
Enter the number of non-zero terms for p2: 3
Enter the coefficient and power for 1 term
4 2
Enter the coefficient and power for 2 term
3 1
Enter the coefficient and power for 3 term
6 0
Printing polynomial p1 : 4x^3 + 3x^2 + 2x^1 + 4x^0 + 0
Printing polynomial p2 : 4x^2 + 3x^1 + 6x^0 + 0
Printing polynomial p1 + p2 : 4x^3 + 7x^2 + 5x^1 + 10x^0 + 0
*/

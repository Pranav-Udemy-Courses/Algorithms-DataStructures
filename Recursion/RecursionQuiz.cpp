#include <iostream>

using namespace std;

// Question 1
int f(int n)
{
    static int i = 1;
    if (n >= 5)return n;
    n = n + i;
    i++;
    return f(n);
}

// Question 2
void foo(int n, int sum)
{
    int k = 0, j = 0;
    if (n == 0) return;
    k = n % 10;
    j = n / 10;
    sum = sum + k;
    foo(j, sum);
    printf(" % d", k);
}

// Question 3
int f(int& x, int c)
{
    c = c - 1;
    if (c == 0) return 1;
    x = x + 1;
    return f(x, c) * x;
}

// Question 4
int fun(int n)
{
    int x = 1, k;
    if (n == 1) return x;
    for (k = 1; k < n; ++k)
        x = x + fun(k) * fun(n - k);
    return x;
}

// Question 5
void count(int n)
{
    static int d = 1;
    printf("%d", n);
    printf("%d", d);
    d++;
    if (n > 1) count(n - 1);
    printf("%d", d);
}

int main()
{
    cout << f(1) << endl; // Question 1 Output : 7
    foo(2048, 0); // Quesiton 2 Output : 2 0 4 8
    cout << endl;
    int x = 5;
    int& y = x;
    cout << f(y, 5) << endl;// Question 3 Output : 6561
    cout << fun(5) << endl; // Output : 51
    count(3); // Output : 3 1 2 2 1 3 4 4 4
    cout << endl;
    system("pause");
    return 0;
}

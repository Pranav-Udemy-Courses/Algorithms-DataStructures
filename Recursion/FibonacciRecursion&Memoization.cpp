#include <iostream> 
 
using namespace std;
 
// Normal Recursive Fibonnaci method
int FibRec(int n)
{
    if (n <= 1)
        return n;
    return FibRec(n - 2) + FibRec(n - 1);
}
 
// Fibonnaci Iterative method
int FibItr(int n)
{
    int term0 = 0, term1 = 1;
    int sum = 0;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; ++i)
    {
        sum = term0 + term1;
        term0 = term1;
        term1 = sum;
    }
    return sum;
}
 
// Global Array
int F[20];
 
// Fibonnaci method with Memoization using Recursion
int FibRecMemo(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
 
    if (F[n - 2] == -1)
    {
        F[n - 2] = FibRecMemo(n - 2);
    }
    if (F[n - 1] == -1)
    {
        F[n - 1] = FibRecMemo(n - 1);
    }
    F[n] = F[n - 2] + F[n - 1]; // This step is missing at the time of explanation
    return F[n - 2] + F[n - 1];
}
int main()
{
    for (int i = 0; i < 19; ++i)
        F[i] = -1;
    cout << FibRec(6) << endl; // Output : 8 Time complexity O(2^n) keep in mind if same func is called twice with each time parameter getting decreased by 1 then complexity is O(2^n) approx.
    cout << FibItr(6) << endl; // Output : 8 Time complexity O(n)
    cout << FibRecMemo(6) << endl; // Output : 8 Time complexity O(n)
    system("pause");
    return 0;
}

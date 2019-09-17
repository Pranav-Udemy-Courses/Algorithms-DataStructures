#include <iostream> 
 
using namespace std;
 
// Iterative solution for Factorial of given number
int FactItr(int n)
{
    int res = 1;
    if (n <= 1)
        return 1;
    else
    {
        for (int i = n; i > 1; --i)
        {
            res *= i;
        }
        return res;
    }
}
 
// Recursive solution for Factorial of given number
int FactRec(int n)
{
    if (n == 0)
        return 1;
    else
        return FactRec(n - 1) * n;
}
 
int main()
{
    cout << FactRec(5) << endl; // Output : 120 Time complexity O(n) Space complexity O(n)
    cout << FactItr(5) << endl; // Output : 120 Time complexity O(n) Space complexity O(1)
    system("pause");
    return 0;
}
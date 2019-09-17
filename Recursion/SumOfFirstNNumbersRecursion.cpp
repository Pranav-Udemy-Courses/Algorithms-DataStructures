#include <iostream> 
 
using namespace std;
 
// Iterative solution
int sumItr(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += i;
    }
    return sum;
}
 
// This is example of head recursion because first call after base condition is recursive call and addition is done in return phase.
int sumRecHead(int n)
{
    if (n > 0)
        return sumRecHead(n - 1) + n;
    return 0;
}
 
// This is not tail recursion because addition operation is performed at the time of return phase
int sumRec(int n)
{
    if (n == 0)
        return 0;
    else
        return sumRec(n - 1) + n;
}
 
int main()
{
    cout << sumRec(5) << endl;     // Output : 15  time complexity O(n) space complexity O(n)
    cout << sumRecHead(5) << endl; // Output : 15  time complexity O(n) space complexity O(n)
    cout << sumItr(5) << endl;     // Output : 15  time complexity O(n) space complexity O(1)
    system("pause");
    return 0;
}
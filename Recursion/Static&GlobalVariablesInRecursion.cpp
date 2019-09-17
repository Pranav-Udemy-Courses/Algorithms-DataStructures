#include <iostream> 
 
using namespace std;
 
// Function without static/Global variable
int fun(int n)
{
    if (n > 0)
    {
        return fun(n - 1) + n; // Note : n will be added at the time of returning phase.
    }
    return 0;
}
 
// Function with static variable
int funStatic(int n)
{
    static int y = 0;
    if (n > 0)
    {
        ++y;
        return funStatic(n - 1) + y; // Note : y will be added at the time of returning phase.
    }
    return 0;
}
 
int m = 0;
// Function using Global variable
int funGlobal(int n)
{
    
    if (n > 0)
    {
        ++m;
        return funGlobal(n - 1) + m; // Note : m will be added at the time of returning phase.
    }
    return 0;
}
 
int main()
{
    int x = 5;
    cout << "Function without static variable : "  << fun(x) << endl; // Output : 15
    cout << "Function with static variable : " << funStatic(x) << endl; // Output : 25
    cout << "Function with Global variable : " << funGlobal(x) << endl; // Output : 25
    system("pause");
    return 0;
}

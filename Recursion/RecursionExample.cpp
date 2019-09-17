#include <iostream>
 
using namespace std;
 
// Ascending/Tail Recursion
void fun1(int n)
{
    if (n > 0)
    {
        cout << n;
        fun1(n - 1); // Tail Recursion because the recursive call is the last operational statement and no operation occurs during the returning phase.
    }
}
 
// Descending/Head Recursion
void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1); // Head Recursion because the recursive call is the first statement and all the processing is done after that call.
        cout << n;
    }
}
 
int main()
{
    int x = 3;
    cout << "Tail Recursion : ";
    fun1(x); // Output : 3 2 1
    cout << endl << "Head Recursion : ";
    fun2(x); // Output : 1 2 3
    cout << endl;
    system("pause");
    return 0;
}

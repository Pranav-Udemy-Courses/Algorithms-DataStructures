#include <iostream> 
 
using namespace std;
 
int fun(int d)
{
    if (d > 0)
    {
        cout << d;
        fun(d - 1);
        fun(d - 1);
    }
    return 0;
}
int main()
{
    int x = 3;
    fun(x);
    cout << endl;
    system("pause");
    return 0;
}
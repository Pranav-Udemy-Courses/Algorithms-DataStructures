#include <iostream> 
 
using namespace std;
 
double TaylorsRec(int x, int n)
{
    static double p = 1, k = 1;
    if (n == 0)
        return 1;
    double res = TaylorsRec(x, n - 1);
    p *= x;
    k *= n;
    return res + (p / k);
}
 
int main()
{
    cout << TaylorsRec(3,10) << endl;
    system("pause");
    return 0;
}
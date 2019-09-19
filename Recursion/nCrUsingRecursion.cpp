#include <iostream> 
 
using namespace std;
 
int FactRec(int n)
{
    if (n == 0)
        return 1;
    return FactRec(n - 1) * n;
}
 
int CombinationFact(int n, int r)
{
    int num, den;
    num = FactRec(n);
    den = FactRec(n - r) * FactRec(r);
    return num / den;
}
 
int CombinationRec(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    return CombinationRec(n - 1, r - 1) + CombinationRec(n - 1, r);
}
 
int main()
{
    cout << CombinationRec(4, 2) << endl; // Output : 6 Using pascals logic that nCr is n-1Cr-1 + n-1Cr
    cout << CombinationFact(4, 2) << endl; // Output : 6 Using factorial and formula nCr=!n/(!r*!(n-r))
    system("pause");
    return 0;
}

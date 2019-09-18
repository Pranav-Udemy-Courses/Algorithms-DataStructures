#include <iostream>

using namespace std;

double TaylorsHornerRec(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return s;
    s = 1 + ((double)x /(double) n) * s;
    return TaylorsHornerRec(x, n - 1);
}


int main()
{
    cout << TaylorsHornerRec(3, 10) << endl;
    system("pause");
    return 0;
}
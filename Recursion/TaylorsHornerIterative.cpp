#include <iostream>

using namespace std;

double TaylorsHornerItr(double x, double n)
{
    double s = 1;
    for (; n > 0; --n)
    {
        s = 1 + (x / n) * s;
    }
    return s;
}

int main()
{
    cout << TaylorsHornerItr(1, 10) << endl;
    system("pause");
    return 0;
}
#include <iostream> 
 
using namespace std;
 
// Recursive method to find nth power of given number m 
int PowRec(int m, int n)
{
    if (n == 0)
        return 1;
    return PowRec(m, n-1) * m;
}
 
// Smart Recursive method to find nth power of given number m 
int SmartPowRec(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return SmartPowRec(m * m, n / 2);
    else
        return m * SmartPowRec(m * m, (n - 1) / 2);
}
 
// Another Recursive approach
int AnotherPowRec(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return AnotherPowRec(m, n / 2) * AnotherPowRec(m, n / 2);
    else
        return AnotherPowRec(m, n / 2) * AnotherPowRec(m, n / 2) * m;
}
int main()
{
    cout << PowRec(2, 6) << endl; // Output : 64 Time Complexity O(n) Space Complexity O(n)
    cout << SmartPowRec(2, 6) << endl; // Output : 64 Time Complexity less than O(n) Space Complexity O(log n)
    cout << AnotherPowRec(2, 6) << endl; // Output : 64 Time Complexity O(n) Space Complexity O(log n)
    system("pause");
    return 0;
}

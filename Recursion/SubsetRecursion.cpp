#include <iostream>

using namespace std;

void SubsetRecursion(string sofar, string rest)
{
    if (rest == "")
        cout << sofar << endl;
    else
    {
        // Add to subset, remove from rest, recur
        SubsetRecursion(sofar + rest[0], rest.substr(1));
        // Don't add to subset, remove from rest, recur
        SubsetRecursion(sofar, rest.substr(1));
    }
}

void Subset(string s)
{
    SubsetRecursion("", s);
}

int main()
{
    Subset("abc");
    system("pause");
    return 0;
}

/*
Output :
abc
ab
ac
a
bc
b
c
""
*/
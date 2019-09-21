#include <iostream> 
 
using namespace std;
 
void PermuteAlphabets(string sofar, string rest)
{
    if (rest == "")
    {
        cout << sofar << endl;
    }
    else
    {
        for (int i = 0; i < rest.length(); ++i)
        {
            string next = sofar + rest[i];
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            PermuteAlphabets(next, remaining);
        }
    }
}
 
// Wrapper function
void Permute(string s)
{
    PermuteAlphabets("", s);
}
 
int main()
{
    Permute("abc");
    system("pause");
    return 0;
}
 
/*
Output
abc
acb
bac
bca
cab
cba
*/
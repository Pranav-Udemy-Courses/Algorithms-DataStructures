#include <iostream>

using namespace std;

bool IsPalindrome(string s)
{
    if (s.length() <= 1)
        return true;

    return s[0] == s[s.length() - 1] && IsPalindrome(s.substr(1, s.length() - 2));
}

int main()
{
    cout << std::boolalpha <<IsPalindrome("wasitacaroracatisaw") << endl; // Output : True
    cout << std::boolalpha << IsPalindrome("naam") << endl; // Output : False
    system("pause");
    return 0;
}

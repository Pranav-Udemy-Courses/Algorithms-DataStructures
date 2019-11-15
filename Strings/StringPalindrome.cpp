#include <iostream>

using namespace std;

// Function to find Length of given String
size_t StringLength(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return i;
}

// Function to check if given string is Palindrome or not
bool IsPalindrome(char str[])
{
	int lo = 0;
	int hi = strlen(str) - 1;
	while (hi > lo)
	{
		if (str[lo] != str[hi])
			return false;
		++lo;
		--hi;
	}
	return true;
}

// Main Method
int main()
{
	char* str = const_cast<char*>("wasitacaroracatisaw");
	cout << "Is " << str << " a palindrome ? : " << boolalpha << IsPalindrome(str) << endl;
	str = const_cast<char*>("pranavshah");
	cout << "Is " << str << " a palindrome ? : " << boolalpha << IsPalindrome(str) << endl;
	return 0;
}

/*
Output

Is wasitacaroracatisaw a palindrome ? : true

Is pranavshah a palindrome ? : false

*/

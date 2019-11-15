#include <iostream>

using namespace std;

// Find Occurrences of character in given string i.e. aaabbcccc : a3b2c4
void FindOccurrences(const char* str)
{
	int hash[26]{ 0 };
	while (*str != '\0')
	{
		hash[*str - 97]++;
		++str;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (hash[i] > 0)
			cout << static_cast<char>(i + 97) << hash[i];
	}
	cout << endl;
}


// Main Method
int main()
{
	FindOccurrences("aaabbbbcc");
	return 0;
}

/*

Output

a3b4c2

*/

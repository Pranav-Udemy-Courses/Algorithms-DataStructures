#include<iostream>

using namespace std;

// Merge two Strings alternatively
void MergeStrings(const char* s1, const char* s2, char* output)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		*output = *s1;
		++output; ++s1;
		*output = *s2;
		++output; ++s2;
	}
	while (*s1 != '\0')
	{
		*output = *s1;
		++output; ++s1;
	}
	while (*s2 != '\0')
	{
		*output = *s2;
		++output; ++s2;
	}
	*output = '\0';
}

// Main Method
int main()
{
	char str1[]{ "Pranav" };
	char str2[]{ "1234" };
	char* output = new char[strlen(str1) + strlen(str2) + 1];
	cout << "String 1 is : " << str1 << endl;
	cout << "String 2 is : " << str2 << endl;
	MergeStrings(str1, str2, output);
	cout << "String 1 + String 2 is : " << output << endl;
	delete[] output;
	output = nullptr;
	return 0;
}

/*
Output

String 1 is : Pranav

String 2 is : 1234

String 1 + String 2 is : P1r2a3n4av

*/

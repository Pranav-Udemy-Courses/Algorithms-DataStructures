#include <iostream>

using namespace std;

// Converting String to Integer
void StringToInteger(const char* str)
{
	int result = 0;
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
		{
			cout << "Can't be converted to integer !!!" << endl;
			return;
		}
		else
		{
			result = (result * 10) + *str - 48;
		}
		++str;
	}
	cout << "Converted to " << result << endl;
}

// Main Method
int main()
{
	StringToInteger("123570");
	return 0;
}

/*

Output

Converted to 123570

*/

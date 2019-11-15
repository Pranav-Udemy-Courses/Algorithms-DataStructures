#include <iostream>

using namespace std;

/*
	Print cool if divisible by 5
	Print dude if divisible by 11
	Print cool dude if divisible by 5 & 11
	Else print number
*/
void CoolDude()
{
	int n = 100;
	while (n < 501)
	{
		bool byFive = n % 5 ? false : true;
		bool byEleven = n % 11 ? false : true;
		if (byFive || byEleven)
		{
			if (byFive)
			{
				cout << "cool";
				if (byEleven)
					cout << " dude";
				cout << endl;
			}
			else
				cout << "dude" << endl;
		}
		else
			cout << n << endl;
		++n;
	}
}

// Main Method
int main()
{
	CoolDude();
	return 0;
}

/*

Output

cool
101
102
103
104
cool
106
107
108
109
cool dude
111
112
113
114
cool
116
117
118
119
cool
dude
122

*/

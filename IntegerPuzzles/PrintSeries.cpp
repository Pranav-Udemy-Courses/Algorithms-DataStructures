#include <iostream>

using namespace std;

// Print Series in form 50,51,52,53,54,55,40,41,42,43,44,45.....10,11,12,13,14,15
void PrintSeries(int n)
{
	while (n)
	{
		for (int i = 0, j = n * 10; i < 6; ++i, ++j)
			cout << " " << j;
		--n;
	}
}

// Main Method
int main()
{
	PrintSeries(5);
	return 0;
}

/*

Output

50 51 52 53 54 55 40 41 42 43 44 45 30 31 32 33 34 35 20 21 22 23 24 25 10 11 12 13 14 15

*/

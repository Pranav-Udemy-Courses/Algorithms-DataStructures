#include <iostream>

using namespace std;

// Print sum of integers of given number i.e. 1234 = 1 + 2 + 3 + 4 = 10
int SumOfIntegers(int n)
{
	int sum = 0;
	while (n / 10 != 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	return sum + n;
}

// Main Method
int main()
{
	int n = 12345;
	cout << "The sum of integers of " << n << " is : " << SumOfIntegers(n) << endl;
	return 0;
}

/*

Output

The sum of integers of 12345 is : 15

*/

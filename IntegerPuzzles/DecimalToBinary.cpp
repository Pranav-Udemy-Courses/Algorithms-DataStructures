#include <iostream>
#include <stack>

using namespace std;

// Convert Decimal To Binary
void DecimalToBinary(int n)
{
	cout << "The decimal " << n << " has its binary equivalent as : ";
	stack<int> s;
	while (n / 2 != 0)
	{
		s.push(n % 2);
		n /= 2;
	}
	s.push(n);
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

// Main Method
int main()
{
	DecimalToBinary(2);
	DecimalToBinary(5);
	DecimalToBinary(7);
	DecimalToBinary(9);
	DecimalToBinary(32);
	return 0;
}

/*

Output

The decimal 2 has its binary equivalent as : 10
The decimal 5 has its binary equivalent as : 101
The decimal 7 has its binary equivalent as : 111
The decimal 9 has its binary equivalent as : 1001
The decimal 32 has its binary equivalent as : 100000

*/

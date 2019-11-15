#include <iostream>

using namespace std;

// Print Stars in shape of Diamond
void PrintDiamondOfStars(int n)
{
	int stars = 1;
	int spaces = n - 1;
	for (int i = 1; i < n*2; ++i)
	{
		for (int j = 1; j <= spaces; ++j)
			cout << " ";
		for (int j = 1; j < stars * 2; ++j)
			cout << "*";
		cout << endl;
		if (i < n)
		{
			--spaces; 
			++stars;
		}
		else
		{
			--stars;
			++spaces;
		}
	}
}

// Main Method
int main()
{
	PrintDiamondOfStars(5);
	return 0;
}

/*

Output

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *

*/

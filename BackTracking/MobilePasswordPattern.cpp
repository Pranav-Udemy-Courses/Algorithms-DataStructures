#include<iostream>
#include<string>

using namespace std;

/* Global Variables */
string ans;

/* Get cell no from row and col */
char GetCellNo(int row, int col)
{
	return (char)((3 * row + col)+65);
}

/* Check if the pattern unlocks your phone */
bool UnlockPattern(int** VisitedArr, int currRow, int currCol, string res, string patt)
{
	if (res == patt)
	{
		ans = res;
		return true;
	}

	for (int i = currRow - 1; i < currRow + 2; ++i)
	{
		for (int j = currCol - 1; j < currCol + 2; ++j)
		{
			if ((i >= 0 && i <= 2) && (j >= 0 && j <= 2) && VisitedArr[i][j] == 0)
			{
				res += GetCellNo(i, j);
				VisitedArr[i][j] = 1;
				if (UnlockPattern(VisitedArr, i, j, res, patt))
					return true;
				res = res.substr(0, res.length() - 1);
			}
		}
	}
	VisitedArr[currRow][currCol] = 0;
	return false;
}

/* Pattern can start from any of the dot */
bool PatternUnlock(string patt)
{
	int StartArr[3][3]{ 0 };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int** VisitedArr = new int*[3];
			for (int i = 0; i < 3; ++i)
				VisitedArr[i] = new int[3]{ 0 };
			ans = GetCellNo(i,j);
			StartArr[i][j] = 1;
			VisitedArr[i][j] = 1;
			if (UnlockPattern(VisitedArr, i, j, ans, patt))
				return true;
			for (int i = 0; i < 3; ++i)
				delete[] VisitedArr[i];
		}
	}
	return false;
}

/* Main Method */
int main()
{
	cout << "Consider the mobile screen pattern as follows : " << endl;
	int number = 1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j, ++number)
		{
			cout << number << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	cout << "Corresponding encrypted pattern as follows : " << endl;
	int num = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j, ++num)
		{
			cout << char(num+65) << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	string pattern;
	cout << "Enter the encrypted pattern : ";
	cin >> ws;
	getline(cin, pattern);
	if (PatternUnlock(pattern))
	{
		cout << endl << "Your password has been cracked!!! Phone got unlocked using the following combination : ";
		for (int i = 0; i < ans.length(); ++i)
			cout << ans[i] - 'A' + 1 << "  ";
		cout << endl << endl;
	}
	else
		cout << endl << "You have entered an invalid pattern !!!" << endl << endl;
	return 0;
}


/* 

Output

Consider the mobile screen pattern as follows :
1 2 3
4 5 6
7 8 9


Corresponding encrypted pattern as follows :
A B C
D E F
G H I


Enter the encrypted pattern : AECFHGD

Your password has been cracked!!! Use the following combination to unlock your phone : 1  5  3  6  8  7  4

Enter the encrypted pattern : AIFC

You have entered an invalid pattern !!! (As we can't reach from A to I directly)

Enter the encrypted pattern : AECE

You have entered an invalid pattern !!! (As same dot can't be repeated here E)

Enter the encrypted pattern : ECBDGHFI

Your password has been cracked!!! Use the following combination to unlock your phone : 5  3  2  4  7  8  6  9

*/

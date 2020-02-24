#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/* LCS Recursive implementation */
int LCSRec(string s1, int i, string s2, int j)
{
	if (i >= s1.length() || j >= s2.length())
		return 0;
	if (s1[i] == s2[j])
		return 1 + LCSRec(s1, i + 1, s2, j + 1);
	else
		return max(LCSRec(s1, i + 1, s2, j), LCSRec(s1, i, s2, j + 1));
}

/* Wrapper method */
int LCSNormal(string s1, string s2)
{
	return LCSRec(s1, 0, s2, 0);
}

/* Print the 2D matrix to understand LCS logic */
void PrintTable(vector<vector<int>>& A, string& s1, string& s2)
{
	cout << "      ";
	for (auto m = 1; m <= s2.length(); ++m)
		cout << s2[m - 1] << "  ";
	cout << endl;
	for (auto i=0; i <= s1.length(); ++i)
	{
		if (i > 0)
			cout << s1[i - 1] << "  ";
		else
			cout << "   ";
		for (auto j= 0; j <= s2.length(); ++j)
		{
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

/* Print the common sebsequence */
void PrintLCS(vector<vector<int>>& A,string s1, int n, int m)
{
	stack<char> s;
	for (int i = n - 1; i > 0; --i)
	{
		bool include = true;
		int t = m - 1;
		for (int j = m - 1; j > 0; --j)
		{
			if (A[i][t] == A[i - 1][j])
			{
				include = false;
				break;
			}
		}
		--t;
		if (include)
			s.push(s1[i - 1]);
	}
	cout << endl << "The common substring is : ";
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl << endl;
}

/* LCS using DP */
int LCSDP(string s1, string s2)
{
	int n = s1.length()+1;
	int m = s2.length()+1;
	vector<vector<int> > A(n, vector<int>(m, 0));
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			A[i][j] = A[i - 1][j - 1];
			if (s1[i-1] == s2[j-1]) // Here since string index start at 0 we will do i-1 and j-1
				A[i][j]++;
			if (A[i][j - 1] > A[i][j])
				A[i][j] = A[i][j - 1];
			if (A[i - 1][j] > A[i][j])
				A[i][j] = A[i - 1][j];
		}
	}
	PrintTable(A, s1, s2);
	PrintLCS(A, s1, n, m);
	return A[n-1][m-1];
}

/* Main method */
int main()
{
	string s1, s2;
	cout << "Enter the string 1 : ";
	getline(cin, s1);
	cout <<"String 1 : " << s1 << endl;
	cout << "Enter the string 2 : ";
	getline(cin, s2);
	cout <<"String 2 : " << s2 << endl;
	cout << "The longest common subsequence using Recursive method is of length : " << LCSNormal(s1, s2) << endl << endl;
	cout << "The longest common subsequence using DP is of length : " << LCSDP(s1, s2) << endl << endl;
	return 0;
}

/*
Output
Enter the string 1 : GXTXAYB
String 1 : GXTXAYB
Enter the string 2 : AGGTAB
String 2 : AGGTAB
The longest common subsequence using Recursive method is of length : 4
      A  G  G  T  A  B
   0  0  0  0  0  0  0
G  0  0  1  1  1  1  1
X  0  0  1  1  1  1  1
T  0  0  1  1  2  2  2
X  0  0  1  1  2  2  2
A  0  1  1  1  2  3  3
Y  0  1  1  1  2  3  3
B  0  1  1  1  2  3  4


The common substring is : G T A B

The longest common subsequence using DP is of length : 4

*/
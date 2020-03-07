#include<iostream>
#include <string>

using namespace std;

/* String Permutations using Backtracking */
void StringPermutation(string curr, string rem)
{
	if (rem.empty())
	{
		cout << curr << endl;
		return;
	}

	for (int i = 0; i < rem.length(); ++i)
	{
		string temp = curr + rem[i];
		StringPermutation(temp, rem.substr(0, i) + rem.substr(i + 1));
	}
}

/* Wrapper Method Permute */
void Permute(string str)
{
	cout << "The following are the possibilities with the given string " << str << endl;
	if (str.empty())
		return;
	StringPermutation("", str);
}

/* Main Method */
int main()
{
	string str;
	cout << "Enter the String : " << endl;
	cin >> ws;
	getline(cin, str);
	Permute(str);
	return 0;
}

/*

Output

Enter the String :
abc
The following are the possibilities with the given string abc
abc
acb
bac
bca
cab
cba

*/

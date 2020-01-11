#include<iostream>
#include<vector>
#include<algorithm>

#define INF 2000000000

using namespace std;

vector<int> coinsVec;

/* -----------------------------------
 Check if amount is greater than coin
----------------------------------- */
bool CheckCoin(int amount, int coin)
{
	if (coin <= amount)
		return true;
	return false;
}

/* -------------------------------------------
 Check all possiblities and get minimum coins
------------------------------------------- */
int CoinRec(vector<int>& coins, int amount)
{
	if (coins.empty())
		return -1;

	if (amount == 0)
		return 0;

	if (coinsVec[amount] != -1)
		return coinsVec[amount];

	int ans = INF;

	for (int i = coins.size() - 1; i >= 0; --i)
	{
		if (CheckCoin(amount, coins[i]))
		{
			ans = min(ans, CoinRec(coins, amount - coins[i]));
		}
	}

	coinsVec[amount] = ans + 1;
	return coinsVec[amount];
}

/* -------------------------------------------------------------
 Finds minimum number of coins required to satiate given amount
------------------------------------------------------------- */
int CoinChange(vector<int>& coins, int amount)
{
	coinsVec.resize(amount + 1, -1);
	sort(coins.begin(), coins.end());
	int ans = CoinRec(coins, amount);
	return ans >= INF ? -1 : ans;
}

/* -----------
 Main Method
------------*/
int main()
{
	vector<int> coins{ 1, 2, 5 };
	cout << "Minimum number of coins required for 11 is : " << CoinChange(coins, 11) << endl; 
	cout << "Minimum number of coins required for 20 is : " << CoinChange(coins, 20) << endl;
	cout << "Minimum number of coins required for 13 is : " << CoinChange(coins, 13) << endl;
	return 0;
}

/*
Output
Minimum number of coins required for 11 is : 3
Minimum number of coins required for 20 is : 4
Minimum number of coins required for 13 is : 4
*/

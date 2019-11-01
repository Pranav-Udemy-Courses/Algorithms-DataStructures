#include <iostream>
#define I INT_MAX

using namespace std;

/*-------------------------------------
	   Prims Algorithm
-------------------------------------*/
void PrimsAlgo()
{
	int cost[][8]
	{
		{I,I,I,I,I,I,I,I},
		{I,I,25,I,I,I,5,I},
		{I,25,I,12,I,I,I,10},
		{I,I,12,I,8,I,I,I},
		{I,I,I,8,I,16,I,14},
		{I,I,I,I,16,I,20,18},
		{I,5,I,I,I,20,I,I},
		{I,I,10,I,14,18,I,I}
	};

	int near[8] = { I,I,I,I,I,I,I,I };
	int t[2][6];
	int min = I;
	int u, v;
	int n = 7;

	// Find the minimum edge
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			if (cost[i][j] < min)
			{
				min = cost[i][j];
				u = i;
				v = j;
			}
		}
	}
	t[0][0] = u;
	t[1][0] = v;
	near[u] = near[v] = 0;

	// Update the near array
	for (int i = 1; i <= n; i++)
	{
		if (near[i] != 0)
		{
			if (cost[i][u] < cost[i][v])
				near[i] = u;
			else
				near[i] = v;
		}
	}

	// Repeat steps such that all elements in array t are filled
	for (int i = 1; i < n - 1; ++i)
	{
		min = I; int k = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (near[j] != 0 && cost[j][near[j]] < min)
			{
				k = j;
				min = cost[j][near[j]];
			}
		}
		t[0][i] = k;
		t[1][i] = near[k];
		near[k] = 0;

		for (int j = 1; j <= n; ++j)
		{
			if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
				near[j] = k;
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		cout << "(" << t[0][i] << "," << t[1][i] << ")   ";
	}
	cout << endl << endl;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	cout << "The Output of Prims Algorithm is : ";
	PrimsAlgo();
	system("pause");
	return 0;
}

/*
Output

The Output of Prims Algorithm is : (1,6)   (5,6)   (4,5)   (3,4)   (2,3)   (7,2)

*/

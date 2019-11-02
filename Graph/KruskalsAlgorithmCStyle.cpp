#include <iostream>

using namespace std;

#define I INT16_MAX

/* -----------------------------------
	Array for Edges
	Row 0: start vertex
	Row 1: end vertex
	Row 2: weight of the edge
----------------------------------- */
int edges[3][9]
{
	{1,1,2,2,3,4,4,5,5},
	{2,6,3,7,4,5,7,6,7},
	{28,10,16,14,12,22,18,25,24}
};

/* -------------------------------
	Result array
	Row 0: start vertex
	Row 1: end vertex
------------------------------- */
int t[2][6];

/* ----------------------------------
	Set array
	Row 0: parent of each node
---------------------------------- */
int set[8]{ -1 };

/* ---------------------------------------
	Included array
	Row 0: 1 means included else not
--------------------------------------- */
int included[9]{ 0 };

/* ----------------------------------------
    Find : Returns parent of given node
---------------------------------------- */
int Find(int u)
{
	int x = u, v = 0;
	while (set[x] > 0)
		x = set[x];

	while (u != x)
	{
		v = set[u];
		set[u] = x;
		u = v;
	}
	return x;
}

/* ----------------------------------------
    Union : Combine two disjoint sets
---------------------------------------- */
void Union(int u, int v)
{
	if (set[u] < set[v])
	{
		set[u] = set[u] + set[v];
		set[v] = u;
	}
	else
	{
		set[v] = set[u] + set[v];
		set[u] = v;
	}
}

/* -------------------------------
	Kruskals Algorithm
------------------------------- */
void Kruskal()
{
	int i = 0, k, u, v, n = 7, e = 9;
	while (i < n - 1)
	{
		int min = I;
		for (int j = 0; j < e; ++j)
		{
			if (included[j] == 0 && edges[2][j] < min)
			{
				min = edges[2][j];
				k = j;
			}
		}
		u = edges[0][k];
		v = edges[1][k];

		if (Find(u) != Find(v))
		{
			t[0][i] = u;
			t[1][i] = v;
			Union(Find(u), Find(v));
			i++;
		}
		included[k] = 1;
	}

	cout << "The Minimum Spanning tree using Kruskals Algorithm is :  ";
	for (int m = 0; m < n - 1; m++)
	{
		cout << "(" << t[0][m] << ", " << t[1][m] << ")   ";
	}
	cout << endl << endl;
}

/* -------------------------------
	Main Method
------------------------------- */
int main()
{
	Kruskal();
	system("pause");
	return 0;
}

/*
Output

The Minimum Spanning tree using Kruskals Algorithm is :  (1, 6)   (3, 4)   (2, 7)   (2, 3)   (4, 5)   (5, 6)

*/

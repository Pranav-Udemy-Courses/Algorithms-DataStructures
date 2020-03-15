#include<iostream>

using namespace std;

// Global Variables
int numOfNodes;
int numOfColor = 2;

/* Is Safe to Place Color */
bool IsSafeColor(int** G,int iNode, int* Color, int col)
{
	for (int i = 0; i < numOfNodes; ++i)
	{
		if (G[iNode][i] == 1 && Color[i] == col)
			return false;
	}
	return true;
}

/* Is Bipartite Graph */
bool IsBipartiteGraph(int** G, int iNode, int* Color)
{
	if (iNode == numOfNodes)
		return true;

	for (int i = 1; i <= numOfColor; ++i)
	{
			if (IsSafeColor(G, iNode, Color, i))
			{
				Color[iNode] = i;
				if (IsBipartiteGraph(G, iNode+1, Color))
					return true;
				Color[iNode] = -1;
			}
	}
	return false;
}

/* Bipartite Graph */
void BipartiteGraph(int** G)
{
	int* Color = new int[numOfNodes] {0};
	if (IsBipartiteGraph(G, 0, Color))
		cout << "It's a Bipartite Graph " << endl << endl;
	else
		cout << "It's not a Bipartite Graph " << endl << endl;
	delete[] Color;
}

/* Main Method */
int main()
{
	cin >> numOfNodes;
	int** G = new int* [numOfNodes];
	for (int i = 0; i < numOfNodes; ++i)
		G[i] = new int[numOfNodes] {0};
	for (int i = 0; i < numOfNodes; ++i)
	{
		for (int j = 0; j < numOfNodes; ++j)
		{
			cin >> ws;
			cin >> G[i][j];
		}
	}
	BipartiteGraph(G);
	for (int i = 0; i < numOfNodes; ++i)
		delete[] G[i];
	return 0;
}

/*

Output 
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

It's a Bipartite Graph

4
0 1 0 1
1 0 1 1
0 1 0 1
1 1 1 0

It's not a Bipartite Graph

*/

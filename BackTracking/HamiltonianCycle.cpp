#include<iostream>

using namespace std;

#define V 5

/* Global variables */
int visited[V]{ 0 };

/* Check if all Nodes visited */
bool AllNodesVisited()
{
	for (int i = 0; i < V; ++i)
	{
		if (visited[i] == 0)
			return false;
	}
	return true;
}

/* Backtrack and Check for Hamiltonian Cycle */
bool HamiltonianUtilCycle(int G[V][V], int* ans,int m, int currentNode, int startNode)
{
	visited[currentNode] = 1;
	if (AllNodesVisited() && G[currentNode][startNode] == 1)
	{
		cout << "Hamilton Cycle exists : " << endl;
		for (int i = 0; i < V; ++i)
			cout << ans[i] << " ";
		cout << endl << endl;
		return true;
	}

	for (int i = 0; i < V; ++i)
	{
		if (!visited[i] && G[currentNode][i] == 1)
		{
			ans[m] = i;
			if (HamiltonianUtilCycle(G, ans, m + 1, i, startNode))
				return true;
			ans[m] = -1;
		}
	}
	return false;
}

/* Hamiltonian Cycle */
void HamiltonianCycle(int G[V][V])
{
	int* ans = new int[V] {-1};
	ans[0] = 0;
	if (!HamiltonianUtilCycle(G, ans, 0, 0, 0))
		cout << "Hamiltonian Cycle doesn't exists" << endl << endl;
	delete[] ans;
}

/* Main Method */
int main()
{
	int graph1[V][V] = 
	{ 
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{0, 1, 1, 1, 0} 
	};
	HamiltonianCycle(graph1);

	int graph2[V][V] = 
	{ 
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 0, 1},
		{1, 1, 0, 0, 0},
		{0, 1, 1, 0, 0} 
	};
	HamiltonianCycle(graph2);

	return 0;
}

/*

Graph1
(0)--(1)--(2)
 |   / \   |
 |  /   \  |
 | /     \ |
(3)-------(4)

Graph2
(0)--(1)--(2)
 |   / \   |
 |  /   \  |
 | /     \ |
(3)      (4)

Output

Hamilton Cycle exists for graph1 :
1 2 4 3 0

Hamiltonian Cycle doesn't exists for graph2

*/

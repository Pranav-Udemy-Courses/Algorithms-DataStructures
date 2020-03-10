#include<iostream>

using namespace std;

#define V 4

/* Check if the selected color already allocated */
bool IsSafe(int G[V][V], int iNode, int* color, int c)
{
	for (int i = 0; i < V; ++i)
	{
		if (G[iNode][i] == 1 && color[i] == c)
			return false;
	}
	return true;
}

/* Check if Coloring Scheme is possible */
bool GraphColoringUtil(int G[V][V], int m, int* color, int iNode)
{
	if (iNode == V)
		return true;

	for (int i = 1; i <= m; ++i)
	{
		if (IsSafe(G, iNode, color, i))
		{
			color[iNode] = i;
			if (GraphColoringUtil(G, m, color, iNode + 1))
				return true;
			color[iNode] = 0;
		}
	}
	return false;
}

/* Wrapper method for Graph Coloring */
void GraphColor(int G[V][V], int m)
{
	int* color = new int[V] {0};
	if(GraphColoringUtil(G, m, color, 0))
	{
		cout << endl << "Solution is possible with atmost " << m << " colors " << endl << endl;
		for (int i = 0; i < V; ++i)
			cout << "Node " << i + 1 << " : Color " << color[i] << endl;
		cout << endl;
	}
	else
		cout << endl << "No solution is possible with atmost " << m << " colors " << endl << endl;
}

/* Main Method */
int main()
{
	int graph[V][V] = 
	{ 
		{0, 1, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 1},
		{1, 0, 1, 0}
	};
	int m;
	cout << "Enter the maximum number of colors : ";
	cin >> m;
	GraphColor(graph, m);
	return 0;
}

/*
	  (3)---(2)
	   |   / |
	   |  /  |
	   | /   |
	  (0)---(1)

Output

Enter the maximum number of colors : 3

Solution is possible with atmost 3 colors

Node 1 : Color 1
Node 2 : Color 2
Node 3 : Color 3
Node 4 : Color 2

Enter the maximum number of colors : 2

No solution is possible with atmost 2 colors

*/

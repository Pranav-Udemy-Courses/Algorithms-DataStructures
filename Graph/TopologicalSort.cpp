#include<iostream>
#include<stack>

using namespace std;

/* Global Variables */
int visited[6]{ 0 };
stack<int> s;

/* Topological Sort */
void TopoSort(int G[][6], int val)
{
	visited[val] = 1;
	for (int i = 0; i < 6; ++i)
	{
		if (!visited[i] && G[val][i] == 1)
		{
			TopoSort(G, i);
		}
	}
	s.push(val);
}

/* Wrapper method for Topological Sort */
void TopoLogicalSort(int G[][6])
{
	for (int i = 0; i < 6; ++i)
	{
		if (!visited[i])
			TopoSort(G, i);
	}
	cout << "The Topological Sort order is : " << endl;
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl << endl;
}


/* Main Method */
int main()
{
	int G[6][6] 
	{
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0},
		{1, 0, 1, 0, 0, 0}
	};
	TopoLogicalSort(G);
	return 0;
}

/*

Output

The Topological Sort order is :
5 4 2 3 1 0

Application :
Deciding the build dependencies. 

*/

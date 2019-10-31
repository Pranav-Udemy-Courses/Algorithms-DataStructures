#include <iostream>
#include <queue>

using namespace std;

/*-------------------------------------
	Depth First Search
-------------------------------------*/
void DFS(int G[][7], int element)
{
	static int visited[7]{ 0 };
	cout << element << "   ";
	visited[element] = 1;
	for (int i = 1; i < 7; i++)
	{
		if (G[element][i] == 1 && visited[i] == 0)
		{
			DFS(G, i);
		}
	}
}

/*-------------------------------------
	Breadth First Search
-------------------------------------*/
void BFS(int G[][7], int startElement)
{
	std::queue<int> q;
	int arr[7]{ 0 };
	cout << "BFS with start element " << startElement << " is : " << startElement << "   ";
	q.push(startElement);
	arr[startElement] = 1;
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		for (int j = 1; j < 7; j++)
		{
			if (G[i][j] == 1 && arr[j] == 0)
			{
				cout << j << "   ";
				arr[j] = 1;
				q.push(j);
			}
		}
	}
	cout << endl << endl;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int G[7][7]
	{
		{0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,1,0,0,1,0,0},
		{0,1,0,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	};

	BFS(G, 1);
	BFS(G, 4);
	BFS(G, 5);
	BFS(G, 6);

	cout << "DFS with start element " << 1 << " is : ";
	DFS(G, 1);
	cout << endl << endl;

	system("pause");
	return 0;
}

/*
Output

BFS with start element 1 is : 1   2   3   4   5   6

BFS with start element 4 is : 4   2   3   5   6   1

BFS with start element 5 is : 5   4   2   3   6   1

BFS with start element 6 is : 6   4   2   3   5   1

DFS with start element 1 is : 1   2   4   3   5   6

*/

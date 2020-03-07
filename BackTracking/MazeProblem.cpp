#include<iostream>

using namespace std;

/* Structure of Node */
typedef struct Node_t
{
	int row;
	int col;
	Node_t* next;
}Node_s;

/* Global variables */
Node_s* headNode = nullptr;
int mSize;

/* Insert the element in the linkedList */
Node_s* Insert(int row, int col, Node_s* head)
{
	Node_s* temp = new Node_s;
	temp->row = row;
	temp->col = col;
	temp->next = head;
	head = temp;
	return head;
}

/* Print the path from source to destination */
void PrintPath(Node_s* head)
{
	if (head)
	{
		cout << endl << "Hurrah... You found the Path from Source to Destination : " << endl << endl;
		while (head)
		{
			Node_s* temp = head->next;
			cout << "( " << head->row << ", " << head->col << " )" << endl;
			delete head;
			head = temp;
		}
		cout << endl;
	}
	else
		cout << endl << "There is no way to get to the destination. You are trapped !!!" << endl << endl;
}

/* Find the path to reach the end of the maze */
bool FindPathInMaze(int** M, int row, int col, Node_s** head)
{
	if (row == col && row == (mSize - 1))
	{
		*head = Insert(row, col, *head);
		return true;
	}

	if (M[row][col])
	{
		if (col < mSize-1 && FindPathInMaze(M, row, col + 1, head))
		{
			*head = Insert(row, col, *head);
			return true;
		}
		else if (row < mSize - 1 && FindPathInMaze(M, row + 1, col, head))
		{
			*head = Insert(row, col, *head);
			return true;
		}
	}
	return false;
}

/* Main Method */
int main()
{
	int mVal;
	cout << "Enter the size of maze : ";
	cin >> mSize;
	int** M = new int* [mSize];
	for (int i = 0; i < mSize; ++i)
		M[i] = new int[mSize] {0};
	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			cout << "Enter the value for M[" << i + 1 << "][" << j + 1 << "] :";
			cin >> mVal;
			if (mVal)
				M[i][j] = mVal;
		}
	}
	if (FindPathInMaze(M, 0, 0, &headNode))
		PrintPath(headNode);
	for (int i = 0; i < mSize; ++i)
		delete[] M[i];
	return 0;
}

/*

Output

Enter the size of maze : 4
Enter the value for M[1][1] :1
Enter the value for M[1][2] :0
Enter the value for M[1][3] :0
Enter the value for M[1][4] :0
Enter the value for M[2][1] :1
Enter the value for M[2][2] :1
Enter the value for M[2][3] :0
Enter the value for M[2][4] :1
Enter the value for M[3][1] :0
Enter the value for M[3][2] :1
Enter the value for M[3][3] :0
Enter the value for M[3][4] :0
Enter the value for M[4][1] :1
Enter the value for M[4][2] :1
Enter the value for M[4][3] :1
Enter the value for M[4][4] :1

Hurrah... You found the Path from Source to Destination :

( 0, 0 )
( 1, 0 )
( 1, 1 )
( 2, 1 )
( 3, 1 )
( 3, 2 )
( 3, 3 )

*/

/* ------------------------------------------------------------------------------------
			  Node Header (Node.hxx)
------------------------------------------------------------------------------------ */
#include <iostream>

using namespace std;

/* Class Node */
class Node
{
public:
	int data; // Data to be stored
	Node* left; // Pointer to left child
	Node* right; // Pointer to right child
};

/* ------------------------------------------------------------------------------------
			  Tree Header (Tree.hxx)
------------------------------------------------------------------------------------ */
#include "Node.hxx"
#include <queue>

/* Class Tree */
class Tree
{
private:
	Node* root; // Pointer to start of Tree
public:

	// Default Constructor
	Tree();

	// Create a Binary Tree
	Node* Create();

	// Display Tree Using PreOrder
	void PreOrder(Node* root);

	// Display Tree Using InOrder
	void InOrder(Node* root);

	// Display Tree Using PostOrder
	void PostOrder(Node* root);

	// Display Tree Using LevelOrder
	void LevelOrder(Node* root);

	// Count All Nodes
	int CountNodes(Node* root);

	// Count All Nodes with Degree 2
	int CountNodes2(Node* root);

	// Count All Nodes with Degree 1
	int CountNodes1(Node* root);

	// Count All Nodes with Degree 0
	int CountNodes0(Node* root);

	// Height of Tree
	int Height(Node* root);

	// Destructor
	~Tree();

};

/* ------------------------------------------------------------------------------------
			Tree Implementation (Tree.cxx)
------------------------------------------------------------------------------------ */
#include "Tree.hxx"

/* ----------------------------------- */
Tree::Tree()
{
	root = nullptr;
}

/* ----------------------------------- */
Node* Tree::Create()
{
	Node* p = nullptr;
	Node* temp = new Node;
	cout << "Enter the root element : ";
	cin >> temp->data;
	temp->left = temp->right = nullptr;
	root = p = temp;
	queue<Node*> q;
	q.push(root);
	int x;
	while (!q.empty())
	{
		p = q.front();
		q.pop();

		cout << "Enter the left element of " << p->data << " : ";
		cin >> x;
		if (x != -1)
		{
			temp = new Node;
			temp->data = x;
			temp->left = temp->right = nullptr;
			p->left = temp;
			q.push(p->left);
		}

		cout << "Enter the right element of " << p->data << " : ";
		cin >> x;
		if (x != -1)
		{
			temp = new Node;
			temp->data = x;
			temp->left = temp->right = nullptr;
			p->right = temp;
			q.push(p->right);
		}
	}
	return root;
}

/* ----------------------------------- */
void Tree::PreOrder(Node* root)
{
	if (root == nullptr)
		return;
	cout << root->data << "  ";
	PreOrder(root->left);
	PreOrder(root->right);
}

/* ----------------------------------- */
void Tree::InOrder(Node* root)
{
	if (root == nullptr)
		return;
	InOrder(root->left);
	cout << root->data << "  ";
	InOrder(root->right);
}

/* ----------------------------------- */
void Tree::PostOrder(Node* root)
{
	if (root == nullptr)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << "  ";
}

/* ----------------------------------- */
void Tree::LevelOrder(Node* root)
{
	if (root == nullptr)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		root = q.front();
		cout << root->data << "   ";
		q.pop();
		if (root->left != nullptr)
			q.push(root->left);
		if (root->right != nullptr)
			q.push(root->right);
	}
}

/* ----------------------------------- */
int Tree::CountNodes(Node* root)
{
	if (root == nullptr)
		return 0;
	return CountNodes(root->left) + CountNodes(root->right) + 1;
}

/* ----------------------------------- */
int Tree::CountNodes2(Node* root)
{
	if (root == nullptr)
		return 0;
	int x = 0;
	int y = 0;
	x = CountNodes2(root->left);
	y = CountNodes2(root->right);
	if (root->left != nullptr && root->right != nullptr)
		return  x + y + 1;
	return x + y;
}

/* ----------------------------------- */
int Tree::CountNodes1(Node* root)
{
	if (root == nullptr)
		return 0;
	int x = 0;
	int y = 0;
	x = CountNodes1(root->left);
	y = CountNodes1(root->right);
	if ((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr))
		return  x + y + 1;
	return x + y;
}

/* ----------------------------------- */
int Tree::CountNodes0(Node* root)
{
	if (root == nullptr)
		return 0;
	int x = 0;
	int y = 0;
	x = CountNodes0(root->left);
	y = CountNodes0(root->right);
	if (root->left == nullptr && root->right == nullptr)
		return  x + y + 1;
	return x + y;
}

/* ----------------------------------- */
int Tree::Height(Node* root)
{
	if (root == nullptr)
		return 0;
	int x = 0;
	int y = 0;
	x = Height(root->left);
	y = Height(root->right);
	if (x > y)
		return  x + 1;
	else
		return y + 1;
}

/* ----------------------------------- */
Tree::~Tree()
{

}

/* ------------------------------------------------------------------------------------
			  Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "Tree.hxx"

/* Main Method */
int main()
{
	Tree t;
	Node* temp = t.Create();
	cout << endl << endl;
	cout << "Tree Traversal PreOrder : ";
	t.PreOrder(temp);
	cout << endl << endl;
	cout << "Tree Traversal InOrder : ";
	t.InOrder(temp);
	cout << endl << endl;
	cout << "Tree Traversal PostOrder : ";
	t.PostOrder(temp);
	cout << endl << endl;
	cout << "Tree Traversal LevelOrder : ";
	t.LevelOrder(temp);
	cout << endl << endl;
	cout << "The Number of Nodes are : " << t.CountNodes(temp);
	cout << endl << endl;
	cout << "The Number of Nodes with Degree 2 are : " << t.CountNodes2(temp);
	cout << endl << endl;
	cout << "The Number of Nodes with Degree 1 are : " << t.CountNodes1(temp);
	cout << endl << endl;
	cout << "The Number of Nodes with Degree 0 are : " << t.CountNodes0(temp);
	cout << endl << endl;
	cout << "The Height of tree is : " << t.Height(temp);
	cout << endl << endl;
	system("pause");
	return 0;
}

/*
Output
Enter the root element : 5
Enter the left element of 5 : 3
Enter the right element of 5 : 7
Enter the left element of 3 : 1
Enter the right element of 3 : 2
Enter the left element of 7 : 6
Enter the right element of 7 : 11
Enter the left element of 1 : -1
Enter the right element of 1 : -1
Enter the left element of 2 : -1
Enter the right element of 2 : 4
Enter the left element of 6 : -1
Enter the right element of 6 : -1
Enter the left element of 11 : 10
Enter the right element of 11 : -1
Enter the left element of 4 : -1
Enter the right element of 4 : -1
Enter the left element of 10 : -1
Enter the right element of 10 : -1

Tree Traversal PreOrder : 5  3  1  2  4  7  6  11  10

Tree Traversal InOrder : 1  3  2  4  5  6  7  10  11

Tree Traversal PostOrder : 1  4  2  3  6  10  11  7  5

Tree Traversal LevelOrder : 5   3   7   1   2   6   11   4   10

The Number of Nodes are : 9

The Number of Nodes with Degree 2 are : 3

The Number of Nodes with Degree 1 are : 2

The Number of Nodes with Degree 0 are : 4

The Height of tree is : 4

*/

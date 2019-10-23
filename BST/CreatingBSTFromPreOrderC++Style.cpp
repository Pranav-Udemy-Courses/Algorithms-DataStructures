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
			  BSTree Header (BSTree.hxx)
------------------------------------------------------------------------------------ */
#include "Node.hxx"

/* Class BSTree */
class BSTree
{
public:

	// Default Constructor
	BSTree();

	// Create BST using PreOrder
	Node* CreateUsingPreOrder(Node* root, int a[], int size);

	// Display BSTree Using InOrder
	void InOrder(Node* root);

	// Destructor
	~BSTree();

};

/* ------------------------------------------------------------------------------------
			  BSTree Implementation (BSTree.cxx)
------------------------------------------------------------------------------------ */
#include "BSTree.hxx"
#include <stack>

/* ----------------------------------- */
BSTree::BSTree()
{

}

/* ----------------------------------- */
Node* BSTree::CreateUsingPreOrder(Node* root, int a[], int size)
{
	int i = 0;
	Node* t = nullptr;
	Node* p = new Node;
	p->data = a[i];
	p->left = p->right = nullptr;
	t = root = p;
	++i;
	stack<Node*> s;
	while (i < size)
	{
		if (a[i] < t->data)
		{
			p = new Node;
			p->data = a[i];
			p->left = p->right = nullptr;
			s.push(t);
			t->left = p;
			t = p;
			++i;
		}
		else if (a[i] > t->data)
		{
			if (s.empty() || a[i] < s.top()->data)
			{
				p = new Node;
				p->data = a[i];
				p->left = p->right = nullptr;
				t->right = p;
				t = p;
				++i;
			}
			else
			{
				t = s.top();
				s.pop();
			}
		}
		else
		{
			++i;
		}
	}
	return root;
}

/* ----------------------------------- */
void BSTree::InOrder(Node* root)
{
	if (root == nullptr)
		return;
	InOrder(root->left);
	cout << root->data << "   ";
	InOrder(root->right);
}

/* ----------------------------------- */
BSTree::~BSTree()
{

}

/* ------------------------------------------------------------------------------------
			  Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "BSTree.hxx"

/* Main Method */
int main()
{
	BSTree t;
	int arr[]{ 30,20,10,15,25,40,50,45 };
	Node* root = nullptr;
	root = t.CreateUsingPreOrder(root, arr, sizeof(arr) / sizeof(int));
	cout << "The Inorder Traversal of Binary Search Tree is : ";
	t.InOrder(root);
	cout << endl << endl;
	system("pause");
	return 0;
}

/*
Output

The Inorder Traversal of Binary Search Tree is : 10   15   20   25   30   40   45   50

*/

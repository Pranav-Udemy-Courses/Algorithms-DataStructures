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
	int height; // Height of the Node
};

/* ------------------------------------------------------------------------------------
			  AVLTree Header (AVLTree.hxx)
------------------------------------------------------------------------------------ */
#include "Node.hxx"

/* Class AVLTree */
class AVLTree
{
private:
	Node* m_root = nullptr;
public:

	// Default Constructor
	AVLTree();

	// Set Root Node
	void SetRoot(Node* root);

	// Get Root Node
	Node* GetRoot() const;

	// Insert in Self-Balanced Binary Search Tree Recursively
	Node* InsertRec(Node* p, int key);

	// Get Height of Node
	int NodeHeight(Node* p);

	// Get Balance Factor of Node
	int BalanceFactor(Node* p);

	// LL Rotation of AVL Tree
	Node* LLRotation(Node* p);

	// LR Rotation of AVL Tree
	Node* LRRotation(Node* p);

	// RR Rotation of AVL Tree
	Node* RRRotation(Node* p);

	// RL Rotation of AVL Tree
	Node* RLRotation(Node* p);

	// Display AVLTree Using InOrder
	void InOrder(Node* p);

	// Display AVLTree Using PreOrder
	void PreOrder(Node* p);

	// Search a key in Self-Balanced Binary Search Tree Recursively
	bool SearchRec(Node* p, int key);

	// Destructor
	~AVLTree();

};

/* ------------------------------------------------------------------------------------
			  AVLTree Implementation (AVLTree.cxx)
------------------------------------------------------------------------------------ */
#include "AVLTree.hxx"

/* ----------------------------------- */
AVLTree::AVLTree()
{
}

/* ----------------------------------- */
void AVLTree::SetRoot(Node* root)
{
	m_root = root;
}

/* ----------------------------------- */
Node* AVLTree::GetRoot() const
{
	return m_root;
}

/* ----------------------------------- */
Node* AVLTree::InsertRec(Node* t, int key)
{
	if (t == nullptr)
	{
		Node* temp = new Node;
		temp->left = temp->right = nullptr;
		temp->height = 1;
		temp->data = key;
		return temp;
	}

	if (key < t->data)
		t->left = InsertRec(t->left, key);
	else if (key > t->data)
		t->right = InsertRec(t->right, key);

	t->height = NodeHeight(t);
	if (BalanceFactor(t) == 2 && BalanceFactor(t->left) == 1)
		LLRotation(t);
	else if (BalanceFactor(t) == 2 && BalanceFactor(t->left) == -1)
		LRRotation(t);
	else if (BalanceFactor(t) == -2 && BalanceFactor(t->right) == -1)
		RRRotation(t);
	else if (BalanceFactor(t) == -2 && BalanceFactor(t->right) == 1)
		RLRotation(t);
	return t;
}

/* ----------------------------------- */
int AVLTree::NodeHeight(Node* p)
{
	int leftHeight = (p != nullptr && p->left != nullptr) ? p->left->height : 0;
	int rightHeight = (p != nullptr && p->right != nullptr) ? p->right->height : 0;

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

/* ----------------------------------- */
int AVLTree::BalanceFactor(Node* p)
{
	int leftHeight = (p != nullptr && p->left != nullptr) ? p->left->height : 0;
	int rightHeight = (p != nullptr && p->right != nullptr) ? p->right->height : 0;

	return leftHeight - rightHeight;
}

/* ----------------------------------- */
Node* AVLTree::LLRotation(Node* p)
{
	Node* pl = p->left;
	Node* plr = p->left->right;

	pl->right = p;
	p->left = plr;
	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);

	if (m_root == p)
		m_root = pl;
	return pl;
}

/* ----------------------------------- */
Node* AVLTree::LRRotation(Node* p)
{
	Node* pl = p->left;
	Node* plr = p->left->right;

	pl->right = plr->left;
	p->left = plr->right;
	plr->left = pl;
	plr->right = p;

	pl->height = NodeHeight(pl);
	p->height = NodeHeight(p);
	plr->height = NodeHeight(plr);

	if (m_root == p)
		m_root = plr;
	return plr;
}

/* ----------------------------------- */
Node* AVLTree::RRRotation(Node* p)
{
	Node* pr = p->right;
	Node* prl = p->right->left;

	pr->left = p;
	p->right = prl;
	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	if (m_root == p)
		m_root = pr;
	return pr;
}

/* ----------------------------------- */
Node* AVLTree::RLRotation(Node* p)
{
	Node* pr = p->right;
	Node* prl = p->right->left;

	pr->left = prl->right;
	p->right = prl->left;
	prl->left = p;
	prl->right = pr;

	pr->height = NodeHeight(pr);
	p->height = NodeHeight(p);
	prl->height = NodeHeight(prl);

	if (m_root == p)
		m_root = prl;
	return prl;
}

/* ----------------------------------- */
void AVLTree::InOrder(Node* p)
{
	if (p == nullptr)
		return;
	InOrder(p->left);
	cout << p->data << "   ";
	InOrder(p->right);
}

/* ----------------------------------- */
void AVLTree::PreOrder(Node* p)
{
	if (p == nullptr)
		return;
	cout << p->data << "   ";
    PreOrder(p->left);
    PreOrder(p->right);
}

/* ----------------------------------- */
bool AVLTree::SearchRec(Node* p, int key)
{
	if (p == nullptr)
		return false;

	if (key == p->data)
		return true;
	else if (key < p->data)
		return SearchRec(p->left, key);
	else
		return SearchRec(p->right, key);
}

/* ----------------------------------- */
AVLTree::~AVLTree()
{

}

/* ------------------------------------------------------------------------------------
			  Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "AVLTree.hxx"

/* Main Method */
int main()
{
	AVLTree llt;
	Node* root = llt.InsertRec(nullptr, 10);
	llt.SetRoot(root);
	llt.InsertRec(root, 5);
	root = llt.InsertRec(root, 2);
	cout << "The InOrder of Self-Balanced Binary Tree(AVL) rotated using LLRotation is : ";
	llt.InOrder(llt.GetRoot());
	cout << endl;
	cout << "The PreOrder of Self-Balanced Binary Tree(AVL) rotated using LLRotation is : ";
	llt.PreOrder(llt.GetRoot());
	cout << endl << endl;

	AVLTree lrt;
	root = lrt.InsertRec(nullptr, 10);
	lrt.SetRoot(root);
	lrt.InsertRec(root, 5);
	root = lrt.InsertRec(root, 7);
	cout << "The InOrder of Self-Balanced Binary Tree(AVL) rotated using LRRotation is : ";
	lrt.InOrder(lrt.GetRoot());
	cout << endl;
	cout << "The PreOrder of Self-Balanced Binary Tree(AVL) rotated using LRRotation is : ";
	lrt.PreOrder(lrt.GetRoot());
	cout << endl << endl;

	AVLTree rrt;
	root = rrt.InsertRec(nullptr, 10);
	rrt.SetRoot(root);
	rrt.InsertRec(root, 20);
	root = rrt.InsertRec(root, 30);
	cout << "The InOrder of Self-Balanced Binary Tree(AVL) rotated using RRRotation is : ";
	rrt.InOrder(rrt.GetRoot());
	cout << endl;
	cout << "The PreOrder of Self-Balanced Binary Tree(AVL) rotated using RRRotation is : ";
	rrt.PreOrder(rrt.GetRoot());
	cout << endl << endl;

	AVLTree rlt;
	root = rlt.InsertRec(nullptr, 10);
	rlt.SetRoot(root);
	rlt.InsertRec(root, 20);
	root = rlt.InsertRec(root, 15);
	cout << "The InOrder of Self-Balanced Binary Tree(AVL) rotated using RLRotation is : ";
	rlt.InOrder(rlt.GetRoot());
	cout << endl;
	cout << "The PreOrder of Self-Balanced Binary Tree(AVL) rotated using RLRotation is : ";
	rlt.PreOrder(rlt.GetRoot());
	cout << endl << endl;

	system("pause");
	return 0;
}

/*
Output

The InOrder of Self-Balanced Binary Tree(AVL) rotated using LLRotation is : 2   5   10
The PreOrder of Self-Balanced Binary Tree(AVL) rotated using LLRotation is : 5   2   10

The InOrder of Self-Balanced Binary Tree(AVL) rotated using LRRotation is : 5   7   10
The PreOrder of Self-Balanced Binary Tree(AVL) rotated using LRRotation is : 7   5   10

The InOrder of Self-Balanced Binary Tree(AVL) rotated using RRRotation is : 10   20   30
The PreOrder of Self-Balanced Binary Tree(AVL) rotated using RRRotation is : 20   10   30

The InOrder of Self-Balanced Binary Tree(AVL) rotated using RLRotation is : 10   15   20
The PreOrder of Self-Balanced Binary Tree(AVL) rotated using RLRotation is : 15   10   20

*/

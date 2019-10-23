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

    // Insert in Binary Search Tree Recursively
    Node* InsertRec(Node* root, int key);

    // Delete a key from Binary Search Tree Recursively
    Node* DeleteRec(Node* root, int key);

    // Search a key in Binary Search Tree Recursively
    bool SearchRec(Node* root, int key);

    // Find Height of Binary Search Tree
    int HeightRec(Node* root);

    // Display BSTree Using InOrder
    void InOrder(Node* root);

    // Display BSTree Using PreOrder
    void PreOrder(Node* root);

    // Destructor
    ~BSTree();


private:
    // Get the InOrder Predecessor
    Node* InOrderPre(Node* p);

    // Get the InOrder Sucessor
    Node* InOrderSucc(Node* p);
};

/* ------------------------------------------------------------------------------------
              BSTree Implementation (BSTree.cxx)
------------------------------------------------------------------------------------ */
#include "BSTree.hxx"

/* ----------------------------------- */
BSTree::BSTree()
{
}

/* ----------------------------------- */
Node* BSTree::InsertRec(Node* t, int key)
{
    if (t == nullptr)
    {
        Node* temp = new Node;
        temp->left = temp->right = nullptr;
        temp->data = key;
        return temp;
    }

    if (key < t->data)
        t->left = InsertRec(t->left, key);
    else if (key > t->data)
        t->right = InsertRec(t->right, key);

    return t;
}

/* ----------------------------------- */
Node* BSTree::DeleteRec(Node* root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }

    if (key < root->data)
        root->left = DeleteRec(root->left, key);
    else if (key > root->data)
        root->right = DeleteRec(root->right, key);
    else
    {
        if (HeightRec(root->left) > HeightRec(root->right))
        {
            Node* q = InOrderPre(root->left);
            root->data = q->data;
            root->left = DeleteRec(root->left, q->data);
        }
        else
        {
            Node* q = InOrderSucc(root->right);
            root->data = q->data;
            root->right = DeleteRec(root->right, q->data);
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
void BSTree::PreOrder(Node * root)
{
    if (root == nullptr)
        return;
    cout << root->data << "   ";
    PreOrder(root->left);
    PreOrder(root->right);
}

/* ----------------------------------- */
bool BSTree::SearchRec(Node * root, int key)
{
    if (root == nullptr)
        return false;

    if (key == root->data)
        return true;
    else if (key < root->data)
        return SearchRec(root->left, key);
    else
        return SearchRec(root->right, key);
}

/* ----------------------------------- */
int BSTree::HeightRec(Node * root)
{
    if (root == nullptr)
        return 0;

    int x = HeightRec(root->left);
    int y = HeightRec(root->right);

    return x > y ? x + 1 : y + 1;
}

/* ----------------------------------- */
BSTree::~BSTree()
{
}

/* ----------------------------------- */
Node* BSTree::InOrderPre(Node * p)
{
    if (p != nullptr && p->right != nullptr)
        p = p->right;
    return p;
}

/* ----------------------------------- */
Node* BSTree::InOrderSucc(Node * p)
{
    if (p != nullptr && p->left != nullptr)
        p = p->left;
    return p;
}

/* ------------------------------------------------------------------------------------
              Main CPP File (Source.cpp)
------------------------------------------------------------------------------------ */
#include "BSTree.hxx"

/* Main Method */
int main()
{
    BSTree t;
    Node* root = nullptr;
    root = t.InsertRec(root, 7);
    t.InsertRec(root, 3);
    t.InsertRec(root, 10);
    t.InsertRec(root, 1);
    t.InsertRec(root, 4);
    t.InsertRec(root, 8);
    t.InsertRec(root, 12);
    cout << "The Inorder Traversal of Binary Search Tree is : ";
    t.InOrder(root);
    cout << endl << endl;
    cout << "Is node 4 found using Recursive Search ? " << boolalpha << t.SearchRec(root, 4) << endl << endl;
    cout << "Is node 14 found using Recursive Search ? " << boolalpha << t.SearchRec(root, 14) << endl << endl;
    cout << "Deleting node with value 10" << endl << endl;
    t.DeleteRec(root, 10);
    cout << "The Inorder Traversal of Binary Search Tree is : ";
    t.InOrder(root);
    cout << endl << endl;
    cout << "The Preorder Traversal of Binary Search Tree is : ";
    t.PreOrder(root);
    cout << endl << endl;
    system("pause");
    return 0;
}

/*
Output

The Inorder Traversal of Binary Search Tree is : 1   3   4   7   8   10   12

Is node 4 found using Recursive Search ? true

Is node 14 found using Recursive Search ? false

Deleting node with value 10

The Inorder Traversal of Binary Search Tree is : 1   3   4   7   8   12

The Preorder Traversal of Binary Search Tree is : 7   3   1   4   12   8

*/

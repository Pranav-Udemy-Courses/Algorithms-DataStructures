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

    // Insert in Binary Search Tree Iteratively
    Node* InsertItr(Node* root, int key);

    // Display BSTree Using InOrder
    void InOrder(Node* root);

    // Search a key in Binary Search Tree Iteratively
    bool SearchItr(Node* root, int key);

    // Search a key in Binary Search Tree Recursively
    bool SearchRec(Node* root, int key);

    // Destructor
    ~BSTree();

};

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
Node* BSTree::InsertItr(Node* root, int key)
{
    Node* tail = nullptr;
    if (root == nullptr)
    {
        Node* temp = new Node;
        temp->left = temp->right = nullptr;
        temp->data = key;
        return temp;
    }

    while (root != nullptr)
    {
        tail = root;
        if (key == root->data)
            return nullptr;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    Node* temp = new Node;
    temp->left = temp->right = nullptr;
    temp->data = key;
    if (key < tail->data)
        tail->left = temp;
    else
        tail->right = temp;
    return temp;
}

/* ----------------------------------- */
void BSTree::InOrder(Node * root)
{
    if (root == nullptr)
        return;
    InOrder(root->left);
    cout << root->data << "   ";
    InOrder(root->right);
}

/* ----------------------------------- */
bool BSTree::SearchItr(Node * root, int key)
{
    if (root == nullptr)
        return false;

    Node * tail = nullptr;
    while (root != nullptr)
    {
        if (root->data == key)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
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
    cout << "Is node 4 found using Iterative Search ? " << boolalpha << t.SearchItr(root, 4) << endl << endl;
    cout << "Is node 4 found using Recursive Search ? " << boolalpha << t.SearchRec(root, 4) << endl << endl;
    cout << "Is node 14 found using Iterative Search ? " << boolalpha << t.SearchItr(root, 14) << endl << endl;
    cout << "Is node 14 found using Recursive Search ? " << boolalpha << t.SearchRec(root, 14) << endl << endl;
    system("pause");
    return 0;
}

/*
Output

The Inorder Traversal of Binary Search Tree is : 1   3   4   7   8   10   12

Is node 4 found using Iterative Search ? true

Is node 4 found using Recursive Search ? true

Is node 14 found using Iterative Search ? false

Is node 14 found using Recursive Search ? false

*/


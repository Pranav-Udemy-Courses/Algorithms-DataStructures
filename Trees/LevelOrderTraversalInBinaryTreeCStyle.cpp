#include <iostream>

using namespace std;

/*-------------------------------------
    Structure of Tree
-------------------------------------*/
typedef struct BTree_t
{
    int data; // Data to be stored
    BTree_t* left; // Pointer to Left Child
    BTree_t* right; // Pointer to Right Child
}BTree_s;

/*-------------------------------------
    Structure of Queue
-------------------------------------*/
typedef struct Queue_t
{
    BTree_s* tnode; // Pointer of Tree
    Queue_t* next; // Pointer to next node in Queue
}Queue_s;

/*-------------------------------------
    Global Variables
-------------------------------------*/
Queue_t* head = nullptr;
Queue_t* tail = nullptr;
BTree_s* root = nullptr;

/*-------------------------------------
    Check if Tree is Empty
-------------------------------------*/
bool IsTreeEmpty()
{
    if (root == nullptr)
        return true;
    return false;
}

/*-------------------------------------
    Check if Queue is Empty
-------------------------------------*/
bool IsEmpty()
{
    if (head == tail && head == nullptr)
        return true;
    return false;
}

/*-------------------------------------
     Add an Element to Queue
-------------------------------------*/
void Enqueue(BTree_s * node)
{
    Queue_s* t = new Queue_s;
    t->tnode = node;
    if (IsEmpty())
    {
        t->next = head;
        head = tail = t;
        return;
    }
    t->next = nullptr;
    tail->next = t;
    tail = tail->next;
}

/*-------------------------------------
    Remove an Element from Queue
-------------------------------------*/
BTree_s* Dequeue()
{
    if (IsEmpty())
        return nullptr;
    Queue_s* temp = head;
    head = head->next;
    if (head == nullptr)
        tail = nullptr;
    BTree_s * t = temp->tnode;
    delete temp;
    temp = nullptr;
    return t;
}

/*-------------------------------------
    Create Tree
-------------------------------------*/
void CreateTree()
{
    BTree_s* tmp = nullptr;
    BTree_s* p = nullptr;
    int x;
    if (IsTreeEmpty())
    {
        BTree_s* tmp = new BTree_s;
        cout << "Enter the root element : ";
        cin >> tmp->data;
        tmp->left = tmp->right = nullptr;
        root = p = tmp;
        tmp = nullptr;
        Enqueue(root);
    }
    while (!IsEmpty())
    {
        p = Dequeue();
        cout << "Enter the left element of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            tmp = new BTree_s;
            tmp->data = x;
            tmp->left = nullptr;
            tmp->right = nullptr;
            p->left = tmp;
            Enqueue(tmp);
        }

        cout << "Enter the right element of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            tmp = new BTree_s;
            tmp->data = x;
            tmp->left = nullptr;
            tmp->right = nullptr;
            p->right = tmp;
            Enqueue(tmp);
        }
    }
}

/*-------------------------------------
    Lever Order
-------------------------------------*/
void LevelOrderTraversal(BTree_s * root)
{
    cout << "Tree Level Order Traversal is : ";
    Enqueue(root);
    BTree_s* temp = nullptr;
    while (!IsEmpty())
    {
        temp = Dequeue();
        cout << temp->data << "  ";
        if (temp->left != nullptr)
        {
            Enqueue(temp->left);
        }
        if (temp->right != nullptr)
        {
            Enqueue(temp->right);
        }
    }
    cout << endl;
}

/*-------------------------------------
    Main Method
-------------------------------------*/
int main()
{
    CreateTree();
    cout << endl;
    LevelOrderTraversal(root);
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
Enter the left element of 7 : 9
Enter the right element of 7 : 11
Enter the left element of 1 : -1
Enter the right element of 1 : -1
Enter the left element of 2 : -1
Enter the right element of 2 : -1
Enter the left element of 9 : -1
Enter the right element of 9 : -1
Enter the left element of 11 : -1
Enter the right element of 11 : -1

Tree Level Order Traversal is : 5  3  7  1  2  9  11

*/

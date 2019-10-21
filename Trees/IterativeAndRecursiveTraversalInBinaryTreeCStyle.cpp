#include <iostream>
#include <stack>

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
    Display Tree using PreOrder
-------------------------------------*/
void PreOrder(BTree_s * temp)
{
    if (temp == nullptr)
        return;

    cout << temp->data << "  ";
    PreOrder(temp->left);
    PreOrder(temp->right);
}

/*-------------------------------------
    Display Tree using InOrder
-------------------------------------*/
void InOrder(BTree_s * temp)
{
    if (temp == nullptr)
        return;

    InOrder(temp->left);
    cout << temp->data << "  ";
    InOrder(temp->right);
}

/*-------------------------------------
    Display Tree using PostOrder
-------------------------------------*/
void PostOrder(BTree_s * temp)
{
    if (temp == nullptr)
        return;

    PostOrder(temp->left);
    PostOrder(temp->right);
    cout << temp->data << "  ";
}

/*------------------------------------------------
    Display Tree using PostOrder Iteratively
------------------------------------------------*/
void PreOrderIterative(BTree_s * temp)
{
    cout << "Tree Traversal PreOrder Iterative approach : ";
    stack<BTree_s*> s;
    while (temp != nullptr || !s.empty())
    {
        if (temp != nullptr)
        {
            cout << temp->data << "  ";
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            s.pop();
            temp = temp->right;
        }
    }
    cout << endl;
}

/*------------------------------------------------
    Display Tree using InOrder Iteratively
------------------------------------------------*/
void InOrderIterative(BTree_s * temp)
{
    cout << "Tree Traversal InOrder Iterative approach : ";
    stack<BTree_s*> s;
    while (temp != nullptr || !s.empty())
    {
        if (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            cout << temp->data << "  ";
            s.pop();
            temp = temp->right;
        }
    }
    cout << endl;
}

/*------------------------------------------------
    Display Tree using PosOrder Iteratively
------------------------------------------------*/
//void PosOrderIterative(BTree_s* temp)
//{
//    cout << "Tree Traversal PosOrder Iterative approach : ";
//    stack<BTree_s*> s;
//    while (temp != nullptr || !s.empty())
//    {
//        if (temp != nullptr)
//        {
//            s.push(temp);
//            temp = temp->left;
//        }
//        else
//        {
//            BTree_s* t = s.top();
//            s.pop();
//            if (t > 0)
//            {
//                s.push(t*-1);
//                temp = t->right;
//            }
//            else
//            {
//                cout << temp->data << "  ";
//                t = nullptr;
//            }
//        }
//    }
//    cout << endl;
//}

/*-------------------------------------
    Main Method
-------------------------------------*/
int main()
{
    CreateTree();
    cout << endl;
    cout << "Tree Traversal PreOrder : ";
    PreOrder(root);
    cout << endl << endl;
    PreOrderIterative(root);
    cout << endl;
    cout << "Tree Traversal InOrder : ";
    InOrder(root);
    cout << endl << endl;
    InOrderIterative(root);
    cout << endl;
    cout << "Tree Traversal PostOrder : ";
    PostOrder(root);
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

Tree Traversal PreOrder : 5  3  1  2  7  9  11

Tree Traversal PreOrder Iterative approach : 5  3  1  2  7  9  11

Tree Traversal InOrder : 1  3  2  5  9  7  11

Tree Traversal InOrder Iterative approach : 1  3  2  5  9  7  11

Tree Traversal PostOrder : 1  2  3  9  11  7  5

*/

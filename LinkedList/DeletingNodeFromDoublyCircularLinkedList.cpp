#include <iostream>

using namespace std;

/* Structure of Node */
typedef struct Node_t
{
    Node_t* prev;  // Pointer to the previous node
    int data; // Data to be stored
    Node_t* next;  // Pointer to the next node
}Node_s;

/* Global pointer */
Node_s* head = nullptr;

/* Inserting a Node at Beginning of Doubly Circular Linked List */
void InsertAtBeginning(Node_s* start, int x)
{
    if (start == nullptr)
    {
        Node_s* t = new Node_s;
        t->next = t->prev = t;
        t->data = x;
        head = t;
        return;
    }

    Node_s* t = new Node_s;
    t->data = x;
    t->next = head;
    head->prev->next = t;
    t->prev = head->prev;
    head->prev = t;
    head = t;
}

/* Inserting a Node at any given Index in a Doubly Circular Linked List */
void InsertAtIndex(Node_s* start, int x, int index)
{
    if (start == nullptr || index == 0)
    {
        InsertAtBeginning(start, x);
        return;
    }

    Node_s* t = new Node_s;
    t->data = x;
    for (int i = 0; i <= index - 2; ++i)
    {
        start = start->next;
    }
    t->next = start->next;
    start->next->prev = t;
    t->prev = start;
    start->next = t;
}

/* Deleting a Node at Beginning of Doubly Circular Linked List */
int DeleteAtBeginning(Node_s* start)
{
    if (start == start->next)
    {
        int nodeValue = head->data;
        delete head;
        head = nullptr;
        return nodeValue;
    }

    Node_s* temp = head->next;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    int nodeValue = head->data;
    delete head;
    head = temp;
    return nodeValue;
}

/* Deleting a Node at any given Index of Doubly Circular Linked List */
int DeleteAtIndex(Node_s* start, int index)
{
    if (start == nullptr)
        return -1;

    if (index == 0)
        return DeleteAtBeginning(start);

    for (int i = 0; i <= index - 2; ++i)
    {
        start = start->next;
    }
    Node_s* nodeToDelete = start->next;
    nodeToDelete->next->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;
    int nodeValue = nodeToDelete->data;
    delete nodeToDelete;
    nodeToDelete = nullptr;
    return nodeValue;
}

/* Display a Doubly Circular Linked List */
void Display(Node_s* start)
{
    if (start == nullptr)
        return;
    Node_s * temp = start;
    do
    {
        cout << " | " << temp->prev << " | " << temp->data << " | " << temp->next << " | -------> ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

/* Main Method */
int main()
{
    InsertAtIndex(head, 3, 0);
    InsertAtIndex(head, 1, 0);
    InsertAtIndex(head, 5, 2);
    InsertAtIndex(head, 9, 3);
    InsertAtIndex(head, 7, 3);
    cout << endl << "Displaying Doubly Circular Linked List : ";
    Display(head);
    cout << endl;
    int nodeValue = DeleteAtIndex(head, 3);
    cout << endl << "Displaying Modified Doubly Circular Linked List : ";
    Display(head);
    cout << endl;
    cout << "The Deleted Element from index 3 of Doubly Circular Linked List is : " << nodeValue << endl << endl;
    system("pause");
    return 0;
}

/*
Output

Displaying Doubly Circular Linked List :  | 005B1358 | 1 | 005B1438 | ------->  | 005B1588 | 3 | 005B1978 | ------->  | 005B1438 | 5 | 005B14E0 | ------->  | 005B1978 | 7 | 005B1358 | ------->  | 005B14E0 | 9 | 005B1588 | ------->

Displaying Modified Doubly Circular Linked List :  | 005B1358 | 1 | 005B1438 | ------->  | 005B1588 | 3 | 005B1978 | ------->  | 005B1438 | 5 | 005B1358 | ------->  | 005B1978 | 9 | 005B1588 | ------->

The Deleted Element from index 3 of Doubly Circular Linked List is : 7

*/
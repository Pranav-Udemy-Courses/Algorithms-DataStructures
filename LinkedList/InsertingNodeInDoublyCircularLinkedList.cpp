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
    cout << endl << "Displaying Doubly Circular Linked List : ";
    Display(head);
    cout << endl;

    InsertAtIndex(head, 1, 0);
    cout << endl << "Displaying Doubly Circular Linked List : ";
    Display(head);
    cout << endl;

    InsertAtIndex(head, 5, 2);
    InsertAtIndex(head, 9, 3);
    InsertAtIndex(head, 7, 3);
    cout << endl << "Displaying Doubly Circular Linked List : ";
    Display(head);
    cout << endl;

    system("pause");
    return 0;
}

/*
Output

Displaying Doubly Circular Linked List :  | 011507F0 | 3 | 011507F0 | ------->


Displaying Doubly Circular Linked List :  | 011507F0 | 1 | 011507F0 | ------->  | 01150978 | 3 | 01150978 | ------->


Displaying Doubly Circular Linked List :  | 01150B70 | 1 | 011507F0 | ------->  | 01150978 | 3 | 01150A58 | ------->  | 011507F0 | 5 | 01150CF8 | ------->  | 01150A58 | 7 | 01150B70 | ------->  | 01150CF8 | 9 | 01150978 | ------->

*/
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

/* Display a Doubly Linked List */
void Display(Node_s* start)
{
    if (start == nullptr)
        return;
    Node_s * temp = start;
    while (temp != nullptr)
    {
        cout << " | " << temp->prev << " | " << temp->data << " | " << temp->next << " | -------> ";
        temp = temp->next;
    }
    cout << endl;
}

/* Find the Length of Doubly Linked List */
int Length(Node_s* start)
{
    if (start == nullptr)
        return 0;
    int count = 1;
    while (start->next != nullptr)
    {
        count++;
        start = start->next;
    }
    return count;
}

/* Insert a Node at Beginning of Doubly Linked List */
void InsertAtBeginning(Node_s* start, int x)
{
    Node_s* t = new Node_s;
    t->data = x;
    t->prev = nullptr;
    t->next = head;
    if (head == nullptr)
    {
        head = t;
        return;
    }
    else
    {
        head->prev = t;
        head = t;
    }
}

/* Insert a Node at any given Index of Doubly Linked List */
void InsertAtIndex(Node_s* start, int x, int index)
{
    if (index < 0 || index > Length(start))
        return;
    if (index == 0 || start == nullptr)
    {
        InsertAtBeginning(start, x);
        return;
    }

    for (int i = 0; i <= index - 2; ++i)
    {
        start = start->next;
    }

    Node_s* t = new Node_s;
    t->data = x;
    t->next = start->next;
    t->prev = start;
    if (start->next != nullptr)
        start->next->prev = t;
    start->next = t;
}

/* Reverse Doubly Linked List Iteratively */
void Reverse(Node_s * start)
{
    if (start == nullptr)
        return;
    Node_s * t = start;
    Node_s * temp = nullptr;
    while (t != nullptr)
    {
        temp = t->next;
        t->next = t->prev;
        t->prev = temp;
        if (t->prev == nullptr)
            head = t;
        t = t->prev;
    }
}

/* Main Method */
int main()
{

    InsertAtIndex(head, 1, 0);
    InsertAtIndex(head, 3, 1);
    InsertAtIndex(head, 5, 2);
    InsertAtIndex(head, 7, 3);
    InsertAtIndex(head, 9, 4);
    cout << "Displaying Doubly Linked List : ";
    Display(head);
    cout << endl;
    cout << "The Length of Doubly Linked List is : " << Length(head) << endl << endl;
    cout << "Displaying Reversed Doubly Linked List : ";
    Reverse(head);
    Display(head);
    cout << endl;
    cout << "The Length of Doubly Linked List is : " << Length(head) << endl << endl;
    system("pause");
    return 0;
}

/*
Output

Displaying Doubly Linked List :  | 00000000 | 1 | 00A70688 | ------->  | 00A70A78 | 3 | 00A707D8 | ------->  | 00A70688 | 5 | 00A70A08 | ------->  | 00A707D8 | 7 | 00A70810 | ------->  | 00A70A08 | 9 | 00000000 | ------->

The Length of Doubly Linked List is : 5

Displaying Reversed Doubly Linked List :  | 00000000 | 9 | 00A70A08 | ------->  | 00A70810 | 7 | 00A707D8 | ------->  | 00A70A08 | 5 | 00A70688 | ------->  | 00A707D8 | 3 | 00A70A78 | ------->  | 00A70688 | 1 | 00000000 | ------->

The Length of Doubly Linked List is : 5

*/
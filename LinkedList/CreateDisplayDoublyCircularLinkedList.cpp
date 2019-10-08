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

/* Create a Circularly Doubly Linked List */
void Create(int A[], int len)
{
    if (len == 0)
        return;

    Node_s * last = head;
    Node_s * t = new Node_s;
    t->prev = t;
    t->data = A[0];
    t->next = t;
    last = head = t;

    for (int i = 1; i < len; ++i)
    {
        t = new Node_s;
        t->next = head;
        t->prev = last;
        t->data = A[i];
        last->next = t;
        last = last->next;
    }
    head->prev = t; // Or head->prev = last
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
    int A[]{ 3,5,7,9 };
    Create(A, 4);
    cout << endl << "Displaying Doubly Circular Linked List : ";
    Display(head);
    cout << endl;

    system("pause");
    return 0;
}

/*
Output

Displaying Doubly Circular Linked List :  | 00850CE8 | 3 | 00850D90 | ------->  | 00850A10 | 5 | 00850B60 | ------->  | 00850D90 | 7 | 00850CE8 | ------->  | 00850B60 | 9 | 00850A10 | ------->

*/
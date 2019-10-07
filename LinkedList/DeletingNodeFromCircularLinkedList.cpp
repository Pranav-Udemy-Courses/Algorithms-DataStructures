#include <iostream>

using namespace std;

/* Structure of Node */
typedef struct Node_t
{
    int data;  // Data to be stored
    Node_t* next;  // Pointer to the next node
}Node_s;

// Global Variable Node_s*
Node_s* head = nullptr;

/* Get count of unique nodes in Circular Linked Lists */
int Count(Node_s* start)
{
    if (start == nullptr)
        return 0;
    int counter = 1;
    Node_s * temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}

/* Insert node at beginning of Circular Linked List */
void InsertAtBeginning(Node_s* start, int x)
{
    Node_s* t = new Node_s;
    t->data = x;
    if (start == nullptr)
    {
        head = t;
        t->next = head;
        return;
    }
    else
    {
        t->next = start;
        Node_s* temp = start;
        while (temp->next != start)
            temp = temp->next;
        temp->next = t;
        head = t;
    }
}

/* Insert node at any given Index in a Circular Linked List */
void InsertAtIndex(Node_s * start, int x, int index)
{
    if (index < 0 || index > Count(start))
        return;

    if (index == 0 || start == nullptr)
    {
        InsertAtBeginning(start, x);
        return;
    }

    Node_s* temp = start;
    for (int i = 0; i <= index - 2; ++i)
    {
        temp = temp->next;
    }
    Node_s* t = new Node_s;
    t->data = x;
    t->next = temp->next;
    temp->next = t;
}

/* Deleting a Node from Beginning of Circular Linked List */
int DeleteAtBeginning(Node_s * start)
{
    Node_s* nodeToDelete = start;
    start = start->next;
    head = start;
    if (head != head->next)
    {
        while (start->next != nodeToDelete)
            start = start->next;
        start->next = head;
    }
    else
        head = nullptr;
    int nodeValue = nodeToDelete->data;
    delete nodeToDelete;
    nodeToDelete = nullptr;
    return nodeValue;
}

/* Deleting a Node from Beginning of Circular Linked List */
int DeleteAtIndex(Node_s * start, int index)
{
    if (start == nullptr || index < 0 || index >= Count(start))
        return -1;

    if (index == 0)
        return DeleteAtBeginning(start);

    Node_s * temp = start;
    for (int i = 0; i <= index - 2; ++i)
        temp = temp->next;
    Node_s * nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    int nodeValue = nodeToDelete->data;
    delete nodeToDelete;
    nodeToDelete = nullptr;
    return nodeValue;
}

/* Display the circular linked list iteratively */
void Display(Node_s * temp)
{
    if (temp == nullptr)
        return;
    do
    {
        cout << "| " << temp->data << " | " << temp->next << " | -------> ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

/* Main Method */
int main()
{
    InsertAtIndex(head, 3, 0);
    InsertAtIndex(head, 5, 1);
    InsertAtIndex(head, 9, 2);
    InsertAtIndex(head, 7, 2);
    InsertAtIndex(head, 1, 0);
    cout << "Displaying the created circular linked list : ";
    Display(head);
    cout << endl;
    cout << "The number of unique nodes in circular linked list are : " << Count(head);
    cout << endl;
    cout << endl;
    int value = DeleteAtIndex(head, 3);
    cout << "Displaying the modified circular linked list : ";
    Display(head);
    cout << endl;
    cout << "The Deleted node from original circular linked list at index 3 is : " << value << endl << endl;
    system("pause");
    return 0;
}

/*
Output

Displaying the created circular linked list : | 1 | 012D35D8 | -------> | 3 | 012D3178 | -------> | 5 | 012D33A8 | -------> | 7 | 012D3488 | -------> | 9 | 012D3060 | ------->

The number of unique nodes in circular linked list are : 5

Displaying the modified circular linked list : | 1 | 012D35D8 | -------> | 3 | 012D3178 | -------> | 5 | 012D3488 | -------> | 9 | 012D3060 | ------->

The Deleted node from original circular linked list at index 3 is : 7

*/
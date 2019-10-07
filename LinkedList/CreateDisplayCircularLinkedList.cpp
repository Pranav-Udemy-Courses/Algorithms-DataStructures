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

/* Create a circular linked list using array */
void CreateCir(int a[], int len)
{
    head = new Node_s;
    head->data = a[0];
    head->next = head;
    Node_s* last = head;

    for (int i = 1; i < len; ++i)
    {
        Node_s* t = new Node_s;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = last->next;
    }

}

/* Display the circular linked list iteratively */
void Display(Node_s* temp)
{
    do
    {
        cout << "| " << temp->data << " | " << temp->next << " | -------> ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

/* Display the circular linked list recursively */
void RDisplay(Node_s * temp)
{
    static int flag = 0;
    if (temp != head || flag == 0)
    {
        flag = 1;
        cout << "| " << temp->data << " | " << temp->next << " | -------> ";
        RDisplay(temp->next);
    }
    flag = 0;
}

/* Main Method */
int main()
{
    int a[]{ 3,5,7,9 };
    CreateCir(a, 4);
    cout << "Displaying Circular Linked List Iteratively : ";
    Display(head);
    cout << endl;
    cout << "Displaying Circular Linked List Recursively : ";
    RDisplay(head);
    cout << endl;
    cout << endl;
    system("pause");
    return 0;
}

/*
Output

Displaying Circular Linked List Iteratively : | 3 | 00BA2860 | -------> | 5 | 00BA24A8 | -------> | 7 | 00BA2668 | -------> | 9 | 00BA26D8 | ------->

Displaying Circular Linked List Recursively : | 3 | 00BA2860 | -------> | 5 | 00BA24A8 | -------> | 7 | 00BA2668 | -------> | 9 | 00BA26D8 | ------->

*/
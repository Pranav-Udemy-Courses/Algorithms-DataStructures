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

/* Display the linked list */
void Display()
{
	Node_s* temp = head;
	while (temp != nullptr)
	{
		cout << "| " << temp->data << " | " << temp->next << " | -------> ";
		temp = temp->next;
	}
	cout << endl;
}

/* Insert a node at the Beginning of Linked List */
Node_s* InsertAtBeginning(Node_s* temp, int x)
{
	Node_s* newNode = new Node_s;
	newNode->data = x;
	newNode->next = head;
	head = newNode;
	return head;
}

/* Insert a node at the end of Linked List */
Node_s* InsertAtEnd(Node_s* temp, int x)
{
	if (temp == nullptr)
		return InsertAtBeginning(temp, x);

	while (temp->next != nullptr)
		temp = temp->next;
	Node_s* newNode = new Node_s;
	newNode->data = x;
	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}

/* Check if the Linked List contains a Loop or not */
bool IsLoop(Node_s* temp)
{
	if (temp == nullptr)
		return false;
	Node_s* p = temp, * q = temp;
	do
	{
		p = p->next;
		q = q->next;
		q = q != nullptr ? q->next : nullptr;
	} while (p != nullptr && q != nullptr && p != q);
	if (p == q)
		return true;
	else
		return false;
}

/* Main Method */
int main()
{
	InsertAtEnd(head, 3);
	InsertAtEnd(head, 5);
	InsertAtEnd(head, 6);
	InsertAtEnd(head, 9);
	cout << "Displaying Original link list : ";
	Display();
	cout << endl;
	cout << "Original linked list has loop ? : " << std::boolalpha << IsLoop(head) << endl;
	Node_s* t1, * t2;
	t1 = head->next;
	t2 = head->next->next->next;
	t2->next = t1;
	cout << "Modified linked list has loop ? : " << std::boolalpha << IsLoop(head) << endl;
	system("pause");
	return 0;
}

/*
Output
Displaying Original link list : | 3 | 00FDE3C0 | -------> | 5 | 00FDE4A0 | -------> | 6 | 00FDDDD8 | -------> | 9 | 00000000 | ------->

Original linked list has loop ? : false

															---------------------------------------------------------------------------
															|																		  |																													
Displaying Modified link list : | 3 | 00FDE3C0 | -------> | 5 | 00FDE4A0 | -------> | 6 | 00FDDDD8 | -------> | 9 | 00FDE3C0 | --------

Modified linked list has loop ? : true
*/

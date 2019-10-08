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

/* Create a linked list */
void Create(int a[], int len)
{
	Node_s* t, * last;
	head = new Node_s;
	head->data = a[0];
	head->next = nullptr;
	last = head;

	for (int i = 1; i < len; ++i)
	{
		t = new Node_s;
		t->data = a[i];
		t->next = nullptr;
		last->next = t;
		last = last->next;
	}
}

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

/* Find Length of Linked List */
int Length(Node_s* start)
{
	if (start == nullptr)
		return -1;
	int count = 0;
	while (start != nullptr)
	{
		count++;
		start = start->next;
	}
	return count;
}

/* Find Mid Basic O(n*log n)*/
int FindMidBasic(Node_s* start)
{
	int count = Length(start) / 2;
	int counter = 0;
	while (counter < count)
	{
		counter++;
		start = start->next;
	}
	return start->data;
}

/* Find Mid Smartly O(n) */
int FindMidSmart(Node_s* start)
{
	Node_s* p = start, * q = start;
	while (q != nullptr)
	{
		q = q->next;
		if (q != nullptr)
			q = q->next;
		if (q != nullptr)
			p = p->next;
	}
	return p->data;
}

/* Main Method */
int main()
{
	int a[]{ 2,5,7,9,11 };
	Create(a, 5);
	cout << endl << "The Linked List is : ";
	Display();
	cout << endl << "The Middle Element of Linked List using basic way is : " << FindMidBasic(head) << endl << endl;
	cout << endl << "The Middle Element of Linked List using smart way is : " << FindMidSmart(head) << endl << endl;
	system("pause");
	return 0;
}

/*
Output

The Linked List is : | 2 | 0012DF00 | -------> | 5 | 0012DFA8 | -------> | 7 | 0012DDB0 | -------> | 9 | 0012DC98 | -------> | 11 | 00000000 | ------->

The Middle Element of Linked List using basic way is : 7

The Middle Element of Linked List using smart way is : 7

*/
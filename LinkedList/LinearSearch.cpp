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

/* Linear Search to find a key recursively */
Node_s* LinearSearchRec(Node_s* temp, int key)
{
	if (temp != nullptr)
	{
		if (temp->data == key)
			return temp;
		return LinearSearchRec(temp->next, key);
	}
	return nullptr;
}

/* Linear Search to find a key iteratively */
Node_s* LinearSearch(Node_s* temp, int key)
{
	while (temp != nullptr)
	{
		if (temp->data == key)
			return temp;
		temp = temp->next;
	}
	return nullptr;
}

/* Linear Search improved version Move to Head strategy */
Node_s* LinearSearchImproved(Node_s* temp, int key)
{
	Node_s* prev = nullptr;
	while (temp != nullptr)
	{
		if (temp->data == key)
		{
			prev->next = temp->next;
			temp->next = head;
			head = temp;
			return temp;
		}
		prev = temp;
		temp = temp->next;
	}
	return nullptr;
}

/* Main Method */
int main()
{
	int a[]{ 2,11,5,7,9 };
	Create(a, 5);
	cout << "Display using loop : ";
	Display();
	Node_s* search = LinearSearch(head, 7);
	cout << "Key found using Iterative LinearSearch is : " << search->data << endl;
	search = LinearSearchRec(head, 7);
	cout << "Key found using Recursive LinearSearch is : " << search->data << endl;
	search = LinearSearchImproved(head, 7);
	cout << "Key found using Improved LinearSearch is : " << search->data << endl;
	Display();
	system("pause");
	return 0;
}

/*
Output
Display using loop : | 2 | 0068D748 | -------> | 11 | 0068D5C0 | -------> | 5 | 0068DBA8 | -------> | 7 | 0068DC18 | -------> | 9 | 00000000 | ------->
Key found using Iterative LinearSearch is : 7
Key found using Recursive LinearSearch is : 7
Key found using Improved LinearSearch is : 7
| 7 | 0068DA58 | -------> | 2 | 0068D748 | -------> | 11 | 0068D5C0 | -------> | 5 | 0068DC18 | -------> | 9 | 00000000 | ------->
*/

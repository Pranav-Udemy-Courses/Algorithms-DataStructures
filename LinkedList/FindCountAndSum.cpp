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

/* Count number of nodes using loop */
int CountNode(Node_s* temp)
{
	int count = 0;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

/* Count number of nodes recursively */
int CountNodeRec(Node_s* temp)
{
	if (temp != nullptr)
		return CountNodeRec(temp->next) + 1;
	return 0;
}

/* Find sum of elements of nodes in linked list using loop */
int Sum(Node_s* temp)
{
	int sum = 0;
	while (temp != nullptr)
	{
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

/* Find sum of elements of nodes in linked list recursively */
int SumRec(Node_s* temp)
{
	if (temp != nullptr)
		return SumRec(temp->next) + temp->data;
	return 0;
}

/* Main Method */
int main()
{
	int a[]{ 2,5,7,9 };
	Create(a, 4);
	cout << "Display using loop : ";
	Display();
	cout << "The number of nodes in the linked list found using loop are : " << CountNode(head) << endl;
	cout << "The number of nodes in the linked list found using recurison are : " << CountNodeRec(head) << endl;
	cout << "The sum of nodes in the linked list found using loop are : " << Sum(head) << endl;
	cout << "The sum of nodes in the linked list found using recursion are : " << SumRec(head) << endl;
	system("pause");
	return 0;
}

/*
Output
Display using loop : | 2 | 006BE0A0 | -------> | 5 | 006BDF18 | -------> | 7 | 006BDD58 | -------> | 9 | 00000000 | ------->
The number of nodes in the linked list found using loop are : 4
The number of nodes in the linked list found using recurison are : 4
The sum of nodes in the linked list found using loop are : 23
The sum of nodes in the linked list found using recursion are : 23
*/
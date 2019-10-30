#ifndef Chains_h 
#define Chains_h 
#include<stdlib.h> 

/*-------------------------------------
	Structure of Node
-------------------------------------*/
struct Node
{
	int data;
	struct Node* next;
};


/*-------------------------------------
   Insert Elements in Sorted Order
   Complexity : O(n)
-------------------------------------*/
void SortedInsert(struct Node** H, int x)
{
	struct Node* t, * q = nullptr, * p = *H;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	t->next = nullptr;
	if (*H == nullptr)
		*H = t;
	else
	{
		while (p != nullptr && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (p == *H)
		{
			t->next = *H;
			*H = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}


/*-------------------------------------
   Search Element from Linked List
   Complexity : O(n)
-------------------------------------*/
struct Node* Search(struct Node* p, int key)
{
	while (p != nullptr)
	{
		if (key == p->data)
		{
			return p;
		}
		p = p->next;
	}
	return nullptr;
}
#endif /* Chains_h */

#include <stdio.h>
#include "Chains.h"

/*-------------------------------------
   Return the Hash Value i.e. Modulus
   in this case
   Complexity : O(n)
-------------------------------------*/
int hash(int key)
{
	return key % 10;
}

/*-------------------------------------
   Insert Element in Hash
   Complexity : O(n)
-------------------------------------*/
void Insert(struct Node* H[], int key)
{
	int index = hash(key);
	SortedInsert(&H[index], key);
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	struct Node* HT[10];
	struct Node* temp;
	int i;
	for (i = 0; i < 10; i++)
		HT[i] = nullptr;
	Insert(HT, 12);
	Insert(HT, 22);    Insert(HT, 42);
	temp = Search(HT[hash(21)], 21);
	printf("Key found from Hashing is : %d ", temp->data);
	system("pause");
	return 0;
}

/*
Output

Key found from Hashing is : 22

*/

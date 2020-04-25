#include <iostream>
#include <unordered_map>

using namespace std;

/*---------------------------------------------------------
ALGORITHM
1. Maintain one unordered_map and one doubly linked-list
2. Always put the element at the beginning of the list
3. If the key is available at the time of Get operation,
   then Delete the node from current position and add it 
   the beginning of the list.
4. If capacity is full then delete the last element and add
   the new element at the beginning of the list.
---------------------------------------------------------*/


/* Struct Node */
struct Node
{
	int val;
	int key;
	Node* next;
	Node* prev;
};

/* Unordered Map for retrieval in constant time O(1) */
unordered_map<int, Node*> valToNode;

/* Class LRUCache */
class LRUCache
{
public:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;

	/* Constructor */
	LRUCache(int capacity)
	{
		m_capacity = capacity;
		head = nullptr;
		tail = nullptr;
		valToNode.erase(valToNode.begin(), valToNode.end());
	}

	/* Print the doubly-linkedlist */
	void Print()
	{
		if (!head)
			return;

		Node* temp = head;
		while (temp)
		{
			cout << "<----|-- " << temp->prev << " --|" << "--Key : " << temp->key << "--|" << "--Value : " << temp->val << "--|" << "-- " << temp->next << " --|---->";
			temp = temp->next;
		}
		cout << endl << endl;
	}

	/* Create a Node */
	Node* CreateNode(int key, int val)
	{
		Node* node = new Node;
		node->next = node->prev = nullptr;
		node->val = val;
		node->key = key;
		return node;
	}

	/* Insert the node at the beginning */
	void InsertAtBeginning(int key, int val)
	{
		Node* node = CreateNode(key, val);
		if (head)
		{
			node->next = head;
			head->prev = node;
		}
		if (!tail)
			tail = node;
		head = node;
	}

	/* Delete the node from beginning */
	void DeleteAtBeginning()
	{
		if (!head)
			return;
		Node* tempHead = head;
		Node* nextNode = head->next;
		if (nextNode)
			nextNode->prev = nullptr;
		if (tail == head)
			tail = head = nullptr;
		else
			head = nextNode;
		delete tempHead;
	}

	/* Delete the node from the end */
	void DeleteFromEnd()
	{
		if (!tail)
			return;
		if (head == tail)
			return DeleteAtBeginning();
		Node* prevNode = tail->prev;
		prevNode->next = nullptr;
		delete tail;
		tail = prevNode;
	}

	/* Delete the given node */
	void DeleteNode(Node* t)
	{
		if (t == tail)
			return DeleteFromEnd();
		if (t == head)
			return DeleteAtBeginning();
		Node* nextNode = t->next;
		Node* prevNode = t->prev;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		delete t;
	}

	/* Put the node with given key and value in the cache */
	void put(int key, int value)
	{
		if (m_capacity <= 0)
			return;

		cout << endl << "Putting Key : " << key << " and Value : "<< value << endl;
		if (valToNode.find(key) != valToNode.end())
		{
			DeleteNode(valToNode[key]);
			--count;
		}
		else if (count == m_capacity)
		{
			valToNode.erase(tail->key);
			DeleteFromEnd();
			--count;
		}
		InsertAtBeginning(key, value);
		++count;
		valToNode[key] = head;
		Print();
	}

	/* Get the value for given key from cache */
	int get(int key)
	{
		cout << endl << "Getting Key : " << key << endl;
		if (valToNode.find(key) != valToNode.end())
		{
			Node* node = valToNode[key];
			int val = node->val;
			DeleteNode(node);
			InsertAtBeginning(key, val);
			valToNode[key] = head;
			Print();
			return head->val;
		}
		Print();
		return -1;
	}

private:
	int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = cout << obj->get(key);
 * obj->put(key,value);
 */

/* Main Method */
int main()
{
	LRUCache* obj = new LRUCache(2);
	cout << obj->get(2) << endl;
	obj->put(2, 6);
	cout << obj->get(1) << endl;
	obj->put(1, 5);
	obj->put(1, 2);
	cout << obj->get(1) << endl;
	cout << obj->get(2) << endl;
	return 0;
}

/* 
Output

Getting Key : 2
-1

Putting Key : 2 and Value : 6
<----|-- 00000000 --|--Key : 2--|--Value : 6--|-- 00000000 --|---->


Getting Key : 1
<----|-- 00000000 --|--Key : 2--|--Value : 6--|-- 00000000 --|---->

-1

Putting Key : 1 and Value : 5
<----|-- 00000000 --|--Key : 1--|--Value : 5--|-- 001F5C48 --|----><----|-- 00204C90 --|--Key : 2--|--Value : 6--|-- 00000000 --|---->


Putting Key : 1 and Value : 2
<----|-- 00000000 --|--Key : 1--|--Value : 2--|-- 001F5C48 --|----><----|-- 00204810 --|--Key : 2--|--Value : 6--|-- 00000000 --|---->


Getting Key : 1
<----|-- 00000000 --|--Key : 1--|--Value : 2--|-- 001F5C48 --|----><----|-- 002049D0 --|--Key : 2--|--Value : 6--|-- 00000000 --|---->

2

Getting Key : 2
<----|-- 00000000 --|--Key : 2--|--Value : 6--|-- 002049D0 --|----><----|-- 00204DD0 --|--Key : 1--|--Value : 2--|-- 00000000 --|---->

6

*/
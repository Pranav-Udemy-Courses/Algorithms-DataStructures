#include <iostream>
#define SIZE 10

using namespace std;

/*-------------------------------------
	   Return Hash Value
-------------------------------------*/
int Hash(int key)
{
	return key % SIZE;
}

/*-------------------------------------
	   Return Hash2 Value
-------------------------------------*/
int Hash2(int key)
{
	return 7 - (key % 7);
}

/*-------------------------------------
	   Find Empty Place for Insert
-------------------------------------*/
int Probe(int HT[], int key)
{
	int index = Hash(key);
	int index2 = Hash2(key);
	int i = 0;
	while (HT[(index + i * index2) % SIZE] != 0)
		i++;
	return (index + i * index2) % SIZE;
}

/*-------------------------------------
	Insert Using Linear Probing
-------------------------------------*/
void Insert(int HT[], int key)
{
	int index = Hash(key);
	if (HT[index] != 0)
		index = Probe(HT, key);
	HT[index] = key;
}

/*-------------------------------------
	Search Using Linear Probing
-------------------------------------*/
int Search(int HT[], int key)
{
	int index = Hash(key);
	int index2 = Hash2(key);
	int i = 0;
	while (HT[(index + i * index2) % SIZE] != key)
		i++;
	return (index + i * index2) % SIZE;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int HT[SIZE]{ 0 };
	Insert(HT, 5);
	Insert(HT, 25);
	Insert(HT, 15);
	Insert(HT, 35);
	cout << "35 is found at index : " << Search(HT, 35) << endl;
	system("pause");
	return 0;
}

/*
Output

35 is found at index : 2

*/

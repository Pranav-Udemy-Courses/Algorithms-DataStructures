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
	   Find Empty Place for Insert
-------------------------------------*/
int Probe(int HT[], int key)
{
	int index = Hash(key);
	int i = 0;
	while (HT[(index + i * i) % SIZE] != 0)
		i++;
	return (index + i * i) % SIZE;
}

/*-------------------------------------
	Insert Using Quadratic Probing
-------------------------------------*/
void Insert(int HT[], int key)
{
	int index = Hash(key);
	if (HT[index] != 0)
		index = Probe(HT, key);
	HT[index] = key;
}

/*-------------------------------------
	Search Using Quadratic Probing
-------------------------------------*/
int Search(int HT[], int key)
{
	int index = Hash(key);
	int i = 0;
	while (HT[(index + i * i) % SIZE] != key)
		i++;
	return (index + i * i) % SIZE;
}

/*-------------------------------------
	   Main Method
-------------------------------------*/
int main()
{
	int HT[SIZE]{ 0 };
	Insert(HT, 12);
	Insert(HT, 15);
	Insert(HT, 25);
	Insert(HT, 35);
	cout << "35 is found at index : " << Search(HT, 35) << endl;
	system("pause");
	return 0;
}

/*
Output

35 is found at index : 9

*/

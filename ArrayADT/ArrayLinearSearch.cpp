#include <iostream>

using namespace std;

/* Data Structure of Array*/
struct Array
{
    int p[10]; // An array created in Stack section of the Main memory
    int size; // Tells size of array
    int length; // Tells how many elements are currently there inside array
};

/* Display elements of Array*/
void Display(Array arr)
{
    cout << "Printing array elements : " << endl;
    for (int m = 0; m < arr.length; ++m)
    {
        cout << arr.p[m] << endl;
    }
}

/* Swaps two numbers*/
void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* If the key is found move one place to left*/
int LinearTransposition(Array* arr, int key)
{
    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->p[i] == key)
        {
            if (i != 0)
            {
                Swap(&arr->p[i], &arr->p[i - 1]);
                return i - 1;
            }
            return 0;
        }
    }
    return -1;
}

/* If key is found move to start index i.e. 0*/
int LinearMoveToHead(Array* arr, int key)
{
    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->p[i] == key)
        {
            Swap(&arr->p[i], &arr->p[0]);
            return 0;
        }
    }
    return -1;
}

/* If key is found return index of key*/
int LinearSearch(Array arr, int key)
{
    for (int i = 0; i < arr.length; ++i)
    {
        if (arr.p[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    Array arr{ {1,2,3,4,5,6,7,8,9,10}, 10, 10 };
    Display(arr);
    cout << "In LinearSearch 5 is found at " << LinearSearch(arr, 5) << endl; // Output : 5 is found at 4th position
    cout << "In LinearTransposition 5 is found at " << LinearTransposition(&arr, 5) << endl; // Output : 5 is found at 3rd position
    cout << "In LinearTransposition 5 is found at " << LinearTransposition(&arr, 5) << endl; // Output : 5 is found at 2nd position
    cout << "In LinearMoveToHead 5 is found at " << LinearMoveToHead(&arr, 5) << endl; // Output : 5 is found at 0th position
    Display(arr);
    system("pause");
    return 0;
}

/*
Output
Printing array elements :
1
2
3
4
5
6
7
8
9
10
In LinearSearch 5 is found at 4
In LinearTransposition 5 is found at 3
In LinearTransposition 5 is found at 2
In LinearMoveToHead 5 is found at 0
Printing array elements :
5
2
1
3
4
6
7
8
9
10
*/
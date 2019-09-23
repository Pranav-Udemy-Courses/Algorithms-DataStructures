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

int BinarySearchIterative(Array arr, int low, int high, int key)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if (arr.p[mid] == key)
            return mid;
        else if (key < arr.p[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int BinarySearchRecursive(Array arr, int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr.p[mid] == key)
            return mid;
        else if (key < arr.p[mid])
            return BinarySearchRecursive(arr, low, mid - 1, key);
        else
            return BinarySearchRecursive(arr, mid + 1, high, key);
    }
    return -1;
}

int main()
{
    Array arr{ {1,2,3,4,5,6}, 10, 6 };
    Display(arr);
    cout << "In BinarySearchIterative 5 is found at " << BinarySearchIterative(arr, 0, arr.length--, 5) << endl;
    cout << "In BinarySearchIterative 2 is found at " << BinarySearchIterative(arr, 0, arr.length--, 2) << endl;
    cout << "In BinarySearchRecursive 5 is found at " << BinarySearchRecursive(arr, 0, arr.length--, 5) << endl;
    cout << "In BinarySearchRecursive 2 is found at " << BinarySearchRecursive(arr, 0, arr.length--, 2) << endl;
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
In BinarySearchIterative 5 is found at 4
In BinarySearchIterative 2 is found at 1
In BinarySearchRecursive 5 is found at 4
In BinarySearchRecursive 2 is found at 1
*/
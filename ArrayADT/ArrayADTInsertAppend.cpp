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

/* Add an element to the end of Array*/
void Append(Array* arr, int x)
{
    if (arr->length < arr->size)
        arr->p[arr->length++] = x; // Add element to the end and then increment the length.
}

/* Add an element at given index of an Array*/
void Insert(Array* arr, int index, int x)
{
    if (index >=0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; --i)
            arr->p[i] = arr->p[i - 1]; // Move all the elements to right by one place
        arr->p[index] = x; // Insert the element at given index
        arr->length++; // Increment the length by one
    }
}
int main()
{
    Array arr{ {1,2,3,4,5,6}, 10, 6 };
    Display(arr);
    Append(&arr, 8);
    Display(arr);
    Insert(&arr, 0, 7);
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
Printing array elements :
1
2
3
4
5
6
8
Printing array elements :
7
1
2
3
4
5
6
8
*/
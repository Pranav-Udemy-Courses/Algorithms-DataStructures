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

/* Gets element at given index of Array*/
int GetElement(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.p[index];
    }
    return -1;
}

/* Sets element at given index of Array*/
void SetElement(Array* arr, int index, int element)
{
    if (index >= 0 && index < arr->length)
    {
        arr->p[index] = element;
    }
}

/* Gets maximum element of Array*/
int MaxElement(Array arr)
{
    int max = arr.p[0];
    for (int i = 1; i < arr.length; ++i)
    {
        if (arr.p[i] > max)
            max = arr.p[i];
    }
    return max;
}

/* Gets minimum element of Array*/
int MinElement(Array arr)
{
    int min = arr.p[0];
    for (int i = 1; i < arr.length; ++i)
    {
        if (arr.p[i] < min)
            min = arr.p[i];
    }
    return min;
}

/* Gets sum of all elements of Array Iteratively*/
int SumIterative(Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; ++i)
        sum += arr.p[i];
    return sum;
}

/* Gets sum of all elements of Array Recursively*/
int SumRecursive(Array arr, int end)
{
    if (end < 0)
        return 0;
    return SumRecursive(arr, end-1) + arr.p[end];
}

float Average(Array arr)
{
    return (float)SumIterative(arr) / arr.length;
}

int main()
{
    Array arr{ {1,2,3,4,5,6}, 10, 6 };
    Display(arr);
    cout << "GetElement returns : " << GetElement(arr, 2) << endl;
    SetElement(&arr, 2, 7);
    cout << "MaxElement returns : " << MaxElement(arr) << endl;
    cout << "MinElement returns : " << MinElement(arr) << endl;
    cout << "SumIterative returns : " << SumIterative(arr) << endl;
    cout << "SumRecursive returns : " << SumRecursive(arr, arr.length-1) << endl;
    cout << "Average returns : " << Average(arr) << endl;
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
GetElement returns : 3
MaxElement returns : 7
MinElement returns : 1
SumIterative returns : 25
SumRecursive returns : 25
Average returns : 4.16667
*/
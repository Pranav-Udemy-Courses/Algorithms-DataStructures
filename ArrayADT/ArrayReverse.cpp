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

/* Reverses all elements of Array using Auxiliary array*/
void ReverseAux(Array* arr)
{
    int* b = new int[arr->length];
    for (int i = 0, j = arr->length - 1; j>=0 ; ++i, --j)
    {
        b[i] = arr->p[j];
    }
    for (int i = 0; i < arr->length; ++i)
    {
        arr->p[i] = b[i];
    }
    delete[]b;
}

/* Reverses all elements of Array using Interchange method */
void ReverseInterChange(Array* arr)
{
    for (int i = 0, j = arr->length - 1; i < j; ++i, --j)
    {
        int temp = arr->p[i];
        arr->p[i] = arr->p[j];
        arr->p[j] = temp;
    }
}

int main()
{
    Array arr{ {1,2,3,4,5,6}, 10, 6 };
    Display(arr);
    ReverseAux(&arr);
    Display(arr);
    ReverseInterChange(&arr);
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
6
5
4
3
2
1
Printing array elements :
1
2
3
4
5
6
*/
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

/* Merges elements of Array1 and Array2 into Array3 */
Array* MergeArray(Array* arr1, Array* arr2)
{
    int i = 0, j = 0, k = 0;
    Array* arr3 = new Array();
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->p[i] < arr2->p[j])
            arr3->p[k++] = arr1->p[i++];
        else
            arr3->p[k++] = arr2->p[j++];
    }
    for(;i<arr1->length;++i)
        arr3->p[k++] = arr1->p[i];
    for (; j < arr2->length; ++j)
        arr3->p[k++] = arr2->p[j];
    arr3->length = arr1->length+arr2->length;
    arr3->size = 10;
    return arr3;
}

int main()
{
    Array arr1 = { {1,3,5,7,9}, 10,5 };
    Display(arr1);
    Array arr2 = { {2,4,6,8,10}, 10,5 };
    Display(arr2);
    Array* arr3 = MergeArray(&arr1, &arr2);
    Display(*arr3);
    system("pause");
    return 0;
}
/*
Output
Printing array elements :
1
3
5
7
9
Printing array elements :
2
4
6
8
10
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
*/
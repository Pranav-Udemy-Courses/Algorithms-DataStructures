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
 
/* Inserts element correctly in a sorted array */
void InsertSort(Array* arr, int element)
{
    if (arr->length == arr->size)
        return;
 
    int i = arr->length - 1;
    while (arr->p[i] > element)
    {
        arr->p[i + 1] = arr->p[i];
        --i;
    }
    arr->p[i + 1] = element;
    arr->length++;
}
 
/* Checks if the array is sorted or not */
bool IsArraySorted(Array arr)
{
    for (int i = 0; i < arr.length - 1; ++i)
    {
        if (arr.p[i] > arr.p[i + 1])
            return false;
    }
    return true;
}
 
/* Rearranges all positive numbers to one side and all negative numbers to another */
void RearrangeNumbers(Array* arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while(arr->p[i]<0)
        {
            ++i;
        }
        while (arr->p[j] >= 0)
        {
            --j;
        }
        if (i < j)
        {
            int temp = arr->p[i];
            arr->p[i] = arr->p[j];
            arr->p[j] = temp;
        }
    }
}
 
int main()
{
    Array arr = { {1,2,3,5,6}, 10,5 };
    Display(arr);
    InsertSort(&arr, 4);
    Display(arr);
    cout <<"The arr array is sorted ? : " << std::boolalpha << IsArraySorted(arr) << endl;
    Array arrayNum = { {-1,2,-4,7,-11,8,-6,99}, 10, 8 };
    cout << "The arrayNum array is sorted ? : " << std::boolalpha << IsArraySorted(arrayNum) << endl;
    RearrangeNumbers(&arrayNum);
    Display(arrayNum);
    system("pause");
    return 0;
}
 
/*
Output
Printing array elements :
1
2
3
5
6
Printing array elements :
1
2
3
4
5
6
The arr array is sorted ? : true
The arrayNum array is sorted ? : false
Printing array elements :
-1
-6
-4
-11
7
8
2
99
*/
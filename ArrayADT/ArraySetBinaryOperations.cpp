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
    cout << "Printing array elements : ";
    for (int m = 0; m < arr.length; ++m)
    {
        cout << arr.p[m] << "   ";
    }
    cout << endl;
}

/* Union for unsorted arrays */
Array* UnionUnsorted(Array* arr1, Array* arr2)
{
    int k = 0;
    Array* arr3 = new Array();
    for (int i = 0; i < arr1->length; ++i)
    {
        arr3->p[k++] = arr1->p[i];
    }

    for (int i = 0; i < arr2->length; ++i)
    {
        bool isPresent = false;
        for (int j = 0; j < arr1->length; ++j)
        {
            if (arr2->p[i] == arr1->p[j])
            {
                isPresent = true;
                break;
            }
        }
        if (!isPresent)
            arr3->p[k++] = arr2->p[i];
    }
    arr3->length = k;
    arr3->size = k;
    return arr3;
}

Array* UnionSorted(Array* arr1, Array* arr2)
{
    int i = 0, j = 0, k = 0;
    Array* arr3 = new Array();
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->p[i] < arr2->p[j])
            arr3->p[k++] = arr1->p[i++];
        else if (arr1->p[i] > arr2->p[j])
            arr3->p[k++] = arr2->p[j++];
        else
        {
            arr3->p[k++] = arr1->p[i++];
            j++;
        }
    }

    for (; i < arr1->length; ++i)
    {
        arr3->p[k++] = arr1->p[i];
    }

    for (; j < arr2->length; ++j)
    {
        arr3->p[k++] = arr2->p[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

/* Intersection of 2 unsorted arrays */
Array* IntersectionUnsorted(Array* arr1, Array* arr2)
{
    int k = 0;
    Array* arr3 = new Array();
    for (int i = 0; i < arr1->length; ++i)
    {
        for (int j = 0; j < arr2->length; ++j)
        {
            if (arr1->p[i] == arr2->p[j])
            {
                arr3->p[k++] = arr1->p[i++];
                j++;
                break;
            }
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

/* Intersection of 2 unsorted arrays */
Array* IntersectionSorted(Array* arr1, Array* arr2)
{
    int i = 0, j = 0, k = 0;
    Array* arr3 = new Array();
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->p[i] < arr2->p[j])
            i++;
        else if (arr1->p[i] > arr2->p[j])
            j++;
        else
        {
            arr3->p[k++] = arr1->p[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

/* Difference between unsorted array1 and unsorted array2 */
Array* DifferenceUnsorted(Array* arr1, Array* arr2)
{
    int k = 0;
    Array* arr3 = new Array();

    for (int i = 0; i < arr1->length; ++i)
    {
        bool isPresent = false;
        for (int j = 0; j < arr2->length; ++j)
        {
            if (arr1->p[i] == arr2->p[j])
            {
                isPresent = true;
                break;
            }
        }
        if (!isPresent)
            arr3->p[k++] = arr1->p[i];
    }
    arr3->length = k;
    arr3->size = k;
    return arr3;
}

/* Difference between sorted array1 and sorted array2 */
Array* DifferenceSorted(Array* arr1, Array* arr2)
{
    int i = 0, j = 0, k = 0;
    Array* arr3 = new Array();
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->p[i] < arr2->p[j])
            arr3->p[k++] = arr1->p[i++];
        else if (arr1->p[i] > arr2->p[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; ++i)
    {
        arr3->p[k++] = arr1->p[i];
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    Array arr1 = { {3,5,10,4,6}, 10, 5 };
    Display(arr1);
    Array arr2 = { {12,4,7,2,5}, 10, 5 };
    Display(arr2);
    Array* arr3 = UnionUnsorted(&arr1, &arr2);
    cout << "The union of unsorted arrays is : ";
    Display(*arr3);
    arr3 = IntersectionUnsorted(&arr1, &arr2);
    cout << "The Intersection of unsorted arrays is : ";
    Display(*arr3);
    arr3 = DifferenceUnsorted(&arr1, &arr2);
    cout << "The Difference of unsorted arrays is : ";
    Display(*arr3);
    Array array1 = { {3,4,5,6,10}, 10, 5 };
    Display(array1);
    Array array2 = { {2,4,5,7,12}, 10, 5 };
    Display(array2);
    Array* array3 = UnionSorted(&array1, &array2);
    cout << "The union of sorted arrays is : ";
    Display(*array3);
    array3 = IntersectionSorted(&array1, &array2);
    cout << "The Intersection of sorted arrays is : ";
    Display(*array3);
    array3 = DifferenceSorted(&array1, &array2);
    cout << "The Difference of sorted arrays is : ";
    Display(*array3);
    system("pause");
    return 0;
}
/*
Output
Printing array elements : 3   5   10   4   6
Printing array elements : 12   4   7   2   5
The union of unsorted arrays is : Printing array elements : 3   5   10   4   6   12   7   2
The Intersection of unsorted arrays is : Printing array elements : 5   4
The Difference of unsorted arrays is : Printing array elements : 3   10   6
Printing array elements : 3   4   5   6   10
Printing array elements : 2   4   5   7   12
The union of sorted arrays is : Printing array elements : 2   3   4   5   6   7   10   12
The Intersection of sorted arrays is : Printing array elements : 4   5
The Difference of sorted arrays is : Printing array elements : 3   6   10
*/

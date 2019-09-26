#include <iostream>

using namespace std;

struct Array
{
    int* p; // Points to an array created in Heap section of the Main memory
    int size; // Tells size of array
    int length; // Tells how many elements are currently there inside array
};

/* Display all the elements of array */
void Display(Array arr)
{
    cout << "Printing array elements : " << endl;
    for (int m = 0; m < arr.length; ++m)
    {
        cout << arr.p[m] << endl;
    }
}

/* Add an element at given index of an Array */
void Insert(Array* arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; --i)
            arr->p[i] = arr->p[i - 1]; // Move all the elements to right by one place
        arr->p[index] = x; // Insert the element at given index
        arr->length++; // Increment the length by one
    }
}

/* Deletes an element at given index of an Array */
int Delete(struct Array* arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->p[index];
        for (i = index; i < arr->length - 1; i++)
            arr->p[i] = arr->p[i + 1];
        arr->length--;
        return x;
    }
    return 0;
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

/* Gets sum of all elements of Array Iteratively*/
int SumIterative(Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; ++i)
        sum += arr.p[i];
    return sum;
}

int main()
{
    Array arr;
    int element, index;
    int x;
    cout << "Enter the size of array" << endl;
    cin >> x;
    arr.size = x;
    arr.p = new int[arr.size];
    arr.length = 0;

    int ch=0;

    do
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Sum" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;


        switch (ch)
        {
        case 1:
            cout << "Enter the index : ";
            cin >> index;
            cout << "Enter the element : ";
            cin >> element;
            Insert(&arr, index, element);
            break;
        case 2:
            cout << "Enter the index ";
            cin >> index;
            cout << "The Deleted element is : " << Delete(&arr, index) << endl;
            break;
        case 3:
            cout << "Enter the element to search : ";
            cin >> element;
            cout << "The key is found at index : "<< LinearSearch(arr, element) << endl;
            break;
        case 4:
            cout << "The sum of elements of array is : " << SumIterative(arr) << endl;
            break;
        case 5:
            Display(arr);
            break;
        default:
            break;
        }
    } while (ch < 6);
    
    system("pause");
    return 0;
}

/*
Output
Enter the size of array
5
1. Insert
2. Delete
3. Search
4. Sum
5. Display
6. Exit
Enter your choice : 1
Enter the index : 0
Enter the element : 1
1. Insert
2. Delete
3. Search
4. Sum
5. Display
6. Exit
Enter your choice : 1
Enter the index : 1
Enter the element : 2
1. Insert
2. Delete
3. Search
4. Sum
5. Display
6. Exit
Enter your choice : 5
Printing array elements :
1
2
1. Insert
2. Delete
3. Search
4. Sum
5. Display
6. Exit
Enter your choice : 4
The sum of elements of array is : 3
1. Insert
2. Delete
3. Search
4. Sum
5. Display
6. Exit
Enter your choice : 2
Enter the index 1
The Deleted element is : 2
1. Insert
2. Delete
3. Search
4. Sum
5. Display
6. Exit
Enter your choice : 5
Printing array elements :
1
1. Insert
2. Delete
3. Search
4. Sum
5. Display
6. Exit
Enter your choice : 1
Enter the index : 1
Enter the element : 3
1. Insert
2. Delete
3. Search
4. Sum
5. Display
6. Exit
Enter your choice : 3
Enter the element to search : 3
The key is found at index : 1
1. Insert
2. Delete
3. Search
4. Sum
5. Display
6. Exit
Enter your choice : 6
*/
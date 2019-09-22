#include <iostream>

using namespace std;

struct Array
{
    int p[20]; // An array created in Stack section of the Main memory
    int size; // Tells size of array
    int length; // Tells how many elements are currently there inside array
};

void Display(Array arr)
{
    cout << "Printing array elements : " << endl;
    for (int m = 0; m < arr.length; ++m)
    {
        cout << arr.p[m] << endl;
    }
}

int main()
{
    Array arr{ {1,2,3,4,5,6}, 20, 6 };
    cout << "The length of array is : " << arr.length << endl;
    Display(arr);

    system("pause");
    return 0;
}

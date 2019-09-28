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

/* Finds multiple missing elements in an array */ 
void MultiMissingElements(Array arr1) 
{ 
    cout << "The missing elements are : "; 
    int diff = arr1.p[0] - 0; 
    for (int i = 1; i < arr1.length; ++i) 
    { 
        if (arr1.p[i] - i != diff) 
        { 
            while (diff < (arr1.p[i] - i)) 
            { 
                cout << diff + i << "  "; 
                diff++; 
            } 
        } 
    } 
    cout << endl; 
} 

int main() 
{ 
    Array arr1 = { {1,2,3,5,6,9}, 10, 6 }; 
    Display(arr1); 
    MultiMissingElements(arr1); 
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
9 
The missing elements are : 4  7  8 
*/ 
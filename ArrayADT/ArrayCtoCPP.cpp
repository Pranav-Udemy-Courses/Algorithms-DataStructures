Array.hxx

#pragma once

class Array
{
public:
    Array();
    Array(int size);
    ~Array();
    void Display();
    void Insert(int index, int element);

private:
    int* p;
    int size;
    int length;
};



Array.cxx

#include "Array.hxx"
#include <iostream>

using namespace std;

Array::Array()
{
    size = 10;
    p = new int[size];
    length = 0;
    
}

Array::Array(int size)
{
    this->size = size;
    p = new int[size];
    length = 0;
}

Array::~Array()
{
    delete[] p;
}

void Array::Display()
{
    cout << "Printing the Elements of array : " << endl;
    for (int i = 0; i < length; ++i)
    {
        cout << p[i] << "   ";
    }
    cout << endl;
}

void Array::Insert(int index, int element)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; --i)
        {
            p[i] = p[i - 1];
        }
        p[index] = element;
        length++;
    }
}



Source.cpp

#include "Array.hxx"
#include <iostream>

using namespace std;

int main()
{
    Array* arr = nullptr;
    int size;
    cout << "Enter size of array" << endl;
    cin >> size;
    arr = new Array(size);
    arr->Insert(0, 1);
    arr->Insert(1, 2);
    arr->Insert(2, 3);
    arr->Insert(1, 4);
    arr->Display();
    system("pause");
    return 0;
}

/*
Output
Enter size of array
5
Printing the Elements of array :
1   4   2   3
*/
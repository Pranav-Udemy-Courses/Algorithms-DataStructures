		#include <iostream>
		
		using namespace std;
		
		struct Array
		{
		    int* p; // Points to an array created in Heap section of the Main memory
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
		    Array arr;
		    int x;
		    cout << "Enter the size of array" << endl;
		    cin >> x;
		    arr.size = x;
		    arr.p = new int[arr.size];
		    arr.length = 0;
		
		    int n, i;
		    cout << "Enter the number of elements" << endl;
		    cin >> n;
		
		    cout << "Enter all the elements" << endl;
		    for (i = 0; i < n; ++i)
		    {
		        cin >> arr.p[i];
		    }
		    arr.length = n;
		    cout << "The Length of array is : " <<arr.length << endl;
		
		    Display(arr);
		
		    system("pause");
		    return 0;
		}

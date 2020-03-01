#include<iostream>
#include<algorithm>

using namespace std;

/* Struct of Box */
typedef struct Box_t
{
	int height;
	int width;
	int depth;
	int area;
}Box_s;

/* Box stacking logic */
void BoxStacking(Box_s boxArr[], int numOfBox)
{
	int* maxHeight = new int[numOfBox];
	int* result = new int[numOfBox];
	for (int i = 0; i < numOfBox; ++i)
	{
		maxHeight[i] = boxArr[i].height;
		result[i] = i;
	}

	int max_height = 0;
	for (int i = 1; i < numOfBox; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (boxArr[i].depth < boxArr[j].depth && boxArr[i].width < boxArr[j].width)
			{
				if (maxHeight[i] < maxHeight[j] + boxArr[i].height)
				{
					maxHeight[i] = maxHeight[j] + boxArr[i].height;
					result[i] = j;
				}
			}
		}
		if (max_height < maxHeight[i])
			max_height = maxHeight[i];
	}
	cout << endl << "BoxNumber : ";
	for (int i = 0; i < numOfBox; ++i)
	{
		cout << i << " ";
	}
	cout << endl << "MaxHeight : ";
	for (int i = 0; i < numOfBox; ++i)
	{
		cout << maxHeight[i] << " ";
	}
	cout << endl;
	cout << "ResultArr : ";
	for (int i = 0; i < numOfBox; ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl << "The maximum height that can be achieved is : " << max_height << endl;
	delete[] maxHeight;
	delete[] result;
}

/* Compare for sort STL */
bool compareArea(Box_s& b1, Box_s& b2)
{
	return b1.area >= b2.area;
}

/* Compare for quick sort */
int compareArea1(const void* b1, const void* b2)
{
	int a = ((Box_s*)(b1))->area;
	int b = ((Box_s*)(b2))->area;
	return (b > a) - (b < a);
}

/* Main Method */
int main()
{
	int numOfBox, height, width, depth;
	cin >> numOfBox;

	Box_s* boxArr = new Box_s[numOfBox*3];
	for (int i = 0; i < numOfBox; ++i)
	{
		Box_s b;
		cin >> height >> width >> depth;
		if (height >= width)
		{
			b.depth = height;
			b.width = width;
			b.height = depth;
		}
		else
		{
			b.depth = width;
			b.width = height;
			b.height = depth;
		}
		b.area = b.depth * b.width;
		boxArr[3 * i + 0] = b;
		cout << boxArr[3 * i + 0].depth << " " << boxArr[3 * i + 0].width << " " << boxArr[3 * i + 0].height << " area : " << boxArr[3 * i + 0].area << endl;
		
		if (height >= depth)
		{
			b.depth = height;
			b.width = depth;
			b.height = width;
		}
		else
		{
			b.depth = depth;
			b.width = height;
			b.height = width;
		}
		b.area = b.depth * b.width;
		boxArr[3 * i + 1] = b;

		cout << boxArr[3 * i + 1].depth << " " << boxArr[3 * i + 1].width << " " << boxArr[3 * i + 1].height << " area : " << boxArr[3 * i + 1].area << endl;

		if (width >= depth)
		{
			b.depth = width;
			b.width = depth;
			b.height = height;
		}
		else
		{
			b.depth = depth;
			b.width = width;
			b.height = height;
		}
		b.area = b.depth * b.width;
		boxArr[3 * i + 2] = b;

		cout << boxArr[3 * i + 2].depth << " " << boxArr[3 * i + 2].width << " " << boxArr[3 * i + 2].height << " area : " << boxArr[3 * i + 2].area << endl;

	}

//	sort(boxArr, boxArr + (3*numOfBox), compareArea);

	qsort(boxArr, 3*numOfBox, sizeof(Box_s) ,compareArea1);

	BoxStacking(boxArr, 3 * numOfBox);

	delete[] boxArr;
	return 0;
}

/*

Output

2
1 2 4
2 1 4 area : 2
4 1 2 area : 4
4 2 1 area : 8
3 2 5
3 2 5 area : 6
5 3 2 area : 15
5 2 3 area : 10

BoxNumber : 0 1 2 3 4 5
MaxHeight : 2 3 3 7 5 11
ResultArr : 0 1 0 0 1 3
The maximum height that can be achieved is : 11

*/

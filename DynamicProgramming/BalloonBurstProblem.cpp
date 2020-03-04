#include <iostream>

using namespace std;

/* Print Table for better understanding */
void PrintTable(int** A, int numOfBalloon)
{
    cout << endl;
    for (int i = 0; i < numOfBalloon; ++i)
    {
        for (int j = 0; j < numOfBalloon; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

/* Balloon Burst using DP */
int BurstBalloon(int balloonValArr[], int numOfBalloon)
{
    int** A = new int*[numOfBalloon];
    for (int i = 0; i < numOfBalloon; ++i)
    {
        A[i] = new int[numOfBalloon] {0};
    }
    int row=numOfBalloon, col = 0, j=0;
    while (row > 0)
    {
        for (int i = 0; i < row; ++i)
        {
            cout << endl << "A[" <<i << "][" << col << "]" << endl;
            for (int k = i; k <= col; ++k)
            {
                int leftNum = 0;
                int rightNum = 0;
                if (k != 0)
                    leftNum = A[i][k - 1];
                if (k != col)
                    rightNum = A[k + 1][col];
                int currNum = balloonValArr[k];
                int prevMul = 1;
                int nextMul = 1;
                
                if (i != 0)
                    prevMul = balloonValArr[i - 1];
                if (col != numOfBalloon - 1)
                    nextMul = balloonValArr[col + 1];
                int ans = prevMul * currNum * nextMul;
                cout << "case : " << k << endl;
                cout << "\t" << "previous num : " << prevMul << " curr num : " << currNum << " next num : " << nextMul << endl;
                cout << "\t" << "left num : " << leftNum << " right num : " << rightNum << " ans : " << ans << endl;
                ans += leftNum + rightNum;
                cout << "\t" << "Total : " << ans << endl;
                if(ans > A[i][col])
                    A[i][col] = ans;
            }
            ++col;
        }
        --row;
        ++j;
        col = j;
    }
    PrintTable(A, numOfBalloon);
    int res = A[0][numOfBalloon - 1];
    for (int i = 0; i < numOfBalloon; ++i)
    {
        delete[] A[i];
    }
    return res;
}

/* Main Method */
int main()
{
    int numOfBalloon, balloonVal;
    cin >> numOfBalloon;
    int* balloonValArr = new int[numOfBalloon];
    for (int i = 0; i < numOfBalloon; ++i)
    {
        cin >> balloonVal;
        balloonValArr[i] = balloonVal;
    }
    int ans = BurstBalloon(balloonValArr, numOfBalloon);
    cout << endl << "The maximum value achieved by bursting balloons is : " << ans << endl << endl;
    delete[] balloonValArr;
    return 0;
}

/*

Output

4

3
1
5
8

A[0][0]
case : 0
        previous num : 1 curr num : 3 next num : 1
        left num : 0 right num : 0 ans : 3
        Total : 3

A[1][1]
case : 1
        previous num : 3 curr num : 1 next num : 5
        left num : 0 right num : 0 ans : 15
        Total : 15

A[2][2]
case : 2
        previous num : 1 curr num : 5 next num : 8
        left num : 0 right num : 0 ans : 40
        Total : 40

A[3][3]
case : 3
        previous num : 5 curr num : 8 next num : 1
        left num : 0 right num : 0 ans : 40
        Total : 40

A[0][1]
case : 0
        previous num : 1 curr num : 3 next num : 5
        left num : 0 right num : 15 ans : 15
        Total : 30
case : 1
        previous num : 1 curr num : 1 next num : 5
        left num : 3 right num : 0 ans : 5
        Total : 8

A[1][2]
case : 1
        previous num : 3 curr num : 1 next num : 8
        left num : 0 right num : 40 ans : 24
        Total : 64
case : 2
        previous num : 3 curr num : 5 next num : 8
        left num : 15 right num : 0 ans : 120
        Total : 135

A[2][3]
case : 2
        previous num : 1 curr num : 5 next num : 1
        left num : 0 right num : 40 ans : 5
        Total : 45
case : 3
        previous num : 1 curr num : 8 next num : 1
        left num : 40 right num : 0 ans : 8
        Total : 48

A[0][2]
case : 0
        previous num : 1 curr num : 3 next num : 8
        left num : 0 right num : 135 ans : 24
        Total : 159
case : 1
        previous num : 1 curr num : 1 next num : 8
        left num : 3 right num : 40 ans : 8
        Total : 51
case : 2
        previous num : 1 curr num : 5 next num : 8
        left num : 30 right num : 0 ans : 40
        Total : 70

A[1][3]
case : 1
        previous num : 3 curr num : 1 next num : 1
        left num : 0 right num : 48 ans : 3
        Total : 51
case : 2
        previous num : 3 curr num : 5 next num : 1
        left num : 15 right num : 40 ans : 15
        Total : 70
case : 3
        previous num : 3 curr num : 8 next num : 1
        left num : 135 right num : 0 ans : 24
        Total : 159

A[0][3]
case : 0
        previous num : 1 curr num : 3 next num : 1
        left num : 0 right num : 159 ans : 3
        Total : 162
case : 1
        previous num : 1 curr num : 1 next num : 1
        left num : 3 right num : 48 ans : 1
        Total : 52
case : 2
        previous num : 1 curr num : 5 next num : 1
        left num : 30 right num : 40 ans : 5
        Total : 75
case : 3
        previous num : 1 curr num : 8 next num : 1
        left num : 159 right num : 0 ans : 8
        Total : 167

3 30 159 167
0 15 135 159
0 0 40 48
0 0 0 40

The maximum value achieved by bursting balloons is : 167

*/

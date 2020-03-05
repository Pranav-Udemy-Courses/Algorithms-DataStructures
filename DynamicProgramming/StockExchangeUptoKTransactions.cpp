#include<iostream>

using namespace std;

int StockExchange(int* StockPrices, int numOfDays, int numOfTransactions)
{
    int** A = new int* [numOfTransactions + 1];
    for (int i = 0; i <= numOfTransactions; ++i)
        A[i] = new int[numOfDays] { 0 };
    for (int i = 1; i <= numOfTransactions; ++i)
    {
        int maxDiff = A[i - 1][0] - StockPrices[0];
        for (int j = 1; j < numOfDays; ++j)
        {
            int temp = maxDiff + StockPrices[j];
            if (temp > A[i][j - 1])
                A[i][j] = temp;
            else
                A[i][j] = A[i][j - 1];
            if (A[i - 1][j] - StockPrices[j] > maxDiff)
                maxDiff = A[i - 1][j] - StockPrices[j];
        }
    }
    cout << endl << endl;
    for (int i = 0; i <= numOfTransactions; ++i)
    {
        for (int j = 0; j < numOfDays; ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    return A[numOfTransactions][numOfDays - 1];
}

int main()
{
    int numOfDays, stockValue, numOfTransactions, transactionFee;
    cout << "Enter the number of days : ";
    cin >> numOfDays;
    cout << "Enter the maximum transactions allowed : ";
    cin >> numOfTransactions;
    /*cout << "Enter the transaction fees : ";
    cin >> transactionFee;*/
    int* StockPrices = new int[numOfDays + 1]{ 0 };
    for (int i = 0; i < numOfDays; ++i)
    {
        cout << "Enter the price for day " << i << " : ";
        cin >> stockValue;
        StockPrices[i] = stockValue;
    }
    int res = StockExchange(StockPrices, numOfDays, numOfTransactions);
    cout << "The maximum amount from StockExchange is : " << res << endl << endl;
    return 0;
}

/*

Output

Enter the number of days : 8
Enter the maximum transactions allowed : 3
Enter the price for day 0 : 2
Enter the price for day 1 : 5
Enter the price for day 2 : 7
Enter the price for day 3 : 1
Enter the price for day 4 : 4
Enter the price for day 5 : 3
Enter the price for day 6 : 1
Enter the price for day 7 : 3


0 0 0 0 0 0 0 0
0 3 5 5 5 5 5 5
0 3 5 5 8 8 8 8
0 3 5 5 8 8 8 10

The maximum amount from StockExchange is : 10

*/

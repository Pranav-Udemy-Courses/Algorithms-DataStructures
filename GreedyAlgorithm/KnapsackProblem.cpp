/*
Problem : Out of n given objects with their corresponding  associated  weights and profits, 
          we need to fill a bag with max weight = 15kg. So that we get maximum profit
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* ----------------------------------------
    Calculate Profit Per Kg
---------------------------------------- */
void CalcProfPerKg(vector<double>& profPerKgVec, int numberOfObj, const vector<int>& profitVec, const vector<int>& wtVec)
{
    for (int i = 0; i < numberOfObj; ++i)
        profPerKgVec.push_back(static_cast<double>(profitVec[i]) / static_cast<double>(wtVec[i]));
}

/* ----------------------------------------------------------
       Returns index of maximum profit to kg ratio
---------------------------------------------------------- */
int FindMaxIndexProfPerKg(const vector<double> & profPerKgVec)
{
    double max = -1;
    int index = -1;
    for (size_t i = 0; i < profPerKgVec.size(); ++i)
    {
        if (profPerKgVec[i] > max)
        {
            max = profPerKgVec[i];
            index = i;
        }
    }
    return index;
}

/* -------------------------------
    Main Method
------------------------------- */
int main()
{
    int numberOfObj = 7;
    vector<int> obj{ 1,2,3,4,5,6,7 };
    vector<int> profit{ 10,5,15,7,6,18,3 };
    vector<int> wt{ 2,3,5,7,1,4,1 };
    vector<double> profPerKg;
    CalcProfPerKg(profPerKg, numberOfObj, profit, wt);
    unordered_map<int, double> objToQuantity;
    double finalProf = 0;
    double max_wt = 15;

    while (max_wt > 0)
    {
        int maxProfIndex = FindMaxIndexProfPerKg(profPerKg);
        if (max_wt - wt[maxProfIndex] >= 0)
        {
            finalProf += profit[maxProfIndex];
            max_wt -= wt[maxProfIndex];
            objToQuantity[maxProfIndex + 1] = wt[maxProfIndex];
        }
        else
        {
            finalProf += max_wt * profPerKg[maxProfIndex];
            objToQuantity[maxProfIndex + 1] = max_wt;
            max_wt = 0;
        }
        profPerKg[maxProfIndex] = -1;
    }

    cout << "The Maximum profit is : " << finalProf << endl;

    for (auto itr : objToQuantity)
        cout << itr.second << "kg of object " << itr.first << " + ";

    cout << "0 " << endl;
    system("pause");
    return 0;
}

/*
Output

The Maximum profit is : 55.3333

1kg of object 5 + 2kg of object 1 + 4kg of object 6 + 5kg of object 3 + 1kg of object 7 + 2kg of object 2 + 0

*/

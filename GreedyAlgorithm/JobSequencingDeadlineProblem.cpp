/*
Problem : There are n jobs with associated profits and deadlines.
          Here the assumption is work needed to complete a job is 1 hr.
          We need to find set of jobs that can be completed within their deadlines such that the profit is maximized
*/

#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------
    Main Method
------------------------------- */
int main()
{
    // Assuming that jobs are sorted based on decreasing profits
    int numberOfJobs = 7;
    vector<int> jobIds{ 1,2,3,4,5,6,7 };
    vector<int> profit{ 35, 30, 25, 20, 15, 12, 5 };
    vector<int> deadline{ 3, 4, 4, 2, 3, 1, 2 };
    vector<int> results{ 0,0,0,0 };
    int maxProfit = 0;

    for (int i = 0; i < numberOfJobs; ++i)
    {
        int j = deadline[i];
        while (j > 0)
        {
            --j;
            if (results[j] == 0)
            {
                results[j] = jobIds[i];
                maxProfit += profit[i];
                break;
            }
        }
    }

    cout << "The jobs to be scheduled to give maximum profit are : ";
    for (auto i : results)
        cout << "Job" << i << ", ";
    cout << endl;

    cout << "The maximum profit will be : " << maxProfit << endl;

    system("pause");
    return 0;
}

/*
Output

The jobs to be scheduled to give maximum profit are : Job4, Job3, Job1, Job2,

The maximum profit will be : 110

*/

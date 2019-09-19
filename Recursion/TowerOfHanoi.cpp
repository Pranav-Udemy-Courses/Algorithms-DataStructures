#include <iostream> 
 
using namespace std;
 
void TowerOfHanoi(int n, char source, char temporary, char destination)
{
    if (n > 0)
    {
        TowerOfHanoi(n - 1, source, destination, temporary);
        cout << "< " << source << ", " << destination << " >" << endl;
        TowerOfHanoi(n - 1, temporary, source, destination);
    }
}
int main()
{
    TowerOfHanoi(3, 'A', 'B', 'C');
    system("pause");
    return 0;
}
 
/* OUTPUT
< A, C >
< A, B >
< C, B >
< A, C >
< B, A >
< B, C >
< A, C >
*/
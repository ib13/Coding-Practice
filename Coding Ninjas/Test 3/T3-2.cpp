#include <iostream>
#include <vector>
using namespace std;
int getMostWork(vector<int> folders, int workers)
{
}
int main()
{
    int n;
    cin >> n;
    vector<int> folders(n);
    for (int i = 0; i < n; i++)
    {
        cin >> folders[i];
    }
    int workers;
    cin >> workers;
    cout << getMostWork(folders, workers);
}
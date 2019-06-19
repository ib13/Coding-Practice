#include <cmath>
#include <iostream>
using namespace std;
#include <vector>
#include <vector>
#include <algorithm>
void combinationSumHelper(vector<int> &ar, int sum, int currsum, int index, vector<vector<int>> &finalarr, vector<int> &currElements)
{
    if (currsum == sum)
    {
        finalarr.push_back(currElements);
        return;
    }

    if (currsum > sum)
        return;

    for (int i = index; i < ar.size(); i++)
    {
        currElements.push_back(ar[i]);
        combinationSumHelper(ar, sum, currsum + ar[i], i, finalarr, currElements);
        currElements.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &ar, int sum)
{
    sort(ar.begin(), ar.end());
    ar.erase(unique(ar.begin(), ar.end()), ar.end());
    vector<vector<int>> finalarr;
    vector<int> temp;
    combinationSumHelper(ar, sum, 0, 0, finalarr, temp);
    // if (finalarr.size() == 0)
    // {
    //     temp.clear();
    //     finalarr.push_back(temp);
    // }
    return finalarr;
}
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ar.push_back(x);
    }
    int sum;
    cin >> sum;
    vector<vector<int>> res = combinationSum(ar, sum);
    if (res.size() == 0)
    {
        cout << "Empty";
        return 0;
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].size() > 0)
        {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }
}

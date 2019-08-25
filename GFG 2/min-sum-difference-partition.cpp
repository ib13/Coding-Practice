#include <bits/stdc++.h>
using namespace std;

void findMinDifferenceHelper(int *arr, int n, int arrSum, int currSum, int visited[], int &sumDiff)
{
    sumDiff = min(sumDiff, abs((arrSum - currSum) - currSum));
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            findMinDifferenceHelper(arr, n, arrSum, currSum + arr[i], visited, sumDiff);
            visited[i] = 0;
        }
    }
}

int findMinDifference(int *arr, int n)
{
    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }
    int visited[n] = {0};
    int sumDiff = arrSum;
    findMinDifferenceHelper(arr, n, arrSum, 0, visited, sumDiff);
    return sumDiff;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << findMinDifference(arr, n) << endl;
    }
    return 0;
}
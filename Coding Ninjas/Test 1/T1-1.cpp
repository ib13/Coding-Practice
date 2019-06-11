#include <iostream>
using namespace std;
#include <algorithm>
int maximumProfit(int budget[], int n)
{
    sort(budget, budget + n);
    int cost = 0;
    int maxcost = 0;
    for (int i = 0; i < n; i++)
    {
        cost = (n - i) * budget[i];
        if (cost > maxcost)
            maxcost = cost;
    }
    return maxcost;
}

int main()
{
    int n, *input, i, *cost;
    cin >> n;
    input = new int[n];
    for (i = 0; i < n; i++)
        cin >> input[i];

    cout << maximumProfit(input, n) << endl;
}

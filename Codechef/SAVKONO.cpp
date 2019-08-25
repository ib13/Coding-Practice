#include <bits/stdc++.h>
using namespace std;

int minAttacks(priority_queue<int> pq, int n, int z)
{
    int count = 0;
    while (z > 0)
    {
        int topElement = pq.top();
        // cout << topElement << " ";
        z -= topElement;
        pq.pop();
        pq.push(topElement / 2);
        count++;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, z;
        cin >> n >> z;
        // int *arr = new int[n];
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            pq.push(val);
        }
        cout << minAttacks(pq, n, z) << endl;
    }
    return 0;
}
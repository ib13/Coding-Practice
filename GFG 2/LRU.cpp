#include <bits/stdc++.h>
using namespace std;

int PageFaults(int *arr, int n, int k)
{
    queue<int> q;
    bool present[1000] = {0};
    int fault = 0;
    for (int i = 0; i < n; i++)
    {
        if (present[arr[i]] == 1)
        {
            int size = q.size();
            for (int j = 0; j < size; j++)
            {
                if (q.front() != arr[i])
                {
                    q.push(q.front());
                    q.pop();
                }
                else
                {
                    q.pop();
                }
            }
            q.push(arr[i]);
        }
        else if (q.size() < k)
        {
            q.push(arr[i]);
            present[arr[i]] = 1;
            fault++;
        }
        else
        {
            present[q.front()] = 0;
            q.pop();
            q.push(arr[i]);
            present[arr[i]] = 1;
            fault++;
        }
    }
    return fault;
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
        int k;
        cin >> k;
        cout << PageFaults(arr, n, k) << endl;
    }
    return 0;
}
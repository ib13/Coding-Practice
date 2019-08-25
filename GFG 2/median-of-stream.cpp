#include <bits/stdc++.h>
using namespace std;

void medianOfStream(int *arr, int n)
{
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq1.push(arr[0]);
    cout << arr[0] << endl;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < pq1.top())
            pq1.push(arr[i]);
        else
            pq2.push(arr[i]);
        if (abs(pq1.size() - pq2.size()) > 1)
        {
            if (pq1.size() > pq2.size())
            {
                pq2.push(pq1.top());
                pq1.pop();
            }
            else if (pq2.size() > pq1.size())
            {
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        if (i % 2 == 0)
        {
            if (pq1.size() > pq2.size())
                cout << pq1.top() << endl;
            else
                cout << pq2.top() << endl;
        }
        else
        {
            cout << (pq1.top() + pq2.top()) / 2 << endl;
        }
    }
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    medianOfStream(arr, n);
    return 0;
}
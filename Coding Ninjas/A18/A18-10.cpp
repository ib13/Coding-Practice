#include <iostream>
#include <vector>
using namespace std;
#include <queue>

int buyTicket(int *arr, int n, int k)
{
    queue<int> q;           //store index of elements
    priority_queue<int> pq; //for max element priority
    for (int i = 0; i < n; i++)
    {
        q.push(i);
        pq.push(arr[i]);
    }
    int time;
    while (!q.empty())
    {
        if (arr[q.front()] == pq.top())
        {
            time++;
            if (q.front() == k)
                break;
            q.pop();
            pq.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    return time;
}
int main()
{
    int n, k, s;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
    return 0;
}

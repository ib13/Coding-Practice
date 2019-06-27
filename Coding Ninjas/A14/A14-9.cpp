#include <bits/stdc++.h>
using namespace std;

queue<int> reverseKElements(queue<int> input, int k)
{
    stack<int> s;
    int q_size = input.size();
    for (int i = 0; i < k; i++)
    {
        s.push(input.front());
        input.pop();
    }
    for (int i = 0; i < k; i++)
    {
        input.push(s.top());
        s.pop();
    }
    for (int i = 0; i < q_size - k; i++)
    {
        int front_val = input.front();
        input.pop();
        input.push(front_val);
    }
    return input;
}

int main()
{
    int n = 0;
    cin >> n;
    queue<int> Queue;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        Queue.push(temp);
    }
    int k;
    cin >> k;

    queue<int> ans = reverseKElements(Queue, k);
    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }
}
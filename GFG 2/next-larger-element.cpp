#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void nextLargerElement2(ll *arr, int n)
{
    vector<ll> ans(n);
    stack<ll> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= s.top())
            s.pop();
        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

void nextLargerElement1(ll *arr, int n)
{
    ll result[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n)
        {
            if (arr[i] < arr[j])
            {
                result[i] = arr[j];
                break;
            }
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *arr = new ll[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        nextLargerElement2(arr, n);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int *arr, int n)
{
    bool m[100000];
    memset(m, 0, sizeof(m));
    bool visited[100000];
    memset(visited, 0, sizeof(m));
    int maxLen = 1;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int len = 1;
            int curr = arr[i];
            visited[curr] = 1;
            while (curr > 0 && m[curr - 1] == 1)
            {
                curr--;
                visited[curr] = 1;
                len++;
            }
            curr = arr[i];
            while (curr < 100000 && m[curr + 1] == 1)
            {
                curr++;
                visited[curr] = 1;
                len++;
            }
            if (len > maxLen)
                maxLen = len;
        }
    }
    return maxLen;
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
        cout << longestSubsequence(arr, n) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int maxTip(int A[], int B[], int x, int y, int n, int index)
{
    if (index == n)
        return 0;

    if (x == 0)
    {
        return B[index] + maxTip(A, B, x, y - 1, n, index + 1);
    }
    if (y == 0)
    {
        return A[index] + maxTip(A, B, x - 1, y, n, index + 1);
    }
    else
    {
        return max(B[index] + maxTip(A, B, x, y - 1, n, index + 1), A[index] + maxTip(A, B, x - 1, y, n, index + 1));
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        int A[n];
        int B[n];

        for (int i = 0; i < n; i++)
            cin >> A[i];

        for (int i = 0; i < n; i++)
            cin >> B[i];

        cout << maxTip(A, B, x, y, n, 0) << endl;
    }
    return 0;
}
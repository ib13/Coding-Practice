// https://www.codechef.com/APRIL19B/problems/MAXREM
// Solved
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    // cin>>tc;
    tc = 1;
    while (tc--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        sort(A, A + n);
        int sec_max = 0;
        int max = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i + 1] > A[i])
            {
                max = A[i + 1];
                sec_max = A[i];
            }
            // if (A[i] >= max)
            // {
            //     max = A[i];
            //     sec_max = max;
            // }
            // else if (A[i] < max && A[i] >= sec_max)
            // {
            //     sec_max = A[i];
            // }
        }
        cout << sec_max;
    }
    return 0;
}
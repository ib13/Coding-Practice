#include <iostream>
using namespace std;

long maxPathSum(int ar1[], int ar2[], int m, int n)
{
    long p1 = 0, p2 = 0;
    long total_sum = 0;
    long sum1 = 0, sum2 = 0;
    while (p1 < m && p2 < n)
    {
        if (ar1[p1] == ar2[p2])
        {
            total_sum = total_sum + max(sum1, sum2) + ar1[p1];
            p1++;
            p2++;
            sum1 = 0;
            sum2 = 0;
        }
        else if (ar1[p1] < ar2[p2])
        {
            sum1 += ar1[p1];
            p1++;
        }
        else
        {
            sum2 += ar2[p2];
            p2++;
        }
    }
    // cout << total_sum << p1 << p2;
    while (p1 < m)
    {
        sum1 += ar1[p1];
        p1++;
    }
    while (p2 < n)
    {
        sum2 += ar2[p2];
        p2++;
    }
    total_sum += max(sum1, sum2);
    return total_sum;
}

int main()
{
    int *a, *b, m, n, i;
    cin >> m;
    a = new int[m];
    for (i = 0; i < m; i++)
        cin >> a[i];
    cin >> n;
    b = new int[n];
    for (i = 0; i < n; i++)
        cin >> b[i];
    long ans = maxPathSum(a, b, m, n);
    cout << ans << endl;
    delete a;
    delete b;
    return 0;
}
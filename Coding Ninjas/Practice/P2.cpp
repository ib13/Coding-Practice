#include <iostream>
using namespace std;

int maxPathSum(int *a, int *b, int m, int n)
{
    int ts1 = 0;
    int ts2 = 0;
    int sum = 0;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] == b[j])
        {
            sum += a[i] + max(ts1, ts2);
            i++;
            j++;
            ts1 = ts2 = 0;
        }
        else if (a[i] < b[j])
        {
            ts1 += a[i++];
        }
        else
        {
            ts2 += b[j++];
        }
    }
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
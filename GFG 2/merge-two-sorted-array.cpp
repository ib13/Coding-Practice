#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        int *a1 = new int[n1];
        int *a2 = new int[n2];
        for (int i = 0; i < n1; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> a2[i];
        }
        int *a3 = new int[n1 + n2];
        int p1 = 0, p2 = 0, p3 = 0;
        while (p1 < n1 && p2 < n2)
        {
            if (a1[p1] < a2[p2])
                a3[p3++] = a1[p1++];
            else
                a3[p3++] = a2[p2++];
        }
        while (p1 < n1)
        {
            a3[p3++] = a1[p1++];
        }
        while (p2 < n2)
        {
            a3[p3++] = a2[p2++];
        }
        for (int i = 0; i < n1 + n2; i++)
        {
            cout << a3[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 2, 1, 5, 4, 3};
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << ans;
}
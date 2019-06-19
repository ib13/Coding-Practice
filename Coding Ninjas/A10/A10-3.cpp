#include <iostream>
using namespace std;

int lis(int arr[], int n)
{
    int LISarr[n] = {0};
    LISarr[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int maxele = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                maxele = max(maxele, LISarr[j]);
        }
        LISarr[i] = 1 + maxele;
    }
    int LISmax = 0;
    for (int i = 0; i < n; i++)
    {
        LISmax = max(LISmax, LISarr[i]);
    }
    return LISmax;
}

int main()
{
    int n;
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << lis(arr, n);
}

#include <bits/stdc++.h>
using namespace std;

void relativeSorting(int *arr1, int *arr2, int n1, int n2)
{
    int countArray[1000000] = {0};
    for (int i = 0; i < n1; i++)
    {
        countArray[arr1[i]]++;
    }
    int index = 0;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < countArray[arr2[i]]; j++)
        {
            arr1[index++] = arr2[i];
        }
        countArray[arr2[i]] = 0;
    }
    for (int i = 0; i < 1000000; i++)
    {
        for (int j = 0; j < countArray[i]; j++)
        {
            arr1[index++] = i;
        }
    }
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        int *arr1 = new int[n1];
        int *arr2 = new int[n2];
        for (int i = 0; i < n1; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> arr2[i];
        }
        relativeSorting(arr1, arr2, n1, n2);
    }
    return 0;
}
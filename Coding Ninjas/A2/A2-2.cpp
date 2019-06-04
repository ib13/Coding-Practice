#include <iostream>
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2, int ans[])
{
    int p1 = 0, p2 = 0;
    for (int i = 0; i < size1 + size2; i++)
    {
        int min_val;
        if (p1 < size1 && p2 < size2)
        {
            if (arr1[p1] < arr2[p2])
            {
                min_val = arr1[p1];
                p1++;
            }
            else
            {
                min_val = arr2[p2];
                p2++;
            }
        }
        else if (p1 == size1 && p2 < size2)
        {
            min_val = arr2[p2];
            p2++;
        }
        else if (p1 < size1 && p2 == size2)
        {
            min_val = arr1[p1];
            p1++;
        }
        ans[i] = min_val;
    }
}

int main()
{
    int size1;
    cin >> size1;
    int *arr1 = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }
    int size2;
    cin >> size2;
    int *arr2 = new int[size2];
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    int *ans = new int[size1 + size2];

    merge(arr1, size1, arr2, size2, ans);

    for (int i = 0; i < size1 + size2; i++)
    {
        cout << ans[i] << " ";
    }
    delete arr1;
    delete arr2;
    delete ans;
}

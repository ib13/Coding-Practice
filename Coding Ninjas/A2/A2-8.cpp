#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int arr[], int n)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            c0++;
        else if (arr[i] == 1)
            c1++;
        else
            c2++;
    }
    for (int i = 0; i < c0; i++)
    {
        arr[i] = 0;
    }
    for (int i = c0; i < c0 + c1; i++)
    {
        arr[i] = 1;
    }
    for (int i = c0 + c1; i < c0 + c1 + c2; i++)
    {
        arr[i] = 2;
    }
}

int main()
{

    int size_first;

    cin >> size_first;
    int *arr_first = new int[1 + size_first];

    for (int i = 0; i < size_first; i++)
        cin >> arr_first[i];

    sort012(arr_first, size_first);

    for (int i = 0; i < size_first; i++)
        cout << arr_first[i] << " ";
    return 0;
}

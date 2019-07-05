#include <iostream>
using namespace std;

bool checkMaxHeap(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (2 * i + 2 < n)
        {
            if (arr[i] < arr[2 * i + 1] || arr[i] < arr[2 * i + 2])
                return false;
        }
        else
        {
            if (arr[i] < arr[2 * i + 1])
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    delete[] arr;
}

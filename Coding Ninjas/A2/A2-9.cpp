#include <iostream>
using namespace std;
// Think in terms of non zero numbers

void PushZeroesEnd(int arr[], int n)
{
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zeros++;
    }
    int nzc = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            arr[nzc++] = arr[i];
    }
    for (int i = n - zeros; i < n; i++)
    {
        arr[i] = 0;
    }
}

int main()
{

    int size;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    PushZeroesEnd(input, size);
    for (int i = 0; i < size; i++)
        cout << input[i] << " ";

    return 0;
}

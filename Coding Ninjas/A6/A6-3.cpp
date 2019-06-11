#include <iostream>
using namespace std;

void mergeSort(int input[], int size)
{
    if (size == 0 || size == 1)
        return;
    int l1 = size / 2;
    int l2 = size - size / 2;
    int a1[l1];
    int a2[l2];

    for (int i = 0; i < l1; i++)
        a1[i] = input[i];
    for (int i = l1; i < l1 + l2; i++)
        a2[i - l1] = input[i];

    mergeSort(a1, l1);
    mergeSort(a2, l2);

    int i = 0, j = 0, k = 0;

    while (i < l1 && j < l2)
    {
        if (a1[i] < a2[j])
            input[k++] = a1[i++];
        else
            input[k++] = a2[j++];
    }

    while (i < l1)
        input[k++] = a1[i++];

    while (j < l2)
        input[k++] = a2[j++];
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}

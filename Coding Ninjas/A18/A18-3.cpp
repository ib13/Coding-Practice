#include <iostream>
using namespace std;

void insertInHeap(int input[], int n)
{
    int childIndex = n - 1;
    while (childIndex > 0)
    {
        int parentIndex = (childIndex - 1) / 2;
        if (input[childIndex] < input[parentIndex])
        {
            int temp = input[childIndex];
            input[childIndex] = input[parentIndex];
            input[parentIndex] = temp;
        }
        else
        {
            break;
        }
        childIndex = parentIndex;
    }
}

void deleteFromHeap(int input[], int n)
{
    int maxval = input[0];
    input[0] = input[n - 1];
    input[n - 1] = maxval;
    n--;
    int parentIndex = 0;
    while (true)
    {
        int minIndex = parentIndex;
        int c1Index = 2 * parentIndex + 1;
        int c2Index = 2 * parentIndex + 2;
        if (c2Index < n)
        {
            if (input[c1Index] < input[minIndex])
                minIndex = c1Index;
            if (input[c2Index] < input[minIndex])
                minIndex = c2Index;
        }
        else if (c1Index < n)
        {
            if (input[c1Index] < input[minIndex])
                minIndex = c1Index;
        }

        if (minIndex == parentIndex)
            break;
        int temp = input[parentIndex];
        input[parentIndex] = input[minIndex];
        input[minIndex] = temp;
        parentIndex = minIndex;
    }
}

void inplaceHeapSort(int input[], int n)
{
    //Using maxHeap
    //Insert in Heap
    for (int i = 0; i < n; i++)
    {
        insertInHeap(input, i + 1);
    }

    //Delete from Heap (removeMax)
    for (int i = n - 1; i >= 0; i--)
    {
        deleteFromHeap(input, i + 1);
    }
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    inplaceHeapSort(input, size);

    for (int i = 0; i < size; i++)
        cout << input[i] << " ";

    return 0;
}

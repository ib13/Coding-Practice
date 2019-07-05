#include <iostream>
using namespace std;
#include <queue>
void findMedian(int arr[], int n)
{
    // We maintain two heaps for two halfs one max heap and one min heap.
    // Difference between sizes of two heap should not be greater than 1.
    // If greater than 1 then pop and push to another
    priority_queue<int> pq1;                            //maxheap
    priority_queue<int, vector<int>, greater<int>> pq2; //minheap
    pq1.push(arr[0]);
    cout << arr[0] << endl;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < pq1.top())
        {
            pq1.push(arr[i]);
        }
        else
        {
            pq2.push(arr[i]);
        }
        int size = pq1.size() - pq2.size();
        if (size > 1)
        {
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if (size < -1)
        {
            pq1.push(pq2.top());
            pq2.pop();
        }

        if ((i + 1) % 2 == 0)
        {
            cout << (pq1.top() + pq2.top()) / 2 << endl;
        }
        else
        {
            if (pq1.size() > pq2.size())
                cout << pq1.top() << endl;
            else
                cout << pq2.top() << endl;
        }
    }
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
    findMedian(arr, n);

    delete[] arr;
}

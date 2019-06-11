#include <iostream>
#include <map>
using namespace std;

void PairSum(int *input, int n)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[input[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m[input[i]] * m[-1 * input[i]]; j++)
        {
            cout << -1 * abs(input[i]) << " " << abs(input[i]) << endl;
        }
        m[input[i]] = 0;
        m[-1 * input[i]] = 0;
    }
}

int main()
{
    int n;
    int arr[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    PairSum(arr, n);
    return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;

void printPairs(int *input, int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[input[i]]++;
    }
    if (k != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m[input[i] - k] * m[input[i]]; j++)
            {
                cout << input[i] - k << " " << input[i] << endl;
            }
            for (int j = 0; j < m[input[i] + k] * m[input[i]]; j++)
            {
                cout << input[i] << " " << input[i] + k << endl;
            }
            m[input[i]] = 0;
        }
    }
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (m[input[i]] * m[input[i]] - 1) / 2; j++)
            {
                cout << input[i] << " " << input[i] << endl;
            }
            m[input[i]] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int k;
    cin >> k;
    printPairs(input, n, k);
}

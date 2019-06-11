#include <iostream>
using namespace std;
#include <unordered_map>
bool subArrayZeroSum(int arr[], int n)
{
    unordered_map<int, bool> m;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || m[sum] == 1)
            return true;
        m[sum] = 1;
    }
    return false;
}

int main()
{
    int n;
    int input[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    bool val = subArrayZeroSum(input, n);
    if (val)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}

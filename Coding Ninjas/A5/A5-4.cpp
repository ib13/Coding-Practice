#include <iostream>
using namespace std;

// We go from left to right by increasing array index by 1 and adding first element
int sum(int input[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return input[0] + sum(input + 1, n - 1);
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

    cout << sum(input, n) << endl;
}

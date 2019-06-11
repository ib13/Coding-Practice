#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x)
{
    // if (size == 0)
    //     return -1;
    // int ans = lastIndex(input + 1, size - 1, x);
    // if (ans == -1 && input[0] == x)
    //     return 0;
    // if (ans == -1)
    //     return ans;
    // return 1 + ans;

    // Another way
    if (size == 0)
        return -1;
    if (input[size - 1] == x)
        return size - 1;
    int ans = lastIndex(input, size - 1, x);
    return ans;
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

    int x;

    cin >> x;

    cout << lastIndex(input, n, x) << endl;
}

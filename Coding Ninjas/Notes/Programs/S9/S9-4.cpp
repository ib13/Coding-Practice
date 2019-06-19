#include <bits/stdc++.h>
using namespace std;

int countNum(int input[], int fact[], int freq[], int n)
{
    if (n == 0 || n == 1)
        return 0;

    int ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (i > input[0] && freq[i] > 0)
        {
            ans += fact[n - 1];
        }
    }
    freq[input[0]]--;
    ans += countNum(input + 1, fact, freq, n - 1);
    freq[input[0]]++;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int input[n];
    int fact[n + 1];
    int freq[10] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        freq[input[i]]++;
    }
    fact[0] = 1;
    for (int i = 0; i < n; i++)
    {
        fact[i + 1] = (i + 1) * fact[i];
    }

    cout << countNum(input, fact, freq, n);

    return 0;
}
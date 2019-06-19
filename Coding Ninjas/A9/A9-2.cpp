#include <bits/stdc++.h>
using namespace std;

long countNum(int input[], int fact[], int freq[], int n)
{
    if (n == 0 || n == 1)
        return 0;

    long ans = 0;
    long den = 1;
    long num = 0;
    for (int i = 0; i <= 9; i++)
    {
        den *= fact[freq[i]];
    }
    for (int i = 0; i <= 9; i++)
    {
        if (i > input[0] && freq[i] > 0)
        {
            ans += ((fact[n - 1] * freq[i]) / den);
        }
    }
    freq[input[0]]--;
    ans += countNum(input + 1, fact, freq, n - 1);
    freq[input[0]]++;
    return ans;
}

long numberOfNumbersWithDuplicates(long num)
{
    int n = 0;
    long numtemp = num;
    while (numtemp > 0)
    {
        n++;
        numtemp /= 10;
    }
    int input[n];
    int fact[n + 1];
    int freq[10] = {0};
    for (int i = 0; i < n; i++)
    {
        input[n - i - 1] = num % 10;
        num /= 10;
        freq[input[n - i - 1]]++;
    }
    fact[0] = 1;
    for (int i = 0; i < n; i++)
    {
        fact[i + 1] = (i + 1) * fact[i];
    }

    return countNum(input, fact, freq, n);
}
int main()
{
    long num;
    cin >> num;
    numberOfNumbersWithDuplicates(num);

    return 0;
}
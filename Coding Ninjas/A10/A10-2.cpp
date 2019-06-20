#include <iostream>
#include <cstring>
using namespace std;

long long int countDecodingDP(string digits, long long int n)
{
    long long int count[n + 1];
    count[0] = 1;
    count[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;
        if (digits[i - 1] > '0')
            count[i] = count[i - 1] % ((long long int)(1000000007));
        if (digits[i - 2] == '1' || (digits[i - 2] == '2' && digits[i - 1] < '7'))
            count[i] = (count[i] % ((long long int)(1000000007)) + count[i - 2] % ((long long int)(1000000007))) % ((long long int)(1000000007));
    }
    return count[n];
}

int main()
{
    string input = "junk";
    while (input != "0")
    {
        cin >> input;
        if (input != "0")
        {
            long long int len = input.length();
            long long int count = countDecodingDP(input, len);
            cout << count << endl;
        }
    }
    return 0;
}
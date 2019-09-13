#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    bool primeNos[1000000];
    primeNos[0] = 0;
    primeNos[1] = 0;
    for (int i = 0; i < 1000000; i++)
    {
        primeNos[i] = 1;
    }
    primeNos[0] = 0;
    primeNos[1] = 0;
    for (int i = 2; i <= sqrt(1000000); i++)
    {
        if (primeNos[i] == 1)
        {
            for (int j = 2; i * j < 1000000; j++)
            {

                primeNos[i * j] = 0;
            }
        }
    }
    // bool primeNos[1000000];
    // primeNos[0] = 0;
    // primeNos[1] = 0;
    // for (int i = 2; i < 1000000; i++)
    // {
    //     primeNos[i] = isPrime(i);
    // }

    while (t--)
    {
        int n;
        cin >> n;
        int num1 = -1, num2 = -1;
        for (int i = 2; i <= n; i++)
        {
            if (primeNos[i] == 1 && primeNos[n - i] == 1)
            {
                num1 = i;
                num2 = n - i;
                break;
            }
        }
        if (num1 != -1)
        {
            cout << num1 << " " << num2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
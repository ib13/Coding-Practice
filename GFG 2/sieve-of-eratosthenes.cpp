#include <bits/stdc++.h>
using namespace std;

int main()
{
    int primeNos[100000];
    for (int i = 0; i < 100000; i++)
    {
        primeNos[i] = 1;
    }
    for (int i = 2; i <= sqrt(100000); i++)
    {
        if (primeNos[i] == 1)
        {
            for (int j = 2; i * j < 100000; j++)
            {

                primeNos[i * j] = 0;
            }
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        if (primeNos[i] == 1)
            cout << i << " ";
    }
    return 0;
}
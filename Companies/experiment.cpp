#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void fun(int n)
{
    if (n < 0)
        return;
    fun(n - 1);
    fun(n - 1);
    fun(n - 1);
    fun(n - 1);
    fun(n - 1);
    fun(n - 1);
    fun(n - 1);
    fun(n - 1);
}

int main()
{
    auto start = high_resolution_clock::now();
    fun(10);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

void lexicographicalOrder(int num)
{
    vector<string> v;
    for (int i = 1; i <= num; i++)
    {
        v.push_back(to_string(i));
    }
    sort(v.begin(), v.end());
    for (auto x = v.begin(); x != v.end(); x++)
    {
        cout << *x << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    lexicographicalOrder(n);
}

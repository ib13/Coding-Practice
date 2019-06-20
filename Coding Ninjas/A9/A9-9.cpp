#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> A)
{
}

int n;
vector<int> A;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << solve(n, A) << endl;
}
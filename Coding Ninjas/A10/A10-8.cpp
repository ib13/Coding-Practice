#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> A)
{
    // We store the value of max score upto ith element(weather present or not)
    int maxscore[1001] = {0};
    maxscore[0] = 0;
    int count[1001] = {0};
    for (int i = 0; i < n; i++)
        count[A[i]]++;
    maxscore[1] = count[1];
    for (int i = 2; i <= 1000; i++)
    {
        // either ith element included or not included
        maxscore[i] = max(count[i] * i + maxscore[i - 2], maxscore[i - 1]);
    }
    return maxscore[1000];
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
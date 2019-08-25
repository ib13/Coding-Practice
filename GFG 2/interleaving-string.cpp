#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C)
{
    int s1 = A.size();
    int s2 = B.size();
    int s3 = C.size();
    bool visited[s3] = {0};
    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B, C;
        cin >> A >> B >> C;
        cout << isInterleave(A, B, C) << endl;
    }
    return 0;
}
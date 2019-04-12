#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];
    for (int i = 0; i < n; ++i)
    {
         cin>>A[i];
    }
    int max1=A[0];
    for (int i = 0; i < n; ++i)
    {
        max1=max(max1,A[i]);
    }
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        sum+=(max1-A[i]);
    }
    cout<<sum;
    return 0;
}
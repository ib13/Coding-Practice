#include <bits/stdc++.h>
using namespace std;
int max_sum=0;
void find_sum(int A[],int n)
{
    int v1,v2;
    v1=A[0];
    v2=0;
    for(int i=0;i<n;i++)
    {
        v1=max(v1,A[i]+v2);
        v2=v1;
    }
    cout<<v1;
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    find_sum(A,n);
    return 0;
}



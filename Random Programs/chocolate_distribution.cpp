#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        int m;
        cin>>m;
        int min1=101;
        sort(A,A+n);
        for(int i=0;i<n-m+1;i++)
        {
            min1=min(min1,abs(A[i]-A[i+m-1]));
        }
        cout<<min1<<endl;
//        for(int i=0;i<n;i++)
//        {
//            cout<<A[i];
//        }
    }
    return 0;
}
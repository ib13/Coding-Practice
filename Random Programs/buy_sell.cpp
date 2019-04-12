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
        int i=0;
        int v[n][2];
        int count=0;
        while(i<n-1)
        {
            while(i<n-1 && A[i]>=A[i+1])
                i++;
            if (i == n-1)
                break;
            v[count][0]=i;
            i++;
            ;
            while(i<n && A[i]>=A[i-1])
                i++;
            v[count][1]=i-1;
            count++;
        }
        for(int i=0;i<count;i++)
            cout<<"("<<v[i][0]<<" "<<v[i][1]<<")"<<" ";
        cout<<endl;

    }
    return 0;
}

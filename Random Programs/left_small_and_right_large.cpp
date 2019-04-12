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
	    	cin>>A[i];
	    int v1[n];
	    int v2[n];
	    v1[0]=A[0];
	    v2[n-1]=A[n-1];
	    memset(v1,0,n);
	    memset(v2,0,n);
	    int f=0;
	    for(int i=1;i<n;i++)
        {
            v1[i]=max(v1[i-1],v1[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            v2[i]=min(v2[i+1],A[i]);
        }
        for(int i=1;i<n-1;i++)
        {
            if(v1[i-1]<A[i] && v2[i+1]>A[i])
            {
                cout<<A[i]<<endl;
                f=1;
                break;

            }
        }
        if(f==0)
            cout<<-1<<endl;


	}
	return 0;
}
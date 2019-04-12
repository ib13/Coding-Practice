#include<bits/stdc++.h>
using namespace std;

int left_view(int A[],int l,int r)
{
    int count=0;
    int max1=0;
    for(int i=l;i<=r;i++)
    {
        if(A[i]>max1)
        {
            count++;
            max1=A[i];
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    int left[n];
    int right[n];
    for(int i=0;i<n;i++)
    {
        left[i]=0;
        right[i]=0;
    }
    int max1=A[0];
    left[0]=1;
    for(int i=1;i<n;i++)
    {
        if(A[i]>max1)
        {
            max1=A[i];
            left[i]=left[i-1]+1;
        }
        else
        {
            left[i]=left[i-1];
        }
    }
    for(int i=1;i<n;i++)
    {
        if(A[i]>max1)
        {
            max1=A[i];
            left[i]=left[i-1]+1;
        }
        else
        {
            left[i]=left[i-1];
        }
    }
//    for(int i=0;i<n;i++)
//        cout<<left[i];
    int v[n][2];
    int a,b;
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&a,&b);
        v.push_back(make_pair(a,b));
    }
    int res=0;
    int l,r;
    for(int j=0;j<q;j++)
    {
        l=(v[j][0]+res)%n;
        r=(v[j][1]+res)%n;
        if(l>r)
        {
            int t=l;
            l=r;
            r=t;
        }
        res=left[r]-left[l];
        cout<<res<<endl;
    }
    return 0;
}


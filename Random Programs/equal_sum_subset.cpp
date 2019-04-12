//WRONG CODE
#include <bits/stdc++.h>
using namespace std;

string equal_subset(int A[],int n,int sum)
{
    if(sum%2!=0)
        return "NO";
    sort(A,A+n);
    for(int k=0;k<n;k++)
        cout<<A[k]<<" ";
    int i=0;
    int j=0;
    sum=sum/2;
    int total=0;
    while(j<n)
    {
        if(total==sum)
            return "YES";
        else if(total<sum)
        {
            total+=A[j];
            j++;
        }
        else if(total>sum)
        {
            total-=A[i];
            i++;
        }
    }
    cout<<"dasd";
    while(sum<=total)
    {
        if(sum==total)
            return "YES";
        total-=A[i];
        i++;
        if(sum==total)
            return "YES";
    }

    return "NO";
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            sum+=A[i];
        }
        cout<<equal_subset(A,n,sum)<<endl;
    }
    return 0;
}
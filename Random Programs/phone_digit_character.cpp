#include<bits/stdc++.h>
using namespace std;
void calc(int A[],int i,string s1,int n,vector<string> v)
{
    if(i==n)
    {
        cout<<s1<<" ";
        return ;
    }
    else
    {

        string s2=v[A[i]];
        for(int j=0;j<s2.length();j++)
        {
            calc(A,i+1,s1+s2[j],n,v);
        }
    }
}
int main()
{
    vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
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
        calc(A,0,"",n,v);
        cout<<endl;

    }
    return 0;
}

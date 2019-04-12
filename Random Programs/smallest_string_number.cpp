#include<bits/stdc++.h>
using namespace std;
string s2="";
string max1="A";
int counter[1000];
void small(string s1,int n,int k,string s3)
{
    if(k==0 && max1>s3)
    {
        max1=s3;
        return;
    }
    else if(k==0)
    {
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(counter[i]==0)
        {
            counter[i]=1;
            small(s1,n,k-1,s3+s1[i]);
            counter[i]=0;
        }

    }
}

int main()
{
    string s1;
    cin>>s1;
    int n=s1.length();
    for(int i=0;i<n;i++)
        counter[i]=0;
    int k;
    cin>>k;
    small(s1,n,k,"");
    cout<<max1;
    return 0;
}
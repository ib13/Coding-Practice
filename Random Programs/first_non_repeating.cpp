#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,flag=0,i,j;
    cin>>n;
    char s[n];
    cin>>s;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[i]==s[j])
            {
                break;
            }

        }
        if(j==n)
        {
            cout<<s[i];
            flag=1;
        }
        if(flag==1)
            break;

    }
    if(flag==0)
        cout<<-1;
}



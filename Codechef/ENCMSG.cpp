#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n%2==0)
        {
            for(int i=0;i<n;i+=2)
            {
                int temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
            }
        }
        else
        {
            for(int i=0;i<n-1;i+=2)
            {
                int temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
            }
        }
        int a=(int)'a';
        int z=(int)'z';
        for(int i=0;i<n;i++)
        {
            int j=z-(int(s[i])-a);
            s[i]=char(j);
        }
        cout<<s<<endl;
    }
    return 0;
}


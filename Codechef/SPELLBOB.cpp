#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        int b=0,o=0,ex=0;
        for (int i = 0; i < 3; ++i)
        {
            if(s1[i]=='b' || s2[i]=='b')
            {
                b++;
            }
            if(s1[i]=='o' || s2[i]=='o')
            {
                o++;
            }
            if((s1[i]!='b' && s2[i]!='o') && (s2[i]!='b' && s1[i]!='o'))
            {
                ex++;
            }
        }
        if(b>=2 && o>=1 && ex==0)
        {
            cout<<"yes";
        }
        else
        {
            cout<<"no";
        }
        cout<<"\n";
    }
    return 0;
}



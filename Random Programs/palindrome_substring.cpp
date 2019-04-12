#include <bits/stdc++.h>
using namespace std;

string palindrome(string s,int i,int j)
{
    string temp="";
    for(int k=i;k<=j;k++)
        temp+=s[k];
    return temp;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s="";
        cin>>s;
        long long int max1=0;
        int n=s.length();
        string str="";
        int A[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                A[i][j]=0;
        for(int i=0;i<n;i++)
        {
            A[i][i]=1;
            string v=palindrome(s,i,i);
            if(v.length()>max1)
            {
                max1=v.length();
                str=v;
            }

        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                A[i][i+1]=1;

//                max1=max(max1,(int)palindrome(s,i,i+1).length());
                string v=palindrome(s,i,i+1);
                if(v.length()>max1)
                {
                    max1=v.length();
                    str=v;
                }
            }

        }
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                int k=j+i;

                {
                    if(s[j]==s[k] && A[j+1][k-1]==1 )
                    {
                        A[j][k]=1;
//                    max1=max(max1,(int)palindrome(s,j,k).length());
                        string v=palindrome(s,j,k);
                        if(v.length()>max1)
                        {
                            max1=v.length();
                            str=v;
                        }
                    }
                }

            }
        }
//        cout<<max1;
        cout<<str<<"\n";
    }
    return 0;
}
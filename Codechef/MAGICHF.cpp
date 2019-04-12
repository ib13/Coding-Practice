#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n,x,s;
         cin>>n>>x>>s;
         int A[s][2];
         for(int i=0;i<s;i++)
         {
             cin>>A[i][0]>>A[i][1];
         }
         for(int i=0;i<s;i++)
         {
             if(x==A[i][0])
             {
                 x=A[i][1];
             }
             else if(x==A[i][1])
             {
                 x=A[i][0];
             }
         }
         cout<<x<<endl;
     }
 }

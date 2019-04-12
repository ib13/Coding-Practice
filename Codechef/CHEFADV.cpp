#include<bits/stdc++.h>
using namespace std;

string fun(int n,int m,int x,int y)
{
    if(n==1 && m==1)
        return "Chefirnemo";
    if (n==2 && m==2)
        return "Chefirnemo";
    if(n==1 && m==2)
    {
        if(y==1)
            return "Chefirnemo";
        else
            return "Pofik";
    }
    if(n==2 && m==1)
    {
        if(x==1)
            return "Chefirnemo";
        else
            return "Pofik";
    }
    if(n<x+1 && m<y+1)
    {
        if(n==1 && m==1)
            return "Chefirnemo";
        if (n==2 && m==2)
            return "Chefirnemo";
        return "Pofik";
    }
    if(n<x+1 || m<y+1)
    {
        if(n<x+1)
        {
            if(n==1 && (m-1)%y==0)
                return "Chefirnemo";
            if(n==2 && (m-1)%y==1)
                return "Chefirnemo";
            return "Pofik";
        }
        if(m<y+1)
        {
            if(m==1 && (n-1)%x==0)
                return "Chefirnemo";
            if(m==2 && (n-1)%x==1)
                return "Chefirnemo";
            return "Pofik";
        }
    }
    n--;
    m--;
    if(n%x==0 && m%y==0)
        return "Chefirnemo";
    if(n%x==1 && m%y==1)
        return "Chefirnemo";
    if(n%x==0 || m%y==0)
    {
        if(n%x==0 && x==1)
        {
            if(m%y==1)
                return "Chefirnemo";
            else
                return "Pofik";
        }
        if(m%y==0 && y==1)
        {
            if(n%x==1)
                return "Chefirnemo";
            else
                return "Pofik";
        }
    }
    return "Pofik";

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        cout<<fun(n,m,x,y)<<endl;
    }
    return 0;
}

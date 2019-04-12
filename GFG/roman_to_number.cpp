#include<bits/stdc++.h>
using namespace std;

int roman_int(string s)
{
    map<char,int> hmap;
    hmap['I']=1;
    hmap['V']=5;
    hmap['X']=10;
    hmap['L']=50;
    hmap['C']=100;
    hmap['D']=500;
    hmap['M']=1000;
    int i=0;
    int sum=0;
    if(s.length()<=1)
    {
        sum+=hmap[s[s.length()-1]];
        return sum;
    }
    while(i<s.length())
    {
        if(hmap[s[i]]<hmap[s[i+1]])
        {
            sum+=hmap[s[i+1]]-hmap[s[i]];
            i+=2;
        }
        else
        {
            sum+=hmap[s[i]];
            i++;
        }
    }
    return sum;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        cout<<roman_int(s)<<"\n";
    }
    return 0;
}
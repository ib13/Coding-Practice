#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str1;
    cin>>str1;
    stack<string> s1;
    string str2="if";
    string str3="endif";
    string str4="";
    for(int i=0;i<str1.length();i++)
    {
        str4+=str1[i];
        if(str1[i]=='f')
        {
            s1.push(str4);
            str4="";
        }
    }
    int i=0;
    int j=0;
    while(!s1.empty())
    {
        str4=s1.top();
        s1.pop();
        if(str4==str2)
            i++;
        if(str4==str3)
            j++;
        if(j<i)
            cout<<-1;
    }
    if(i==j)
        cout<<i;
    else
        cout<<-1;
    return 0;
}


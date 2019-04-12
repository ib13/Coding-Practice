#include <bits/stdc++.h>
using namespace std;
void reverse_str(string str)
{
    int k=0;
    stack<string> stk;
    string temp="";
    for(int i=0;i<str.length()+1;i++)
    {
        if(str[i]=='.' || i==(str.length()))
        {
            stk.push(temp);
            temp="";
            k++;
        }
        else
            temp+=str[i];
    }
    temp="";
    while(k>1)
    {
        temp=temp+stk.top()+".";
        stk.pop();
        k--;
    }
    temp+=stk.top();
    stk.pop();
    cout<<temp;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        stack<string> stk;
        cin>>str;
        string temp;
        reverse_str(str);
    }
    return 0;
}


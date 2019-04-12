#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int flag=1;
        int num=0, temp=-1, pre=-1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '.') {
                num = s[i] - '0';
                if(temp==-1){
                    temp = i;
                    pre = num;
                }
                else{
                    if(i-temp-1<pre+num){
                        cout<<"unsafe";
                        flag=0;
                        break;
                    }
                }
                temp=i;
                pre=num;
            }
        }

        if(flag==1)
        cout<<"safe";
    }
}

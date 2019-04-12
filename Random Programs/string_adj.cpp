#include <iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int max=0,freq_max=0;
	    string s;
	    cin>>s;
	    for(int j=0;j<s.length();j++)
        {
            max=0;
            for(int k=j+1;k<s.length();k++)
            {
                if(s[j]==s[k])
                    max++;
                if(max+1>freq_max)
                    freq_max=max+1;
            }
        }
        cout<<freq_max<<" ";
	}
	return 0;
}


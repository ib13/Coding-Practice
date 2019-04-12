#include <iostream>
using namespace std;
void LCS(string s1,string s2,int n1,int n2)
{
    int prev=0,len=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(s1[i]==s2[j] && prev<=j)
            {
                len++;
                break;
            }
        }
    }
    cout<<len<<"\n";
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    string s1;
	    string s2;
	    cin>>s1>>s2;
	    LCS(s1,s2,n1,n2);

	}
	return 0;
}

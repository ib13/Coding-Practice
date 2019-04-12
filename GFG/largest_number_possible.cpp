#include <iostream>
using namespace std;

void largest(int n,int s)
{
    if(n*9<s || s==0)
    {
        cout<<-1;
        return;
    }
    int num=9;
	while(n--)
    {
	    if(s>=num)
        {
	        cout<<num;
	        s-=num;
        }
        else
        {
            num--;
            n++;
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,s;
	    cin>>n>>s;
	    largest(n,s);
	    cout<<"\n";
	}
	return 0;
}
#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
	set<int> s;
	int num,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cin>>num;
	    s.insert(num);
	    set<int>:: iterator it=s.begin();
	    if(s.size()%2==0)
	    {
	        it=it+(i/2)-1;
	    }
	    else
	    {
	        it=it+(i/2);
	    }
	    cout<<*it;
	}
	return 0;
}
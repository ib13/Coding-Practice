#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,i;
	vector<int> v(5);
	v.clear();
	for(i=0;i<3;i++)
	{
		cin>>n;
		v.push_back(n);
	}
	cout<<v.capacity();
	cout<<v.size();
	cout<<v.at(2);
    cout<<v.front()<<v.back();
	vector<int>::iterator it=v.begin();   //points to starting element
	v.insert(it+1,4);
	cout<<v[1]<<endl;	
	cout<<"----------------------------------------------";
	for(i=0;i<v.size();i++)
	{
		cout<<endl<<v[i];
	}
	v.pop_back();
	for(i=0;i<v.size();i++)
	{
		cout<<endl<<v[i];
	}
	return 0;
}
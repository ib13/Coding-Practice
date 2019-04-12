#include<iostream>
#include<array>
using namespace std;

int main()
{
	array<int,5> obj;
	for(int i=0;i<5;i++)
	{
		cin>>obj[i];
	}
	for(int i=0;i<5;i++)
	{
		cout<<obj[i];
	}
	cout<<'\n'<<obj.front()<<obj.back()<<obj.size()<<'\n';
	obj.fill(2);
	for(int i=0;i<5;i++)
	{
		cout<<obj[i];
	}

	return 0;
}

#include<iostream>
using namespace std;

void count(int n)
{
	if(n<1)
		return;
	cout<<n;
	count(n-1);
}

int main()
{
	int n;
	cout<<"Enter number to which you want to count: ";
	cin>>n;
	count(n);
}
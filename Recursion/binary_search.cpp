#include<iostream>
using namespace std;

void search(int A[],int b,int e,int c)
{
	if(b>e)
	{
		cout<<"Element not found";
		return;
	}
	int mid=(b+e)/2;
	if(A[mid]==c)
	{
		cout<<"Element found at index "<<mid;
		return;
	}
	else if(A[mid]>c)
		search(A,b,mid-1,c);
	else
		search(A,mid+1,e,c);
}
int main()
{
	int n,i,c;
	cout<<"Enter number of elements in the array: ";
	cin>>n;
	int A[n];
	cout<<"Enter elements: ";
	for(i=0;i<n;i++)
		cin>>A[i];
	int b=0,e=n-1;
	cout<<"Element to be searched: ";
	cin>>c;
	search(A,b,e,c);
}
#include<iostream>
using namespace std;
int n;
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
 int partition(int A[],int begin,int end)
 {
 	int pivot=A[end];
 	int i=begin-1;
 	for(int j=begin;j<end;j++)
 	{
 		if(A[j]<=pivot)
 			swap(&A[++i],&A[j]);
 	}
 	swap(&A[++i],&A[end]);
 	for(int i=0;i<n;i++)
 		cout<<A[i];
 	cout<<"\n";
 	return i;
 }

void quicksort(int A[],int begin,int end)
{
	if(begin<end)
	{
		int pivot=partition(A,begin,end);
		quicksort(A,begin,pivot-1);
		quicksort(A,pivot+1,end);
	}
}

 int main()
 {
 	cout<<"Enter number of elements: ";
    cin>>n;
    int A[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    	cin>>A[i];
    quicksort(A, 0, n-1);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    	cout<<A[i];
    return 0;
 }
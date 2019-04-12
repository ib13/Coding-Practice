#include<iostream>
using namespace std;
int A[6];
void binary(int n)
{
	if(n<1)
		printf("%s",A);
	else
	{
		A[n-1]=5;
		binary(n-1);
		A[n-1]=3;
		binary(n-1);
	}
}
int main()
{
	binary(6);
	return 0;
}
#include<iostream>
using namespace std;
int sum=0;
 int sum_digit(int n)
 {
 	if(n<1)
 		return sum;
 	sum=sum+(n%10);
 	sum_digit(n/10);
 }
 int main()
 {
 	int n;
 	cin>>n;
 	cout<<sum_digit(n);
 	return 0;
 }
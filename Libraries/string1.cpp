#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1=string("Hello");
	string s2="World";
	string s3;
	s3="Welcome";
	char ch[10]="Everyone";
	string s4=s3+ch;
	string s5=s1+s2;
	cout<<s5<<endl<<s4;
	return 0;
}
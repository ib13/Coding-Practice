#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1="Hello";
	string s2="Hello there how are you";
	string s3;
	getline(cin,s3);
	cout<<s3;
	string s4=s1.append(s2);
	s1.replace(0,5,"Hi");
	cout<<endl<<s1<<endl<<s4;
	s1.insert(12,"goo");
	cout<<endl<<s1;
	char ch[]={'A','B','C'};
	cout<<ch;
	s4=ch;
	cout<<s4;
	return 0;
}
#include<iostream>
using namespace std;
int A[5];
int front;
int rear;
bool isfull()
{
	if(rear==4)
		return true;
}
bool isempty()
{
	if(front>rear)
		return true;
}
void enqueue(int data)
{
	if(isfull())
		return;
	A[++rear]=data;
}
void dequeue()
{
	if(isempty())
		return;
	front++;
}

void print()
{
	for(int i=0;i<=5;i++)
		cout<<A[i];
}

int main()
{
	front=0;
	rear=-1;
	enqueue(5);
	enqueue(7);
	// dequeue();
	print();
	return 0;
}
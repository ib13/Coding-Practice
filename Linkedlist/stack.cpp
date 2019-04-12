#include<iostream>
using namespace std;

struct node
{
	int data;     //data to be inserted
	node *next;   //points to next node
};
node *head;


void push(int x)
{
	node *temp=new node();    
	temp->data=x;	
	temp->next=head;   //point newly created node to 1st existing node
	head=temp;         //newy created 1st node
	cout<<"Push Successful.\n";
}

void pop()
{
	node *temp=head;
	head=head->next;
	delete temp;
	cout<<"Pop Successful.\n";
}

void print()
{
	int i=0;
	node *temp=new node();
	temp=head;                                          //to start travesing from 1st node
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
		i++;
	}	
	cout<<"\n";
}

int main()
{
	head=NULL;
	int n,i,x;

while(1)
{
	cout<<"1.Push\n2.Pop\n3.Print\n4.Exit\nEnter option: ";
	cin>>n;
	switch (n)
	{

		case 1:
		cout<<"Enter value: ";
		cin>>x;
		push(x);
		break;
		case 2:
		pop();
		break;
		case 3:
		print();
		break;
		case 4:
		exit(0);
		break;
		default:
		cout<<"Invalid Option.\n";
	}
}

	return 0;
}

#include<iostream>
using namespace std;

struct node
{
	int data;     //data to be inserted
	node *next;   //points to next node
};
node *head;

void insert(int x)
{
	node *temp=new node();    
	temp->data=x;	
	temp->next=head;   //point newly created node to 1st existing node
	head=temp;         //newy created 1st node
}

void print()
{
	int i=0;
	node *temp=new node();
	temp=head;                                          //to start travesing from 1st node
	while(temp!=NULL)
	{
		cout<<"Element at index "<<i<<" is ";
		cout<<temp->data<<"\n";
		temp=temp->next;
		i++;
	}	
}

int main()
{
	head=NULL;
	int n,i,x;
	cout<<"Enter number of elements: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter "<<i<<"th element: ";
		cin>>x;
		insert(x);
	}
	print();
	return 0;
}

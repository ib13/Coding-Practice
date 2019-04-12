#include<iostream>
using namespace std;

struct node
{
	int data;     //data to be inserted
	node *next;   //points to next node
};
node *head;

void insert(int x,int p)
{
	node *temp1=new node();
	temp1->data=x;
	temp1->next=NULL;
	node *temp2=head;
	if(p==1)
	{
		temp1->next=head;
		head=temp1;
	}
	else
	{
		for(int i=0;i<p-2;i++)
	    {
		    temp2=temp2->next;
	    }
	    temp1->next=temp2->next;
	    temp2->next=temp1;
	}
	
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
	int n,i,x,p;
	cout<<"Enter number of elements: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cout<<"Enter position to be inserted: ";
	    cin>>p;
		cout<<"Enter "<<p<<"th element: ";
		cin>>x;
		insert(x,p);
	}
	print();
	return 0;
}

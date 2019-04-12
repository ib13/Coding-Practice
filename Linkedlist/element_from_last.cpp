#include<iostream>
using namespace std;

struct node
{
	int data;     //data to be inserted
	node *next;   //points to next node
};
node *head;

void search_at_index(int index)
{
	node *temp1,*temp2;
	temp1=temp2=head;
	for(int i=0;i<index;i++)
	{
		temp1=temp1->next;
	}
	while(temp1->!=NULL)
	{
		temp1=temp1->next;
		temp2=temp2->next;
	}
	cout<<"Element at index "<<index<<" from last is "<<temp2->data;
}

void insert(int x)
{
	node *temp=new node();    
	temp->data=x;	
	temp->next=NULL;   //point newly created node to 1st existing node
//	head=temp;         //newy created 1st node
    node *temp1=head; 
    if(temp1==NULL)
    {
    	head=temp;
	}
	else
	{
	    while(temp1->next!=NULL)
	    {
		    temp1=temp1->next;		
	    }
	    temp1 ->next=temp;
		
	}

}

void print()
{
	int i=0;
	node *temp=new node();
	temp=head;                                          //to start travesing from 1st node
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}	
}

void testcase()
{
	node *temp[5]=new node();
}

int main()
{
	head=NULL;
	testcase();
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
	cout<<"\nEnter index from last to be printed: ";
	cin>>x;
	search_at_index(x);
	return 0;
}

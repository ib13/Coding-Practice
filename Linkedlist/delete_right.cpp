#include<iostream>
using namespace std;

struct node
{
	int data;     //data to be inserted
	node *next;   //points to next node
};
node *head;

void deletion()
{
	node *temp=head;
	node *temp1=head;
	while(temp->next!=NULL)
	{
		if((temp->data)<((temp->next)->data))
		{
			if(temp==head)
				head=temp->next;
			else
				temp1->next=temp->next;
		}
		temp1=temp;
		temp=temp->next;
	}
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
		cout<<"Element at index "<<i<<" is ";
		cout<<temp->data<<"\n";
		temp=temp->next;
		i++;
	}	
}

int main()
{
	head=NULL;
	int n,i,x,k;
	cout<<"Enter number of elements: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter "<<i<<"th element: ";
		cin>>x;
		insert(x);
	}
	print();
	deletion();
	cout<<endl;
	print();
	return 0;
}

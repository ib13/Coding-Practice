#include<iostream>
using namespace std;

struct node
{
	int data;     //data to be inserted
	node *next;   //points to next node
};
node *head;


void swap(int pos)
{
	node *temp1,*temp2,*temp3;
	temp1=head;
	for(int i=0;i<pos;i++)
	temp1=temp1->next;
    temp2=temp1->next;
    temp1->next=temp2->next;
    temp3=temp2->next;
    temp2->next=temp3->next;
    temp3->next=temp2;
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
	int n,i,x,index;
	cout<<"Enter number of elements: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter "<<i<<"th element: ";
		cin>>x;
		insert(x);
	}
	cout<<"Enter index after which elements are to be swapped: ";
	cin>>index;
	swap(index);
	print();
	return 0;
}

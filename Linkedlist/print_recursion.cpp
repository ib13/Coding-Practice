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

void print(node *p)
{
	if(p==NULL)	
	return;
	cout<<p->data;                      //To print forward
	print(p->next);
//	cout<<p->data;                      //To print reverse
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
	print(head);
	return 0;
}

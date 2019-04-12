#include<iostream>
using namespace std;

struct node
{
	int data;     //data to be inserted
	node *next;   //points to next node
}*head1,*head2,*head3;

void insert(int x,node **head)
{
	node *temp=new node();    
	temp->data=x;	
	temp->next=NULL;   //point newly created node to 1st existing node
//	head=temp;         //newy created 1st node
    node *temp1=*head; 
    if(temp1==NULL)
    {
    	*head=temp;
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

void print(node **head)
{
	int i=0;
	node *temp;
	temp=*head;                                       
	while(temp!=NULL)
	{
		cout<<"Element at index "<<i<<" is ";
		cout<<temp->data<<"\n";
		temp=temp->next;
		i++;
	}	
}

void merge()
{
	node *temp1=head1;
	node *temp2=head2;
	while(temp1!=NULL || temp2!=NULL)
	{
		if(temp1==NULL)
		{
			insert(temp2->data,&head3);
			temp2=temp2->next;
		}
		else if(temp2==NULL)
		{
			insert(temp1->data,&head3);
			temp1=temp1->next;
		}
		else
		{
			if((temp1->data)>(temp2->data))
			{
				insert(temp2->data,&head3);
				temp2=temp2->next;
			}
			else
			{
                insert(temp1->data,&head3);
				temp1=temp1->next;				
			}
		}
	}
}

int main()
{
	head1=head2=head3=NULL;
	int n,m,i,x;
	cout<<"Enter number of elements in 1st list: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter "<<i<<"th element: ";
		cin>>x;
		insert(x,&head1);
	}
	cout<<"Enter number of elements in 2st list: ";
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"Enter "<<i<<"th element: ";
		cin>>x;
		insert(x,&head2);
	}
	merge();
	cout<<endl;
	print(&head3);
	return 0;
}
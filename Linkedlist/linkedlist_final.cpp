#include<iostream>
using namespace std;

struct node
{
	int data;     //data to be inserted
	node *next;   //points to next node
};
node *head;
int count=1;

//---------------------------------------------------Insertion---------------------------------------------------------------//

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
		    temp2=temp2->next;                   //points to (n-1)th node
	    }
	    temp1->next=temp2->next;                 //points to next node
	    temp2->next=temp1;
	}
	count++;
	cout<<"Insertion successful.\n";	
}

//-----------------------------------------------------Deletion--------------------------------------------------------------//

void deletion(int q)
{
	node *temp1=head;
	if(temp1==NULL)
	cout<<"No element in the linkedlist.\n";                                      
	else
	{
		if(q==1)                               //for head
	    {
		    head=temp1->next;
		    delete temp1;
	    }
	    else
	    {
	        for(int i=0;i<q-2;i++)
		    {
			    temp1=temp1->next;             //points to (n-1)th node
		    }
		    node *temp2=temp1->next;           //points to nth node
		    temp1->next=temp2->next;           //points to(n+1)th node
		    delete temp2;
	    }
	    count--;
	    cout<<"Deletion successful.\n";
	}	
}

//---------------------------------------------------Reverse-----------------------------------------------------------------//

void reverse()
{
	node *current,*before,*after;
	current=head;
	before=NULL;
	if(current==NULL)
	cout<<"No element in the linkedlist.\n";
	else
	{
	    while(current!=NULL)
	    {
		    after=current->next;
		    current->next=before;
		    before=current;
		    current=after;
	    }
	    head=before;
	    cout<<"Linkedlist reversed.\n";
	}
}

//----------------------------------------------------Print------------------------------------------------------------------//

void print()
{
	int i=1;
    node *temp=head;                                        //to start travesing from 1st node
	if(temp==NULL)
	cout<<"No element in the linkedlist.\n";
	while(temp!=NULL)
	{
		cout<<"Element at position "<<i<<" is ";
		cout<<temp->data<<"\n";
		temp=temp->next;
		i++;
	}	
}

//-----------------------------------------------------Main------------------------------------------------------------------//

int main()
{
	head=NULL;
	int n,i,x,p,opt=0;
	cout<<"Enter the operation you want to perform.\n1.Insert\n2.Delete\n3.Print\n4.Reverse\n5.Exit\n";
	while(opt!=5)
	{
		cout<<"Enter option: ";
		cin>>opt;
		switch(opt)
		{
			case 1:
		    cout<<"Enter position at which data is to be inserted: ";
	        cin>>p;
	        if(p>count || p<=0)
	        cout<<"Insertion not possible.\n";
	        else
	        {
	        	cout<<"Enter "<<p<<"th element: ";
		        cin>>x;
		        insert(x,p);
			}
		    break;
		    case 2:
		    cout<<"Enter position at which data is to be deleted: ";
	        cin>>p;
	        if(p>=count || p<=0)
	        {
		        cout<<"Deletion not possible\n";
	        }
	        else
	        deletion(p);
	        break;
		    case 3:
		    print();
		    break;
		    case 4:
		    reverse();
		    break;
		    case 5:
		    exit(0);
		    break;
		    default:
		    cout<<"Enter a valid option.\n";			
		}
			
	}
	return 0;
}

#include<iostream>
using namespace std;

struct node
{
	int data;     //data to be inserted
	node *next;   //points to next node
	node *prev;   //points to previous node
}*head;


void insert_at_end(int d)
{
	node *temp=new node();
	temp->data=d;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		node *temp1=head;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
		temp->prev=temp1;
	}
	cout<<"Insertion at end successful.\n";
}


void insert_at_beginning(int d)
{
	node *temp=new node();
    temp->data=d;
    temp->next=head;
    temp->prev=NULL;
    head->prev=temp;
    head=temp;
    cout<<"Insertion at beginning successful.\n";
}

void insert_in_between(int d,int index)
{
	node *temp=new node();
	temp->data=d;
	temp->next=NULL;
	temp->prev=NULL;
	node *temp1=head;
	for(int i=0;i<index;i++)
	{
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp->prev=temp1;
	temp1->next=temp;
	temp->next->prev=temp;
	cout<<"Insertion at index "<<index<<" successful.\n";
}

void print()
{
	node *temp=head;
	cout<<"Printing from start to end: ";
	while(temp->next!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<"\nPrinting from end to start: ";
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->prev;
	}
	cout<<"\n";
}

int main()
{
	head=NULL;
	int data1,opt,index;
	cout<<"1.Insert At End\n2.Insert At Beginning\n3.Insert In Between\n4.Print\n5.Exit\n";
	while(1)
	{
		cout<<"Enter option: ";
		cin>>opt;
		switch(opt)
		{
		case 1:
	    cout<<"Enter data: ";
	    cin>>data1;
	    insert_at_end(data1);
	    break;
	    case 2:
	    cout<<"Enter data: ";
	    cin>>data1;
	    insert_at_beginning(data1);
	    break;
	    case 3:
	    cout<<"Enter index after which data is to inserted: ";
	    cin>>index;
	    cout<<"Enter data: ";
	    cin>>data1;
	    insert_in_between(data1,index);
	    break;
	    case 4:
	    print();
	    break;
	    case 5:
	    exit(0);
	    break;
		default:
		cout<<"Enter a valid option.\n";			
		}
	}
}

	


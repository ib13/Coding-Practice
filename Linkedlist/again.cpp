#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
node *head=NULL;
void push(int data)
{
	node *temp=new node();
	temp->data=data;
	temp->next=NULL;
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
	}
}

void print()
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}

int main()
{
	push(5);
	push(6);
	push(7);
	print();
}
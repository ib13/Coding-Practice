#include<iostream>
using namespace std;

struct node
{
int data;
node *next;
}*head;

void insert(int data)
{
node *temp=new node();
temp->data=data;
temp->next=head;
if(head==NULL)
{
head=temp;
temp->next=head;
}
else
{
node *temp1=new node();
temp1=head->next;
while(temp1->next!=head)
{
temp1=temp1->next;
}
temp1->next=temp;
}
}

void print()
{
int i=0;
node *temp=head;
cout<<temp->data;
temp=temp->next;
while(temp!=head)
{
cout<<temp->data;
temp=temp->next;
}
}

void deletion(int pos)
{
node *temp=head;
int i=1;
node *temp1;
if(pos==0)
{
while(temp->next!=head)
{
temp=temp->next;
}
temp1=temp->next;
head=head->next;
temp->next=temp->next->next;
}
else
{
while(i<pos)
{
temp=temp->next;
i++;
}

temp1=temp->next;
if(temp->next==head)
{
head=temp->next->next;

temp->next=head;
}
else
{
temp->next=temp->next->next;
}
}
delete temp1;
}



int main()
{
int n,i,x;
head=NULL;
cout<<"Enter number of elements: ";
cin>>n;
for(i=0;i<n;i++)
{
cin>>x;
insert(x);
}
print();
cout<<"Enter index to be deleted: ";
cin>>x;
deletion(x);
cout<<endl;
print();
return 0;
}
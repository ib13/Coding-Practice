#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int data;
    node *next;
};
node *head;

void insert(int x)
{
    node *temp=new node();
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        node *temp2=head;
        while(temp2->next!=NULL)
            temp2=temp2->next;
        temp2->next=temp;
    }
}

void reverse(node *ptr)
{
    node *temp1=ptr->next;
    node *temp2=ptr->next->next;
    node *temp3=NULL;
    while(temp2!=NULL)
    {
        temp1->next=temp3;
        temp3=temp1;
        temp1=temp2;
        temp2=temp2->next;
    }
    temp1->next=temp3;
    ptr->next=temp1;
}

void spiral()
{
    node *fp=head;
    node *sp=head;
    while(fp->next!=NULL && fp->next->next!=NULL)
    {
        fp=fp->next->next;
        sp=sp->next;
    }
    node *temp1=sp;
    reverse(sp);
    temp1=temp1->next;
    node *temp2=head;
    node *temp3=head->next;
    node *temp4=temp1->next;
    while(temp1!=NULL)
    {
        temp2->next=temp1;
        temp2=temp3;
        temp3=temp3->next;
        if(temp1->next!=NULL)
        {
            temp1->next=temp2;
            temp1=temp4;
            temp4=temp4->next;
        }
        else
        {
            if(n%2==0)
            {
                temp1->next=NULL;
                temp1=temp4;
            }

            else
            {
                temp1->next=temp2;
                temp1=temp4;
                temp2->next=NULL;
            }


        }

    }

}

void print()
{
    int i=0;
    node *temp=head;
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
    cin>>n;
    int num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        insert(num);
    }
    spiral();
    print();

}
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("");
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	(struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
struct node* findIntersection(struct node* head1, struct node* head2);
int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(findIntersection(a, b));
    }
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node* findIntersection(struct node* head1, struct node* head2)
{
    multiset<int> s;
    node* t1=head2;
    map<node*,int> m1;
    while(head1!=NULL)
    {
        t1=head2;
        while(t1!=NULL)
        {
            if(head1->data==t1->data && m1[t1]==0)
            {
                s.insert(t1->data);
                m1[t1]=1;
                break;
            }

            t1=t1->next;
        }
        head1=head1->next;
    }
    node *head3=NULL;
    for(auto it=s.begin();it!=s.end();it++)
    {
//        cout<<*it<<" ";
        node *temp1=new node();
        node*temp2;
        temp1->data=*it;
        temp1->next=NULL;
        if(head3==NULL)
        {
            head3=temp1;
            temp2=head3;
        }
        else
        {
            temp2->next=temp1;
            temp2=temp2->next;
        }

    }
//    cout<<endl;
    return head3;
}


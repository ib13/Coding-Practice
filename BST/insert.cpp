#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *root=NULL;
node* insert(node *root,int data)
{
	if(root==NULL)
	{
		node *temp=new node();
		temp->data=data;
	    temp->left=temp->right=NULL;	
	    root=temp;
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

void search(node *root,int data)
{
	if(root==NULL)
	{
		cout<<"Data not found.";
	}
	else if(data==root->data)
	{
		cout<<"Data found.";
	}
	else if(data<=root->data)
	{
		search(root->left,data);
	}
	else
	{
		search(root->right,data);
	}
}

int main()
{
	int n,num;
	cout<<"Enter n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		root=insert(root,num);
	}
	cout<<"Values inserted.";
	int s;
	cout<<"\nelement to be searched: ";
	cin>>s;
	search(root,s);
	return 0;
}
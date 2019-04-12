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

int findmin(node *root)
{
	if(root->left==NULL)
		return root->data;
	return findmin(root->left);
}
int findmax(node *root)
{
	if(root->right==NULL)
		return root->data;
	return findmax(root->right);
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
	cout<<"Min value is: "<<findmin(root);
	cout<<"\nMax value is: "<<findmax(root);
	return 0;
}
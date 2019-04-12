#include<iostream>
#include<algorithm>
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

int findheight(node *root)
{
	if(root==NULL)
		return -1;
	int left_height=findheight(root->left);
	int right_height=findheight(root->right);
	return max(left_height,right_height)+1;
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
	cout<<findheight(root);
	return 0;
}
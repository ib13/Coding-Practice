#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(int data, Node *root)
{
    if (root == NULL)
    {
        Node *newNode = new Node(data);
        return newNode;
    }
    else if (data < root->data)
    {
        root->left = insert(data, root->left);
    }
    else
    {
        root->right = insert(data, root->right);
    }
    return root;
}

int findMaxDist(int val, Node *root)
{
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    while (n--)
    {
        int data;
        cin >> data;
        root = insert(data, root);
    }
    inOrderTraversal(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << height(root);
    return 0;
}
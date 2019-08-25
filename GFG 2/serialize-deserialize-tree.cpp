#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void serialize(Node *root, vector<int> &);
Node *deSerialize(vector<int> &);
/* Computes the number of nodes in a tree. */
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        map<int, Node *> m;
        int n;
        scanf("%d", &n);
        int N = n;
        struct Node *root = NULL;
        struct Node *child;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = newNode(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = newNode(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        vector<int> A;
        A.clear();
        serialize(root, A);
        //  for(int i=0;i<A.size();i++)
        //    cout<<A[i]<<" ";
        //  cout<<endl;
        // inorder(root);
        //cout<<endl;
        Node *tree_made = deSerialize(A);
        inorder(tree_made);
        cout << endl;
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*this  function serializes 
the binary tree and stores 
it in the vector A*/
void serialize(Node *root, vector<int> &A)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int qsize = q.size();
        while (qsize--)
        {
            A.push_back(q.front()->data);
            Node *tempNode = q.front();
            q.pop();
            if (tempNode->left)
                q.push(tempNode->left);
            if (tempNode->right)
                q.push(tempNode->right);
        }
    }
}
/*this function deserializes
 the serialized vector A*/
Node *deSerialize(vector<int> &A)
{
}
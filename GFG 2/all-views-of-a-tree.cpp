#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// A wrapper over leftViewUtil()
void leftView(struct Node *root);
void rightView(struct Node *root);
void topView(struct Node *root);
void bottomView(struct Node *root);
/* Driver program to test size function*/
int main()
{
    int t;
    struct Node *child;
    scanf("%d", &t);
    while (t--)
    {
        map<int, Node *> m;
        int n;
        scanf("%d", &n);
        struct Node *root = NULL;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        cout << "Left View: ";
        leftView(root);
        cout << endl;
        cout << "Right View: ";
        rightView(root);
        cout << endl;
        cout << "Top View: ";
        topView(root);
        cout << endl;
        cout << "Bottom View: ";
        bottomView(root);
        cout << endl;
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// A wrapper over leftViewUtil()
void leftView(Node *root)
{
    queue<Node *> q;
    vector<Node *> view;
    q.push(root);
    while (!q.empty())
    {
        int qsize = q.size();
        view.push_back(q.front());
        while (qsize--)
        {
            Node *tempNode = q.front();
            q.pop();
            if (tempNode->left)
                q.push(tempNode->left);
            if (tempNode->right)
                q.push(tempNode->right);
        }
    }
    for (int i = 0; i < view.size(); i++)
    {
        cout << view[i]->data << " ";
    }
}

void rightView(Node *root)
{
    queue<Node *> q;
    vector<Node *> view;
    q.push(root);
    while (!q.empty())
    {
        int qsize = q.size();
        while (qsize--)
        {
            Node *tempNode = q.front();
            q.pop();
            if (qsize == 0)
                view.push_back(tempNode);
            if (tempNode->left)
                q.push(tempNode->left);
            if (tempNode->right)
                q.push(tempNode->right);
        }
    }
    for (int i = 0; i < view.size(); i++)
    {
        cout << view[i]->data << " ";
    }
}

void top_bottomViewHelper(Node *root, map<int, vector<Node *>> &m, int index)
{
    if (root == NULL)
        return;
    m[index].push_back(root);
    top_bottomViewHelper(root->left, m, index - 1);
    top_bottomViewHelper(root->right, m, index + 1);
}

void topView(Node *root)
{
    map<int, vector<Node *>> m;
    top_bottomViewHelper(root, m, 0);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second[0]->data << " ";
    }
}

void bottomView(Node *root)
{
    map<int, vector<Node *>> m;
    top_bottomViewHelper(root, m, 0);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second[it->second.size() - 1]->data << " ";
    }
}
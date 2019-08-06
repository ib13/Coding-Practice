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
void verticalOrder(Node *root);
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
        verticalOrder(root);
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
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
void VerticalOrderHelper1(Node *root, map<int, vector<Node *>> &m, int index)
{
    if (root == NULL)
        return;
    m[index].push_back(root);
    VerticalOrderHelper1(root->left, m, index - 1);
    VerticalOrderHelper1(root->right, m, index + 1);
}

void VerticalOrderHelper2(Node *root, map<int, vector<Node *>> &m)
{
    queue<pair<Node *, int>> q;
    int hd = 0;
    pair<Node *, int> p;
    p.first = root;
    p.second = hd;
    q.push(p);
    while (!q.empty())
    {
        Node *temp = q.front().first;
        hd = q.front().second;
        q.pop();
        m[hd].push_back(temp);
        if (temp->left != NULL)
            q.push(make_pair(temp->left, hd - 1));
        if (temp->right != NULL)
            q.push(make_pair(temp->right, hd + 1));
    }
}

void verticalOrder(Node *root)
{
    map<int, vector<Node *>> m;
    // VerticalOrderHelper1(root, m, 0);
    VerticalOrderHelper2(root, m);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << it->second[i]->data << " ";
        }
    }
}
// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
// Unsolved
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
int getLevelDiff(Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)
        malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
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
        cout << getLevelDiff(root);
        cout << endl;
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*You are required to complete this function*/
int getLevelDiff(Node *root)
{
    Node *temp;
    queue<Node *> q;
    if (root == NULL)
        return 0;
    q.push(root);
    int level = 0;
    int level_diff = 0;
    while (!q.empty())
    {
        int q_size = q.size();
        while (q_size > 0)
        {
            temp = q.front();
            q.pop();
            if (!temp->left)
            {
                q.push(temp->left);
            }
            else if (!temp->right)
            {
                q.push(temp->right);
            }
            if (level % 2)
            {
                level_diff -= temp->data;
            }
            else
                level_diff += temp->data;
        }
        level++;
    }
    return level_diff;
}

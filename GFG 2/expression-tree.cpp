#include <bits/stdc++.h>
using namespace std;
struct node
{
    string data;
    node *left;
    node *right;
};
int evalTree(node *);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        int p = 0;
        node *root = new node;
        root->data = s[p];
        root->left = NULL;
        root->right = NULL;
        queue<node *> q;
        q.push(root);
        p = 1;
        while (!q.empty())
        {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (p != n)
            {
                l = new node;
                l->data = s[p];
                f->left = l;
                p++;
                q.push(l);
            }
            else
            {
                f->left = NULL;
            }
            if (p != n)
            {
                r = new node;
                r->data = s[p];
                f->right = r;
                p++;
                q.push(r);
            }
            else
            {
                f->right = NULL;
            }
        }
        cout << evalTree(root) << endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*The structure of node is as follows
struct node{
	string data;
	node *left;
	node *right;
};
*/
/*You are required to complete below method */
int evalTree(node *root)
{
    if (root == NULL)
        return 0;
    int val = INT_MAX;
    if (root->data == "+")
        val = evalTree(root->left) + evalTree(root->right);
    else if (root->data == "-")
        val = evalTree(root->left) - evalTree(root->right);
    else if (root->data == "*")
        val = evalTree(root->left) * evalTree(root->right);
    else if (root->data == "/")
        val = evalTree(root->left) / evalTree(root->right);
    if (val == INT_MAX)
        val = stoi(root->data);
    root->data = to_string(val);
    return val;
}
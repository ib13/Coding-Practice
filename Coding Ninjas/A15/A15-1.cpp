#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

#include <queue>

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        cout << temp->data << ":";
        int childsize = temp->children.size();
        for (int i = 0; i < childsize - 1; i++)
        {
            cout << temp->children[i]->data << ",";
            q.push(temp->children[i]);
        }
        if (childsize != 0)
        {
            cout << temp->children[childsize - 1]->data;
            q.push(temp->children[childsize - 1]);
        }
        cout << endl;
    }
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
}

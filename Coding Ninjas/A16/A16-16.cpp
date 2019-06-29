#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

void printSpecificPattern(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    vector<BinaryTreeNode<int> *> v;
    q.push(root);
    while (!q.empty())
    {
        int qsize = q.size();
        v.clear();
        for (int i = 0; i < qsize; i++)
        {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
            v.push_back(temp);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        int start = 0;
        int end = qsize - 1;
        while (start < end)
        {
            cout << v[start]->data << " " << v[end]->data << " ";
            start++;
            end--;
        }
        if (start == end)
            cout << v[start]->data << " ";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

BinaryTreeNode<int> *takeinputlevelwise()
{

    queue<BinaryTreeNode<int> *> pendingnodes;
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);

    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {

        BinaryTreeNode<int> *frontnode = pendingnodes.front();
        BinaryTreeNode<int> *currentnode = frontnode;
        pendingnodes.pop();

        int lchild;
        cin >> lchild;

        if (lchild != -1)
        {
            BinaryTreeNode<int> *leftchild = new BinaryTreeNode<int>(lchild);
            pendingnodes.push(leftchild);
            currentnode->left = leftchild;
        }

        int rchild;
        cin >> rchild;

        if (rchild != -1)
        {
            BinaryTreeNode<int> *rightchild = new BinaryTreeNode<int>(rchild);
            pendingnodes.push(rightchild);
            currentnode->right = rightchild;
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = NULL;
    root = takeinputlevelwise();
    printSpecificPattern(root);
}

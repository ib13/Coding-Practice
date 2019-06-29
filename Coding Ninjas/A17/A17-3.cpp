#include <iostream>
#include <queue>

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
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
#include <limits.h>
using namespace std;

// Approach 1
// int getMax(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return INT_MIN;
//     return max(root->data, max(getMax(root->left), getMax(root->right)));
// }

// int getMin(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return INT_MAX;
//     return min(root->data, min(getMin(root->left), getMin(root->right)));
// }

// bool isBST(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return true;
//     if (root->data > getMax(root->left) && root->data < getMin(root->right) && isBST(root->left) && isBST(root->right))
//         return true;
//     else
//         return false;
// }

//Approach 2
bool isBSTHelper(BinaryTreeNode<int> *root, int minval, int maxval)
{
    if (root == NULL)
        return true;
    if (maxval < root->data && minval > root->data && isBSTHelper(root->left, minval, max(maxval, root->data)) && isBSTHelper(root->right, min(minval, root->data), maxval))
        return true;
    return false;
}

bool isBST(BinaryTreeNode<int> *root)
{
    return isBSTHelper(root, INT_MAX, INT_MIN);
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    if (isBST(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    delete root;
}

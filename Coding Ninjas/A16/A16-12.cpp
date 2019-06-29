#include <iostream>
#include <vector>
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
};

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int hleft, hright;
    hleft = height(root->left);
    hright = height(root->right);
    return 1 + max(hleft, hright);
}

void longestPathHelper(BinaryTreeNode<int> *root, vector<int> *temp, vector<int> *final, int h)
{
    if (root == NULL)
    {
        if (temp->size() == h)
            *final = *temp;
        return;
    }
    temp->push_back(root->data);
    longestPathHelper(root->left, temp, final, h);
    longestPathHelper(root->right, temp, final, h);
    temp->pop_back();
}

vector<int> *longestPath(BinaryTreeNode<int> *root)
{
    vector<int> *temp = new vector<int>;
    vector<int> *final = new vector<int>;
    int h = height(root);
    longestPathHelper(root, temp, final, h);
    return final;
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
    vector<int> *output = longestPath(root);
    vector<int>::iterator i = output->begin();
    while (i != output->end())
    {
        cout << *i << endl;
        i++;
    }
}

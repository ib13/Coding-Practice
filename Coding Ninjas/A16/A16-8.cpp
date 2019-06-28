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
};

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
BinaryTreeNode<int> *buildTreeHelper(int *postorder, int *inorder, int inStart, int inEnd, int postStart, int postEnd)
{
    if (inEnd - inStart < 0)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postEnd]);
    // For left
    int LinS = 0, LinE = 0, LpostS = 0, LpostE = 0;
    int rootdata = postorder[postEnd];
    cout << rootdata << endl;
    LinS = inStart;
    while (inorder[LinE] != rootdata)
        LinE++;
    LinE--;
    LpostS = LinS;
    LpostE = LinE;
    root->left = buildTreeHelper(postorder, inorder, LinS, LinE, LpostS, LpostE);

    // For right
    int RinS = 0, RinE = 0, RpostS = 0, RpostE = 0;
    RinS = LinE + 2;
    RinE = inEnd;
    RpostS = LpostE + 1;
    RpostE = postEnd - 1;
    root->right = buildTreeHelper(postorder, inorder, RinS, RinE, RpostS, RpostE);
    return root;
}

BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength)
{
    return buildTreeHelper(postorder, inorder, 0, inLength - 1, 0, postLength - 1);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
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

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> post[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelATNewLine(root);
}

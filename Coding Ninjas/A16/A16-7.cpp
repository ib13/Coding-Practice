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
BinaryTreeNode<int> *buildTreeHelper(int *preorder, int *inorder, int inStart, int inEnd, int preStart, int preEnd)
{
    if (inEnd - inStart < 0)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[preStart]);
    // For left
    int LinS = 0, LinE = 0, LpreS = 0, LpreE = 0;
    int rootdata = preorder[preStart];
    LinS = inStart;
    int rootindex = -1;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == rootdata)
        {
            rootindex = i;
            break;
        }
    }
    // while (inorder[LinE] != rootdata)
    //     LinE++;
    // LinE--;
    LinE = rootindex - 1;
    LpreS = preStart + 1;
    LpreE = LpreS + LinE - LinS;
    root->left = buildTreeHelper(preorder, inorder, LinS, LinE, LpreS, LpreE);

    // For right
    int RinS = 0, RinE = 0, RpreS = 0, RpreE = 0;
    RinS = rootindex + 1;
    RinE = inEnd;
    RpreS = LpreE + 1;
    RpreE = preEnd;
    root->right = buildTreeHelper(preorder, inorder, RinS, RinE, RpreS, RpreE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLenght, int *inorder, int inLength)
{
    return buildTreeHelper(preorder, inorder, 0, inLength - 1, 0, preLenght - 1);
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
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> pre[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}

#include <iostream>
#include <queue>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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
void insertToLL(int data, Node<int> *&head, Node<int> *&tail)
{
    Node<int> *newNode = new Node<int>(data);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}

void BSTToLL(BinaryTreeNode<int> *root, Node<int> *&head, Node<int> *&tail)
{
    if (root == NULL)
        return;
    BSTToLL(root->left, head, tail);
    insertToLL(root->data, head, tail);
    BSTToLL(root->right, head, tail);
}

Node<int> *constructBST(BinaryTreeNode<int> *root)
{
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    BSTToLL(root, head, tail);
    return head;
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
    Node<int> *head = constructBST(root);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

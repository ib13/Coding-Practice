#include <iostream>
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
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
    BinaryTreeNode<int> *root;

    bool hasDataHelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return false;
        if (root->data == data)
            return true;
        return (hasDataHelper(data, root->left) || hasDataHelper(data, root->right));
    }

    BinaryTreeNode<int> *insertHelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *newBSTNode = new BinaryTreeNode<int>(data);
            return newBSTNode;
        }

        if (data < root->data)
            root->left = insertHelper(data, root->left);
        else
            root->right = insertHelper(data, root->right);
        return root;
    }

    BinaryTreeNode<int> *deleteDataHelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return root;
        if (data < root->data)
            root->left = deleteDataHelper(data, root->left);
        else if (data > root->data)
            root->right = deleteDataHelper(data, root->right);
        else
        {
            // 0 children
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // 1 children
            else if (root->left == NULL || root->right == NULL)
            {
                if (root->left)
                {
                    BinaryTreeNode<int> *temp = root->left;
                    delete root;
                    return temp;
                }
                else if (root->right)
                {
                    BinaryTreeNode<int> *temp = root->right;
                    delete root;
                    return temp;
                }
            }
            // 2 children
            else
            {
                BinaryTreeNode<int> *rightMin = root->right;
                while (rightMin->left != NULL)
                    rightMin = rightMin->left;
                BinaryTreeNode<int> *temp = root;
                root->data = rightMin->data;
                root->right = deleteDataHelper(root->data, root->right);
                return root;
            }
        }
        return root;
    }

    void printTreeHelper(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << ":";
        if (root->left)
        {
            cout << "L:" << root->left->data << ",";
            // if (root->right)
            // cout << ",";
        }
        if (root->right)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTreeHelper(root->left);
        printTreeHelper(root->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    bool hasData(int data)
    {
        return hasDataHelper(data, root);
    }

    void insert(int data)
    {
        root = insertHelper(data, root);
    }

    void deleteData(int data)
    {
        root = deleteDataHelper(data, root);
    }

    void printTree()
    {
        printTreeHelper(root);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->deleteData(input);
            break;
        case 3:
            cin >> input;
            if (tree->hasData(input))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
            break;
        default:
            tree->printTree();
            return 0;
            break;
        }
    }
}

#include <iostream>
using namespace std;
class BTree
{
public:
    int data;
    BTree *left;
    BTree *right;

    BTree(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BTree *takeInput()
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    if (data == -1)
        return NULL;
    BTree *newNode = new BTree(data);
    cout << "Enter left of " << data << " : ";
    newNode->left = takeInput();
    cout << "Enter right of " << data << " : ";
    newNode->right = takeInput();
    return newNode;
}

void printTree(BTree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " :";
    if (root->left)
        cout << " L" << root->left->data;
    if (root->right)
        cout << " R" << root->right->data;
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    BTree *root;
    root = takeInput();
    printTree(root);
}
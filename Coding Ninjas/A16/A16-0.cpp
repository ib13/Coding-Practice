#include <iostream>
#include <queue>
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

int height(BTree *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BTree *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(lh + rh, max(ld, rd));
}

pair<int, int> diameter1(BTree *root)
{ //first height, second diameter
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = diameter1(root->left);
    pair<int, int> rightAns = diameter1(root->right);
    pair<int, int> p;
    int lh = leftAns.first;
    int rh = rightAns.first;
    int ld = leftAns.second;
    int rd = rightAns.second;
    p.first = 1 + max(lh, rh);
    p.second = max(max(ld, rd), lh + rh);
    return p;
}

BTree *takeInputLevel()
{
    int data;
    cout << "Enter root data: ";
    cin >> data;
    if (data == -1)
        return NULL;
    queue<BTree *> q;
    BTree *root = new BTree(data);
    q.push(root);
    while (!q.empty())
    {
        BTree *temp = q.front();
        q.pop();
        cout << "Enter left data for node " << temp->data << " : ";
        cin >> data;
        if (data != -1)
        {
            BTree *newNode = new BTree(data);
            temp->left = newNode;
            q.push(newNode);
        }
        cout << "Enter right data for node " << temp->data << " : ";
        cin >> data;
        if (data != -1)
        {
            BTree *newNode = new BTree(data);
            temp->right = newNode;
            q.push(newNode);
        }
    }
    return root;
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
    // root = takeInput();
    root = takeInputLevel();
    printTree(root);
    cout << diameter1(root).first << " " << diameter1(root).second;
}

// 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1
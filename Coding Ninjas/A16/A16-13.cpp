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
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// #include <unordered_map>
// #include <vector>
// #include <queue>
// #include <algorithm>
// pair<vector<BinaryTreeNode<int> *>, vector<BinaryTreeNode<int> *>> leftRightBoundary(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, bool> &m)
// {
//     vector<BinaryTreeNode<int> *> leftB;
//     vector<BinaryTreeNode<int> *> rightB;
//     queue<BinaryTreeNode<int> *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         int qsize = q.size();
//         if (!m[q.front()])
//         {
//             leftB.push_back(q.front());
//             m[q.front()] = 1;
//         }
//         for (int i = 0; i < qsize; i++)
//         {
//             if (i == (qsize - 1))
//             {
//                 if (!m[q.front()])
//                 {
//                     rightB.push_back(q.front());
//                     m[q.front()] = 1;
//                 }
//             }
//             BinaryTreeNode<int> *temp = q.front();
//             q.pop();
//             if (temp->left)
//                 q.push(temp->left);
//             if (temp->right)
//                 q.push(temp->right);
//         }
//     }
//     reverse(rightB.begin(), rightB.end());
//     pair<vector<BinaryTreeNode<int> *>, vector<BinaryTreeNode<int> *>> p;
//     p.first = leftB;
//     p.second = rightB;
//     return p;
// }

// void leafBoundary(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, bool> &m, vector<BinaryTreeNode<int> *> &v)
// {
//     if (root == NULL)
//         return;
//     leafBoundary(root->left, m, v);
//     if (!root->left && !root->right)
//     {
//         if (!m[root])
//         {
//             v.push_back(root);
//             m[root] = 1;
//         }
//     }
//     leafBoundary(root->right, m, v);
// }

// void solve(BinaryTreeNode<int> *root)
// {
//     unordered_map<BinaryTreeNode<int> *, bool> m;
//     vector<BinaryTreeNode<int> *> leafB;
//     leafBoundary(root, m, leafB);
//     pair<vector<BinaryTreeNode<int> *>, vector<BinaryTreeNode<int> *>> p = leftRightBoundary(root, m);
//     vector<BinaryTreeNode<int> *> leftB = p.first;
//     vector<BinaryTreeNode<int> *> rightB = p.second;

//     vector<BinaryTreeNode<int> *> finalvector;
//     for (int i = 0; i < leftB.size(); i++)
//         finalvector.push_back(leftB[i]);
//     for (int i = 0; i < leafB.size(); i++)
//         finalvector.push_back(leafB[i]);
//     for (int i = 0; i < rightB.size(); i++)
//         finalvector.push_back(rightB[i]);
//     for (int i = 0; i < finalvector.size(); i++)
//         cout << finalvector[i]->data << " ";
// }
void printLeftBoundary(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        cout << root->data << " ";
        printLeftBoundary(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        printLeftBoundary(root->right);
    }
}

void printLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    printLeafNodes(root->left);

    if (!root->left && !root->right)
        cout << root->data << " ";

    printLeafNodes(root->right);
}

void printRightBoundary(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    if (root->right)
    {
        printRightBoundary(root->right);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        printRightBoundary(root->left);
        cout << root->data << " ";
    }
}

void solve(BinaryTreeNode<int> *root)
{
    cout << root->data << " ";
    printLeftBoundary(root->left);
    printLeafNodes(root->left);
    printLeafNodes(root->right);
    printRightBoundary(root->right);
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
    solve(root);
}

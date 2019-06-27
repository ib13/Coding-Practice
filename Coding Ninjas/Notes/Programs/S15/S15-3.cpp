#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class treeNode
{
public:
    T data;
    vector<treeNode<T> *> child;

    treeNode(T data)
    {
        this->data = data;
    }
};

int main()
{
    treeNode<int> *root = new treeNode<int>(10);
    treeNode<int> *node1 = new treeNode<int>(10);
    treeNode<int> *node2 = new treeNode<int>(10);
    root->child.push_back(node1);
    root->child.push_back(node2);
    return 0;
    /*

         root
        /   \
    node1   node2

     */
}
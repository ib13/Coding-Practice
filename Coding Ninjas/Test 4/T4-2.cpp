//Implement code to swap two elements of a Linked List. You need to swap the Nodes not the data
#include <iostream>
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
using namespace std;
#include <unordered_map>
void changeLL(Node<int> *head)
{
    Node<int> *temp = head;
    int maxval = 0;
    while (temp != NULL)
    {
        maxval = max(maxval, temp->data);
        temp = temp->next;
    }
    maxval++;
    unordered_map<int, bool> m;
    temp = head;
    while (temp != NULL)
    {
        if (m[temp->data])
        {
            temp->data = maxval++;
        }
        else
        {
            m[temp->data] = 1;
        }
        temp = temp->next;
    }
}

Node<int> *takeinput()
{
    int data;
    cin >> data;
    Node<int> *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node<int> *newNode = new Node<int>(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node<int> *head = takeinput();
    changeLL(head);
    print(head);
    return 0;
}

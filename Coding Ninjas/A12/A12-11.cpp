//Write a function AlternatingSplit() that takes one list and divides up its nodes to make two smaller lists a and b.
//The sublists should be made from alternating elements in the original list.
//nodes should be in the reverse order of which they occurred in the source list
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        //(*this).data = data;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

void AlternatingSplit(Node<int> *head)
{
    Node<int> *newhead1 = NULL;
    Node<int> *newhead2 = NULL;
    Node<int> *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        Node<int> *newnode = new Node<int>(temp->data);
        if ((index++) % 2 == 0)
        {
            newnode->next = newhead1;
            newhead1 = newnode;
        }
        else
        {
            newnode->next = newhead2;
            newhead2 = newnode;
        }
        temp = temp->next;
    }

    while (newhead1 != NULL)
    {
        cout << newhead1->data << " ";
        newhead1 = newhead1->next;
    }
    cout << endl;
    while (newhead2 != NULL)
    {
        cout << newhead2->data << " ";
        newhead2 = newhead2->next;
    }
}

Node<int> *takeLLInput()
{
    int data;
    cin >> data;
    Node<int> *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node<int> *newnode = new Node<int>(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void printLL(Node<int> *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node<int> *head = takeLLInput();

    AlternatingSplit(head);
}

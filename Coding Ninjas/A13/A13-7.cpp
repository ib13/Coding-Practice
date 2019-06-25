#include <iostream>
#include <cmath>
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

int decimal(Node<int> *head)
{
    int decimalnum = 0;
    Node<int> *t1 = head;
    int length = 0;
    while (t1 != NULL)
    {
        t1 = t1->next;
        length++;
    }
    t1 = head;
    while (t1 != NULL)
    {
        decimalnum += ((t1->data) * (pow(2, length - 1)));
        t1 = t1->next;
        length--;
    }
    return decimalnum;
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

    Node<int> *head1 = takeLLInput();

    cout << decimal(head1) << endl;

    delete head1;
}

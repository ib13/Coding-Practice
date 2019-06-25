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

Node<int> *func(Node<int> *head, int n)
{
    Node<int> *t1 = head;
    Node<int> *t2 = head;
    Node<int> *tail = head;
    Node<int> *t4 = head;
    while (t1->next != NULL)
        t1 = t1->next;
    tail = t1;
    t1 = NULL;
    Node<int> *t3 = tail;
    while (t2 != tail)
    {
        if (t2->data == n)
        {
            if (t2 == head)
            {
                head = t2->next;
                t3->next = t2;
                t3 = t3->next;
                t2->next = NULL;
                t2 = head;
            }
            else
            {
                t4 = t2->next;
                t3->next = t2;
                t3 = t3->next;
                t2->next = NULL;
                t1->next = t4;
                t2 = t4;
            }
        }
        else
        {
            t1 = t2;
            t2 = t2->next;
        }
    }
    return head;
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
    int n;
    cin >> n;
    printLL(func(head1, n));
    delete head1;
}

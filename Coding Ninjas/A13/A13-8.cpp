#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (next)
            delete next;
    }
};

Node *swapEveryPair(Node *head)
{
    Node *t1 = head;
    Node *t2 = head->next;
    Node *t3;
    while (t1 != NULL && t1->next != NULL)
    {
        if (t1 == head)
        {
            head = t2;
            t1->next = t2->next;
            t2->next = t1;
        }
        else
        {
            t3->next = t2;
            t1->next = t2->next;
            t2->next = t1;
        }
        t3 = t1;
        t1 = t1->next;
        if (t1 != NULL)
            t2 = t1->next;
    }
    return head;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = takeinput();
    head = swapEveryPair(head);
    print(head);
    delete head;
    return 0;
}

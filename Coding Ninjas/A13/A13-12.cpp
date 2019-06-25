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
};

Node *rev_linkedlist_itr(Node *head)
{
    Node *t1 = head;
    Node *t2 = NULL;
    Node *t3;
    while (t1 != NULL)
    {
        t3 = t1->next;
        t1->next = t2;
        t2 = t1;
        t1 = t3;
    }
    head = t2;
    return head;
}

Node *NextLargeNumber(Node *head)
{
    head = rev_linkedlist_itr(head);
    Node *t1 = head;
    while (t1->next != NULL)
    {
        if (t1->data == 9)
            t1->data = 0;
        else
        {
            t1->data++;
            break;
        }
        t1 = t1->next;
    }
    if (t1->next == NULL)
    {
        if (t1->data == 9)
        {
            t1->data = 0;
            Node *newnode = new Node(1);
            t1->next = newnode;
        }
        else
        {
            t1->data++;
        }
    }
    head = rev_linkedlist_itr(head);
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

    head = NextLargeNumber(head);
    print(head);
    return 0;
}

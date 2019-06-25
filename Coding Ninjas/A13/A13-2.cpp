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

Node *mergeTwoLLs(Node *head1, Node *head2)
{
    Node *t1 = head1;
    Node *prev1 = NULL;
    Node *t2 = head2;
    Node *prev2 = NULL;
    while (t1 != NULL && t2 != NULL)
    {
        if (t2->data < t1->data)
        {
            if (t1 == head1)
            {
                prev2 = t2;
                t2 = t2->next;
                prev2->next = head1;
                head1 = prev2;
                prev1 = head1;
            }
            else
            {
                prev2 = t2;
                t2 = t2->next;
                prev1->next = prev2;
                prev2->next = t1;
                prev1 = prev2;
            }
        }
        else
        {
            prev1 = t1;
            t1 = t1->next;
        }
    }
    if (t1 == NULL && t2 != NULL)
        prev1->next = t2;
    return head1;
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
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}

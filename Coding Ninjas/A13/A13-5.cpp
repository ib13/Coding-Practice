// Reverse Linked List  a. Using recursion  b. Without using recursion
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *rev_linkedlist_itr(node *head)
{
    node *t1 = head;
    node *t2 = NULL;
    node *t3;
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

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
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
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = takeinput();
    head = rev_linkedlist_itr(head);
    print(head);
    return 0;
}

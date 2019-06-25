//Find midpoint of a Linked List
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

node *midpoint_linkedlist(node *head)
{
    node *t1 = head;
    node *t2 = head;
    while (t2->next != NULL && t2->next->next != NULL)
    {
        t2 = t2->next->next;
        t1 = t1->next;
    }
    return t1;
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
    node *mid = midpoint_linkedlist(head);
    cout << mid->data;
    return 0;
}

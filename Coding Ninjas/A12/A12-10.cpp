//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
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

// Takes O(n) auxillary space
node *arrange_LinkedList(node *head)
{
    node *t1 = head;
    node *newhead = NULL;
    node *newtail = NULL;
    while (t1 != NULL)
    {
        if (t1->data % 2 == 1)
        {
            node *tempnode = new node(t1->data);
            if (newhead == NULL)
            {
                newhead = tempnode;
                newtail = newhead;
            }
            else
            {
                newtail->next = tempnode;
                newtail = newtail->next;
            }
        }
        t1 = t1->next;
    }
    t1 = head;
    while (t1 != NULL)
    {
        if (t1->data % 2 == 0)
        {
            node *tempnode = new node(t1->data);
            if (newhead == NULL)
            {
                newhead = tempnode;
                newtail = newhead;
            }
            else
            {
                newtail->next = tempnode;
                newtail = newtail->next;
            }
        }
        t1 = t1->next;
    }
    return newhead;
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
    head = arrange_LinkedList(head);
    print(head);
    return 0;
}

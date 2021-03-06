//Implement code to swap two elements of a Linked List. You need to swap the nodes not the data
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

node *swap_nodes(node *head, int i, int j)
{
    int minval = min(i, j);
    int maxval = max(i, j);
    node *temp1 = head;
    node *temp2 = head;
    node *temp3 = head;
    node *temp4 = head;
    if (minval == 0)
    {
        while ((maxval - 1) != 0)
        {
            temp1 = temp1->next;
            maxval--;
        }
        temp4 = head;
        temp3 = temp1->next;
        temp1->next = temp4;
        temp1 = temp3->next;
        temp3->next = temp4->next;
        temp4->next = temp1;
        head = temp3;
    }
    else
    {
        while ((maxval - 1) != 0)
        {
            temp1 = temp1->next;
            maxval--;
        }
        while ((minval - 1) != 0)
        {
            temp2 = temp2->next;
            minval--;
        }
        temp3 = temp1->next;
        temp4 = temp2->next;
        temp1->next = temp4;
        temp2->next = temp3;
        temp1 = temp3->next;
        temp3->next = temp4->next;
        temp4->next = temp1;
    }
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
    int i, j;
    node *head = takeinput();
    cin >> i;
    cin >> j;
    head = swap_nodes(head, i, j);
    print(head);
    return 0;
}

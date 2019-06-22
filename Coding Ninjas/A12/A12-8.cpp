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
    if (minval == 0)
    {
        while ((maxval - 1) != 0)
        {
            temp1 = temp1->next;
            maxval--;
        }
        temp2 = temp1->next;
        head->next = temp1->next->next;
        temp2->next = head;
        head = temp1;
    }
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

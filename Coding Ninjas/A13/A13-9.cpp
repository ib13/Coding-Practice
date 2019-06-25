//bubble sort iterative
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

pair<node *, node *> swap_nodes(node *head, int i, int j)
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
    pair<node *, node *> p = make_pair(temp3, head);
    return p;
}
node *bubble_sort_LinkedList_itr(node *head)
{
    node *t1 = head;
    node *t2 = head->next;
    int length = 0;
    while (t1 != NULL)
    {
        length++;
        t1 = t1->next;
    }

    for (int i = 0; i < length; i++)
    {
        t1 = head;
        t2 = head->next;
        pair<node *, node *> p;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (t1->data > t2->data)
            {
                p = swap_nodes(head, j, j + 1);
                t1 = p.first;
                head = p.second;
            }
            t1 = t1->next;
            t2 = t1->next;
        }
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
    node *head = takeinput();
    head = bubble_sort_LinkedList_itr(head);
    print(head);
}

//insertion sort iterative
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

pair<pair<node *, node *>, node *> swap_nodes(node *head, int i, int j)
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
    pair<node *, node *> p = make_pair(temp4, temp3);
    pair<pair<node *, node *>, node *> p1 = make_pair(p, head);
    return p1;
}

node *insertion_sort_LinkedList_itr(node *head)
{
    node *t1 = head;
    node *t2 = head;
    node *t3 = head;
    int length = 0;
    while (t1 != NULL)
    {
        t1 = t1->next;
        length++;
    }
    t1 = head;
    pair<pair<node *, node *>, node *> p;
    for (int i = 0; i < length - 1; i++)
    {
        t1 = head;
        for (int j = 0; j < i; j++)
        {
            t1 = t1->next;
        }
        t2 = t1->next;
        node *t4 = t1;
        int minindex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (t2->data < t4->data)
            {
                minindex = j;
                t4 = t2;
            }
            t2 = t2->next;
        }
        p = swap_nodes(head, i, minindex);
        t2 = p.first.first;
        t1 = p.first.second;
        head = p.second;
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
    head = insertion_sort_LinkedList_itr(head);
    print(head);
}

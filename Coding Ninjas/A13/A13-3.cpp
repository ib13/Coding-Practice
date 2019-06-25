//merge sort recursive
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

node *mergeTwoLLs(node *head1, node *head2)
{
    node *t1 = head1;
    node *prev1 = NULL;
    node *t2 = head2;
    node *prev2 = NULL;
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

node *mergeSort(node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    node *mid = midpoint_linkedlist(head);
    node *t1 = head;
    node *t2 = mid->next;
    mid->next = NULL;
    t1 = mergeSort(t1);
    t2 = mergeSort(t2);
    head = mergeTwoLLs(t1, t2);
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
    head = mergeSort(head);
    print(head);
    return 0;
}

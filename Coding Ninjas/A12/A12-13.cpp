//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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

node *skipMdeleteN(node *head, int M, int N)
{
    int Mtemp = M - 1;
    int Ntemp = N + 1;
    node *t1 = head;
    while (t1 != NULL)
    {
        while (Mtemp-- && t1 != NULL)
        {
            t1 = t1->next;
        }
        if (t1 == NULL)
            break;
        Mtemp = M - 1;
        node *t2 = t1;
        while (Ntemp-- && t1 != NULL)
        {
            node *t3 = t1;
            t1 = t1->next;
            if (Ntemp != N)
                delete t3;
        }
        t2->next = t1;
        Ntemp = N + 1;
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
    int m, n;
    cin >> m >> n;
    head = skipMdeleteN(head, m, n);
    print(head);
    return 0;
}

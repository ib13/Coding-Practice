#include <iostream>
using namespace std;
#include <unordered_map>
template <typename T>
class ListNode
{
public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this->data = data;
        next = NULL;
    }
};

ListNode<int> *unionOf2LL(ListNode<int> *head1, ListNode<int> *head2)
{
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    ListNode<int> *head3 = NULL;
    ListNode<int> *temp1 = head1;
    ListNode<int> *temp2 = head2;
    while (temp1 != NULL)
    {
        m1[temp1->data]++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        m2[temp2->data]++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    while (temp1 != NULL)
    {
        for (int i = 0; i < max(m1[temp1->data], m2[temp1->data]); i++)
        {
            ListNode<int> *newNode = new ListNode<int>(temp1->data);
            newNode->next = head3;
            head3 = newNode;
        }
        m1[temp1->data] = 0;
        m2[temp1->data] = 0;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        for (int i = 0; i < max(m1[temp2->data], m2[temp2->data]); i++)
        {
            ListNode<int> *newNode = new ListNode<int>(temp2->data);
            newNode->next = head3;
            head3 = newNode;
        }
        m1[temp2->data] = 0;
        m2[temp2->data] = 0;
        temp2 = temp2->next;
    }
    return head3;
}

ListNode<int> *createlist()
{
    ListNode<int> *head = NULL;
    ListNode<int> *rear = NULL;
    int data;
    cin >> data;
    while (data != -1)
    {
        ListNode<int> *newnode = new ListNode<int>(data);
        if (head == NULL)
        {
            head = newnode;
            rear = head;
        }
        else
        {
            rear->next = newnode;
            rear = rear->next;
        }
        cin >> data;
    }
    return head;
}

void print(ListNode<int> *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{
    ListNode<int> *head1 = createlist();
    ListNode<int> *head, *head2 = createlist();
    head = unionOf2LL(head1, head2);
    print(head);
}

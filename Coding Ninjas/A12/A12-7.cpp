//Check if a linked list is a palindrome
#include <iostream>
#include <stack>
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

bool check_palindrome(node *head)
{
    node *temp1 = head;
    node *temp2 = head;
    int len = 0;
    while (temp1 != NULL || temp1->next != NULL)
    {
        len++;
        temp2 = temp2->next;
        temp1 = temp1->next->next;
    }
    if (len % 2 == 1)
        temp2 = temp2->next;

    stack<int> s;
    while (temp2 != NULL)
    {
        s.push(temp2->data);
        temp2 = temp2->next;
    }
    temp1 = head;
    while (!s.empty())
    {
        if (temp1->data != s.top())
            return false;
        temp1 = temp1->next;
        s.pop();
    }
    return true;
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
    bool ans = check_palindrome(head);
    if (ans)
        cout << "true";
    else
        cout << "false";
    return 0;
}

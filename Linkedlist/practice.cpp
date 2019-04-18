#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} * head;

void insert_at_end(int data)
{
    Node *newNode = new Node();
    Node *temp = head;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insert_at_beg(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

void delete_at_beg()
{
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void delete_at_nth(int pos)
{
    Node *temp1 = head;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

int main()
{
    head = NULL;
    int option = 1;
    while (option)
    {
        cout << "\n=====================================";
        cout << "\n0.Exit\n1.Insert at beginning\n2.Insert at end\n3.Print\n4.Delete from beginning\n5.Delete from nth pos\nEnter Option: ";
        cin >> option;
        int data;
        int pos;
        switch (option)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            insert_at_beg(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            insert_at_end(data);
            break;
        case 3:
            print();
            break;
        case 4:
            delete_at_beg();
            break;
        case 5:
            cout << "Enter index: ";
            cin >> pos;
            delete_at_nth(pos - 1);
            break;
        default:
            break;
        }
    }
    return 0;
}
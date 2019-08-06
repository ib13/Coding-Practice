#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
struct Node *addTwoLists(struct Node *first, struct Node *second);
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("");
}
void freeList(struct Node *Node)
{
    struct Node *temp;
    while (Node != NULL)
    {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void)
{
    int t, n, m, i, x;
    cin >> t;
    while (t--)
    {
        struct Node *res = NULL;
        struct Node *first = NULL;
        struct Node *second = NULL;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++)
        {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first)
            freeList(first);
        if (second)
            freeList(second);
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// write a function returns the resultant linked list
Node *addTwoLists(Node *first, Node *second)
{
    Node *t1 = first;
    Node *t2 = second;
    int l1 = 0;
    int l2 = 0;
    while (t1 != NULL)
    {
        l1++;
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        l2++;
        t2 = t2->next;
    }
    if (l1 > l2)
    {
        t1 = first;
        t2 = second;
    }
    else
    {
        t1 = second;
        t2 = first;
    }
    int carry = 0;
    Node *t3 = t1;
    Node *t4 = t1;
    while (t1 != NULL)
    {
        t4 = t1;
        int val;
        if (t2 != NULL)
            val = t1->data + t2->data + carry;
        else
            val = t1->data + carry;
        if (val >= 10)
        {
            carry = 1;
            t1->data = val - 10;
        }
        else
        {
            carry = 0;
            t1->data = val;
        }
        t1 = t1->next;
        if (t2 != NULL)
            t2 = t2->next;
    }
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        t4->next = newNode;
    }
    return t3;
}
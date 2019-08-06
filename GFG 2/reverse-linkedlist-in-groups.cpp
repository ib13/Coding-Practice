#include <bits/stdc++.h>
using namespace std;
/* Link list node */
struct node *reverse(struct node *head, int k);
struct node
{
    int data;
    struct node *next;
} * head;
/* UTILITY FUNCTIONS */
/* Function to push a node */
void insert()
{
    int n, value;
    cin >> n;
    struct node *temp;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->data = value;
            head->next = NULL;
            temp = head;
            continue;
        }
        else
        {
            temp->next = (struct node *)malloc(sizeof(struct node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t, k, value, n;
    cin >> t;
    while (t--)
    {
        insert();
        cin >> k;
        head = reverse(head, k);
        printList(head);
    }
    return (0);
}

/*This is a function problem.You only need to complete the function given below*/
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *reverse(struct node *head, int k)
{
    stack<node *> s;
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    while (curr != NULL)
    {
        count = 0;
        while (curr != NULL && count < k)
        {
            s.push(curr);
            curr = curr->next;
            count++;
        }

        while (!s.empty())
        {
            if (prev == NULL)
            {
                prev = s.top();
                head = prev;
                s.pop();
            }
            else
            {
                prev->next = s.top();
                prev = prev->next;
                s.pop();
            }
        }
    }
    prev->next = NULL;
    return head;
}

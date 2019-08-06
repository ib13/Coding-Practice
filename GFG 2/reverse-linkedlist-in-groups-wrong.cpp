#include <stdio.h>
#include <stdlib.h>
/* Link list node */
struct node
{
    int data;
    struct node *next;
} * head;
struct node *reverse(struct node *head, int k);
/* Reverses the linked list in groups of size k and returns the
   pointer to the new head node. */
/* UTILITY FUNCTIONS */
/* Function to push a node */
void insert()
{
    int n, value, i;
    scanf("%d", &n);
    struct node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
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
    /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
    scanf("%d", &t);
    while (t--)
    {
        insert();
        scanf("%d", &k);
        head = reverse(head, k);
        printList(head);
    }
    return (0);
}
/*This is a function problem.You only need to complete the function given below*/
/*
  Reverse a linked list
  The input list will have at least one element
  Return pointer to head of reverse linked list
  Node is defined as
  struct node
  {
     int data;
     struct Node *next;
  }
*/

node *reverseHelper(struct node *ptr, struct node *head, int k)
{
    node *t1 = ptr;
    node *prev = NULL;
    node *next = ptr->next;
    // int val = 1;
    // int i = 0;
    // for (i = 0; i < k; i++)
    // {
    //     if (t1->next != NULL)
    //         t1 = t1->next;
    //     else
    //         break;
    // }
    // t1 = ptr;
    // if (i == k)
    // {
    while (ptr->next != NULL && k--)
    {
        ptr->next = prev;
        prev = ptr;
        ptr = next;
        next = next->next;
    }
    if (ptr->next == NULL)
    {
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    if (t1 == head)
        head = prev;
    t1->next = ptr;
    return prev;
    // }
}

struct node *reverse(struct node *head, int k)
{
    int val = 1;
    node *t1 = head;
    int ktemp = k;
    while (t1 != NULL)
    {
        if (t1 != head)
        {
            t1->next = reverseHelper(t1->next, head, k);
        }
        else
        {
            head = reverseHelper(head, head, k);
        }
        // while (ktemp--)
        // {
        //     t1 = t1->next;
        // }
        // ktemp = k;
        if (val == 1)
        {
            val = 0;
        }
        else
        {
            while (ktemp != 0 && t1 != NULL)
            {
                t1 = t1->next;
            }
            ktemp = k;
        }
    }
    // t1 = t1->next;
    return head;
}

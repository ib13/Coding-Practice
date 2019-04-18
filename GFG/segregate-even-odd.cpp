// The idea is to get pointer to the last node of list.
// And then traverse the list starting from the head node and
// move the odd valued nodes from their current position to end of the list.
#include <bits/stdc++.h>
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

void segregate(int n)
{
    Node *temp = head;
    vector<int> even;
    vector<int> odd;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
            even.push_back(temp->data);
        else
            odd.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < even.size(); i++)
    {
        temp->data = even[i];
        temp = temp->next;
    }
    for (int i = 0; i < odd.size(); i++)
    {
        temp->data = odd[i];
        temp = temp->next;
    }
}

// // void segregate(int n)
// // {
// //     Node *temp1 = head;
// //     Node *temp2 = head;
// //     Node *temp3 = head->next;
// //     Node *temp4 = head;
// //     int k = 0;
// //     while (temp1->next != NULL)
// //     {
// //         temp1 = temp1->next;
// //     }
// //     while (temp3 != NULL)
// //     {
// //         if (temp2 == head && temp2->data % 2 == 1)
// //         {
// //             head = temp3;
// //             temp2->next == NULL;
// //             temp1->next = temp2;
// //             temp1 = temp1->next;
// //             temp2 = temp3;
// //             temp3 = temp3->next;
// //         }
// //         else if (temp2->data % 2 == 1)
// //         {
// //             if (k == 0)
// //             {
// //                 temp4 = head;
// //                 k = 1;
// //             }
// //             temp4->next = temp3;
// //             temp2->next = NULL;
// //             temp1->next = temp2;
// //             temp1 = temp1->next;
// //             temp4 = temp3;
// //             temp2 = temp3;
// //             temp3 = temp3->next;
// //         }
// //         else
// //         {
// //             if (k == 0)
// //             {
// //                 temp4 = head;
// //                 k = 1;
// //             }
// //             temp2 = temp3;
// //             temp3 = temp3->next;
// //         }
// //     }
// // }

// void segregate()
// {
//     Node *end = head;
//     Node *prev = NULL;
//     Node *curr = head;

//     /* Get pointer to the last node */
//     while (end->next != NULL)
//         end = end->next;

//     Node *new_end = end;

//     /* Consider all odd nodes before the first
//      even node and move then after end */
//     while (curr->data % 2 != 0 && curr != end)
//     {
//         new_end->next = curr;
//         curr = curr->next;
//         new_end->next->next = NULL;
//         new_end = new_end->next;
//     }

//     // 10->8->17->17->15
//     /* Do following steps only if
//     there is any even node */
//     if (curr->data % 2 == 0)
//     {
//         /* Change the head pointer to
//         point to first even node */
//         head = curr;

//         /* now current points to
//         the first even node */
//         while (curr != end)
//         {
//             if ((curr->data) % 2 == 0)
//             {
//                 prev = curr;
//                 curr = curr->next;
//             }
//             else
//             {
//                 /* break the link between
//                 prev and current */
//                 prev->next = curr->next;

//                 /* Make next of curr as NULL */
//                 curr->next = NULL;

//                 /* Move curr to end */
//                 new_end->next = curr;

//                 /* make curr as new end of list */
//                 new_end = curr;

//                 /* Update current pointer to
//                 next of the moved node */
//                 curr = prev->next;
//             }
//         }
//     }
// }

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        head = NULL;
        int n;
        cin >> n;
        int data;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            insert_at_end(data);
        }
        segregate(n);
        print();
    }
    return 0;
}
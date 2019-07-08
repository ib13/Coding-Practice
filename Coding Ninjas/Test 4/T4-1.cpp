#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
    }
};

Node<int> *takeinput()
{
    int data;
    cin >> data;
    Node<int> *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node<int> *newNode = new Node<int>(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Following is the Node<int> class already defined
template<typename T>
class Node<int>{
  public :
  T data;
  Node<int><T>* next;
  Node<int>(T data){
    this->data = data;
  }
};
*/
Node<int> *mergeTwoLLs(Node<int> *head1, Node<int> *head2)
{
    Node<int> *t1 = head1;
    Node<int> *prev1 = NULL;
    Node<int> *t2 = head2;
    Node<int> *prev2 = NULL;
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

Node<int> *midpoint_linkedlist(Node<int> *head)
{
    Node<int> *t1 = head;
    Node<int> *t2 = head;
    while (t2->next != NULL && t2->next->next != NULL)
    {
        t2 = t2->next->next;
        t1 = t1->next;
    }
    return t1;
}

Node<int> *mergeSort(Node<int> *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    Node<int> *mid = midpoint_linkedlist(head);
    Node<int> *t1 = head;
    Node<int> *t2 = mid->next;
    mid->next = NULL;
    t1 = mergeSort(t1);
    t2 = mergeSort(t2);
    head = mergeTwoLLs(t1, t2);
    return head;
}

Node<int> *sort(Node<int> *head)
{
    return mergeSort(head);
}

int main()
{
    Node<int> *head = takeinput();
    head = sort(head);
    print(head);
    return 0;
}

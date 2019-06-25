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
        next = NULL;
    }
};

template <typename T>
class Queue
{
    int size;
    Node<T> *front_ptr;
    Node<T> *rear_ptr;

public:
    Queue()
    {
        size = 0;
        front_ptr = NULL;
        rear_ptr = NULL;
    }

    void enqueue(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (front_ptr == NULL)
        {
            front_ptr = newNode;
            rear_ptr = front_ptr;
        }
        else
        {
            rear_ptr->next = newNode;
            rear_ptr = rear_ptr->next;
        }
        size++;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    T dequeue()
    {
        if (front_ptr == NULL)
            return 0;
        Node<T> *temp = front_ptr;
        T val = temp->data;
        front_ptr = front_ptr->next;
        delete temp;
        size--;
        return val;
    }

    T front()
    {
        if (front_ptr == NULL)
            return 0;
        return front_ptr->data;
    }
};

int main()
{

    Queue<int> q;

    int choice;
    cin >> choice;
    int input;

    while (choice != -1)
    {
        if (choice == 1)
        {
            cin >> input;
            q.enqueue(input);
        }
        else if (choice == 2)
        {
            int ans = q.dequeue();
            if (ans != 0)
            {
                cout << ans << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else if (choice == 3)
        {
            int ans = q.front();
            if (ans != 0)
            {
                cout << ans << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else if (choice == 4)
        {
            cout << q.getSize() << endl;
        }
        else if (choice == 5)
        {
            if (q.isEmpty())
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        cin >> choice;
    }
}

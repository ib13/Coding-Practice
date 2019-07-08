// C++ implementation of De-queue using circular
// array
#include <iostream>
using namespace std;

class Deque
{
    int *dequeue;
    int frontIndex;
    int rearIndex;
    int noOfElements;
    int size;

public:
    Deque(int size)
    {
        noOfElements = 0;
        frontIndex = 0;
        rearIndex = -1;
        dequeue = new int[size];
        this->size = size;
    }

    void insertFront(int data)
    {
        if (noOfElements == size)
        {
            cout << -1 << endl;
            return;
        }
        noOfElements++;
        frontIndex--;
        frontIndex = frontIndex % size;
        dequeue[frontIndex] = data;
    }

    void insertRear(int data)
    {
        if (noOfElements == size)
        {
            cout << -1 << endl;
            return;
        }
        noOfElements++;
        rearIndex++;
        rearIndex = rearIndex % size;
        dequeue[rearIndex] = data;
    }

    void deleteFront()
    {
        if (noOfElements == 0)
        {
            cout << -1 << endl;
            return;
        }
        noOfElements--;
        frontIndex++;
        frontIndex = frontIndex % size;
    }

    void deleteRear()
    {
        if (noOfElements == 0)
        {
            cout << -1 << endl;
            return;
        }
        noOfElements--;
        rearIndex--;
        rearIndex = rearIndex % size;
    }

    int getFront()
    {
        if (noOfElements == 0)
            return -1;
        return dequeue[frontIndex];
    }

    int getRear()
    {
        if (noOfElements == 0)
            return -1;
        return dequeue[rearIndex];
    }
};

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice, input;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            dq.insertFront(input);
            break;
        case 2:
            cin >> input;
            dq.insertRear(input);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            cout << dq.getFront() << "\n";
            break;
        case 6:
            cout << dq.getRear() << "\n";
            break;
        default:
            return 0;
        }
    }

    return 0;
}

#include <iostream>
using namespace std;
#include <climits>
#include <vector>
class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    // Return the size of priorityQueue - no of elements present
    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0; // Priority Queue is empty
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        int minval = pq[0];
        pq[0] = pq[getSize() - 1];
        pq[getSize() - 1] = minval;
        pq.pop_back();
        // auto it = pq.end();
        // pq.erase(it-1);
        int parentIndex = 0;
        while (true)
        {
            int C1Index = 2 * parentIndex + 1;
            int C2Index = 2 * parentIndex + 2;
            int minIndex = parentIndex;
            if (C1Index < getSize() && C2Index < getSize())
            {
                if (pq[parentIndex] < pq[C1Index] && pq[parentIndex] < pq[C2Index])
                    break;
                if (pq[C1Index] < pq[C2Index])
                    minIndex = C1Index;
                else
                    minIndex = C2Index;
            }
            else if (C1Index < getSize())
            {
                if (pq[parentIndex] < pq[C1Index])
                    break;
                else
                    minIndex = C1Index;
            }
            else
                break;
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;
            parentIndex = minIndex;
        }
        return minval;
    }
};

int main()
{
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMin
            cout << pq.getMin() << endl;
            break;
        case 3: // removeMax
            cout << pq.removeMin() << endl;
            break;
        case 4: // size
            cout << pq.getSize() << endl;
            break;
        case 5: // isEmpty
            if (pq.isEmpty())
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        default:
            return 0;
        }
        cin >> choice;
    }
}

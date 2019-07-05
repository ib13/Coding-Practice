#include <iostream>
using namespace std;
#include <vector>
class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    int getSize()
    {
        return pq.size();
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getMax()
    {
        if (isEmpty())
        {
            return 0; // Priority Queue is empty
        }
        return pq[0];
    }

    void insert(int data)
    {
        pq.push_back(data);
        int childIndex = getSize() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex])
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

    int removeMax()
    {
        int maxval = pq[0];
        pq[0] = pq[getSize() - 1];
        pq.pop_back();
        int parentIndex = 0;
        while (true)
        {
            int maxIndex = parentIndex;
            int c1Index = 2 * parentIndex + 1;
            int c2Index = 2 * parentIndex + 2;
            if (c2Index < getSize())
            {
                if (pq[c1Index] > pq[maxIndex])
                    maxIndex = c1Index;
                if (pq[c2Index] > pq[maxIndex])
                    maxIndex = c2Index;
            }
            else if (c1Index < getSize())
            {
                if (pq[c1Index] > pq[maxIndex])
                    maxIndex = c1Index;
            }

            if (maxIndex == parentIndex)
                break;
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[maxIndex];
            pq[maxIndex] = temp;
            parentIndex = maxIndex;
        }
        return maxval;
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
        case 2: // getMax
            cout << pq.getMax() << endl;
            break;
        case 3: // removeMax
            cout << pq.removeMax() << endl;
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

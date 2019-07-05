#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

    void heapify(int index)
    {
    }

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

    void insert(int data)
    {
        pq.push_back(data);
        int childIndex = getSize() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] > pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
};
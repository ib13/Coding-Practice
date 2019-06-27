#include <iostream>
using namespace std;
#include <queue>

template <typename T>
class stack
{
public:
    queue<T> *q1 = new queue<T>;
    queue<T> *q2 = new queue<T>;

    stack()
    {
    }

    void push(T data)
    {
        q1->push(data);
    }

    T pop()
    {
        T lastval = q1->front();
        while (q1->size() != 1)
        {
            q2->push(lastval);
            q1->pop();
            lastval = q1->front();
        }
        q1->pop();
        while (!q2->empty())
        {
            q1->push(q2->front());
            q2->pop();
        }
        return lastval;
    }

    T top()
    {
        T lastval;
        while (!q1->empty())
        {
            lastval = q1->front();
            q2->push(lastval);
            q1->pop();
        }
        while (!q2->empty())
        {
            q1->push(q2->front());
            q2->pop();
        }
        return lastval;
    }

    T getSize()
    {
        return q1->size();
    }
};

int main()
{
    stack<int> s;
    int choice, input;

    while (true)
    {

        cin >> choice;

        switch (choice)
        {
        case 1:
            cin >> input;
            s.push(input);
            break;
        case 2:
            cout << s.pop() << "\n";
            break;
        case 3:
            cout << s.top() << "\n";
            break;
        case 4:
            cout << s.getSize() << endl;
            break;
        case 5: // Test
            while (!s.q1->empty())
            {
                cout << s.q1->front() << " ";
                s.q1->pop();
            }
            return 0;
        default:
            return 0;
            break;
        }
    }
}

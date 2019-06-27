#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &s)
{
    stack<int> temp;
    int popval;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
        if (!s.empty())
        {
            if (s.top() < temp.top())
            {
                popval = s.top();
                s.pop();
                while (!temp.empty() && temp.top() > popval)
                {
                    s.push(temp.top());
                    temp.pop();
                }
                temp.push(popval);
            }
        }
    }
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack<int> input;
    int size, value;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> value;
        input.push(value);
    }
    sortStack(input);
    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
}

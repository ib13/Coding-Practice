#include <iostream>
#include <climits>
#include <stack>
using namespace std;

void Leaders(int *arr, int len)
{
    stack<int> s;
    int max_element = arr[len - 1];
    s.push(arr[len - 1]);
    for (int i = len - 2; i >= 0; i--)
    {
        if (arr[i] >= max_element)
        {
            s.push(arr[i]);
        }
        max_element = max(max_element, arr[i]);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    int len;
    cin >> len;
    int *arr = new int[len + 1];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    Leaders(arr, len);
}

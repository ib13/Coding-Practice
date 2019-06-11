#include <iostream>
#include <map>
using namespace std;

int highestFrequency(int *input, int n)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[input[i]]++;
    }
    auto it = m.begin();
    int max_element;
    int max_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[input[i]] > max_count)
        {
            max_count = m[input[i]];
            max_element = input[i];
        }
    }

    return max_element;
}

int main()
{
    int n;
    int input[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int maxKey = highestFrequency(input, n);
    cout << maxKey;
    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

// O(n^2)
// int *stockSpan(int *price, int size)
// {
//     int *arr = new int[size];
//     int count;
//     arr[0] = 1;
//     for (int i = 1; i < size; i++)
//     {
//         count = 1;
//         int j = i;
//         while (j)
//         {
//             if (price[j - 1] < price[i])
//                 count++;
//             else
//                 break;
//             j--;
//         }
//         arr[i] = count;
//     }
//     return arr;
// }

// O(n) soln
// we use logic that if prev element is smaller then it has all elements of smaller one so dont check for those
// int *stockSpan(int *price, int size)
// {
//     stack<int> s; //stores index of the elements
//     s.push(0);
//     int *arr = new int[size];
//     int count;
//     arr[0] = 1;
//     for (int i = 1; i < size; i++)
//     {
//         while (!s.empty() && price[s.top()] < price[i])
//             s.pop();
//         if (s.empty())
//             arr[i] = i + 1;
//         else
//             arr[i] = i - s.top();
//         s.push(i);
//     }
//     return arr;
// }

// O(n) without stack (using DP) //TLE
int *stockSpan(int *price, int size)
{
    int *arr = new int[size];
    int count = 1;
    arr[0] = 1;
    for (int i = 1; i < size; i++)
    {
        int index = i - 1;
        while (index != 0 && price[index] < price[i])
        {
            index = index - arr[index];
        }
        if (index == 0 && price[0] < price[i])
            index--;
        arr[i] = i - index;
    }
    return arr;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }
}
#include <iostream>
using namespace std;
#include <vector>

// We see the longest sequence starting with each element in array
vector<int> longestSubsequence(int *arr, int n)
{
    vector<int> v;
    int maxlen = 1;
    int currlen = 0;
    int hashtable[100000] = {0};
    for (int i = 0; i < n; i++)
    {
        hashtable[arr[i]] = 1;
    }
    v.push_back(arr[0]);

    for (int i = 0; i < n; i++)
    {
        currlen = 0;
        int key = arr[i];
        while (hashtable[key++] == 1)
        {
            currlen++;
        }
        if (currlen > maxlen)
        {
            maxlen = currlen;
            currlen = 0;
            v.clear();
            for (int j = arr[i]; j < key - 1; j++)
            {
                v.push_back(j);
            }
        }
    }
    return v;

    // A little long and few errors
    // for (int i = 0; i < 100000 - 1; i++)
    // {
    //     if (hashtable[i] == 1 && hashtable[i + 1] == 1)
    //     {
    //         currlen++;
    //         temp.push_back(i);
    //     }
    //     else if (hashtable[i] == 1 && hashtable[i + 1] == 0)
    //     {
    //         temp.push_back(i);
    //     }
    //     else
    //     {
    //         if (currlen == maxlen)
    //         {
    //             for (int j = 0; j < n; j++)
    //             {
    //                 if (v[0] == arr[j])
    //                 {
    //                     break;
    //                 }
    //                 if (temp[0] == arr[j])
    //                 {
    //                     currlen = 1;
    //                     v.clear();
    //                     for (int k = 0; k < temp.size(); k++)
    //                     {
    //                         v.push_back(temp[k]);
    //                     }
    //                     break;
    //                 }
    //             }
    //         }
    //         else if (currlen > maxlen)
    //         {
    //             maxlen = currlen;
    //             currlen = 1;
    //             v.clear();
    //             for (int j = 0; j < temp.size(); j++)
    //             {
    //                 v.push_back(temp[j]);
    //             }
    //         }
    //         temp.clear();
    //     }
    // }
    // return v;
}

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector<int> output = longestSubsequence(input, n);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}

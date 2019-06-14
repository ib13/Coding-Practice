#include <iostream>
#include <unordered_map>
using namespace std;
#include <unordered_map>
using namespace std;

void printPairs(int *input, int n, int k)
{
    // Write your code here
    int a;
    int b;
    int c;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[input[i]]++;
    int d = 0;
    int e;
    if (k == 0)
    { //cout<<'k'<<endl;
        for (int j = 0; j < n; j++)
        { //  cout<<"l1"<<endl;
            if (freq[input[j]] > 1)
            { //   cout<<"l2"<<endl;
                d = freq[input[j]];
                e = d * (d - 1) / 2;
                while (e--)
                {
                    cout << input[j] << ' ' << input[j] << endl;
                }
            }
            freq[input[j]] = 0;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            //cout<<input[i]-k<<endl;

            if (freq.count(input[i] - k) > 0)
            {
                a = freq[input[i] - k];
                b = freq[input[i]];
                c = a * b;
                while (c--)
                {
                    cout << input[i] - k << ' ' << input[i] << endl;
                }
            }
            if (freq.count(input[i] + k) > 0)
            {

                a = freq[input[i] + k];
                b = freq[input[i]];
                c = a * b;
                while (c--)
                {
                    cout << input[i] << ' ' << input[i] + k << endl;
                }
            }

            freq[input[i]] = 0;
            // cout<<input[i]<<' '<<freq[input[i]]<<endl;
        }
    }
}

// 1 test case wrong
/*
void printPairs(int *input, int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[input[i]]++;
    }
    if (k != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m[input[i] - k] * m[input[i]]; j++)
            {
                cout << input[i] - k << " " << input[i] << endl;
            }
            for (int j = 0; j < m[input[i] + k] * m[input[i]]; j++)
            {
                cout << input[i] << " " << input[i] + k << endl;
            }
            m[input[i]] = 0;
        }
    }
    else if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (m[input[i]] * m[input[i]] - 1) / 2; j++)
            {
                cout << input[i] << " " << input[i] << endl;
            }
            m[input[i]] = 0;
        }
    }


}
*/

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int k;
    cin >> k;
    printPairs(input, n, k);
}

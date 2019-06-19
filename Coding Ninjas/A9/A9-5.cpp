#include <iostream>
#include <vector>
using namespace std;

void printSubsetSumToKHelper(int input[], int size, int start, int k, vector<int> v, int sum, int visited[])
{
    if (sum == k)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    if (sum > k)
        return;

    for (int i = start; i < size; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            v.push_back(input[i]);
            printSubsetSumToKHelper(input, size, i, k, v, sum + input[i], visited);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

void printSubsetSumToK(int input[], int size, int k)
{
    vector<int> v;
    int visited[size] = {0};
    printSubsetSumToKHelper(input, size, 0, k, v, 0, visited);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
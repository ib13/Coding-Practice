#include <iostream>
using namespace std;
#include <vector>
#include <queue>
vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    vector<int> finalvector;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int allsize = 0;
    for (int i = 0; i < input.size(); i++)
    {
        pair<int, int> p;
        p.first = input[i]->at(0); //or  (*input[i])[0];
        p.second = i;
        pq.push(p);
        allsize += input[i]->size();
    }
    int storeIndex[input.size()] = {0};
    for (int i = 0; i < allsize; i++)
    {
        pair<int, int> minTop = pq.top();
        finalvector.push_back(minTop.first);
        storeIndex[minTop.second]++;
        pq.pop();
        if (storeIndex[minTop.second] < input[minTop.second]->size())
        {
            pair<int, int> p;
            p.first = input[minTop.second]->at(storeIndex[minTop.second]);
            p.second = minTop.second;
            pq.push(p);
        }
    }
    return finalvector;
}

int main()
{

    int k;
    cin >> k;
    vector<vector<int> *> input;
    for (int j = 1; j <= k; j++)
    {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            current->push_back(a);
        }
        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++)
        cout << output[i] << " ";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void findOverlap(int entry[], int exit[], int n)
{
    sort(entry, entry + n);
    sort(exit, exit + n);
    int time = 0;
    int maxGuest = 1;
    int guests = 1;
    int i = 0;
    int j = 1;
    while (i < n && j < n)
    {
        if (exit[i] >= entry[j])
        {
            guests++;
            if (maxGuest < guests)
            {
                maxGuest = guests;
                time = entry[j];
            }
            j++;
        }
        else
        {
            guests--;
            i++;
        }
    }
    cout << maxGuest << " " << time << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *entry = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> entry[i];
        }

        int *exit = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> exit[i];
        }
        findOverlap(entry, exit, n);
    }
    return 0;
}
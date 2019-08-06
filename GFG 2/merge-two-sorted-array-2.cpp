#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        int *a1 = new int[n1];
        int *a2 = new int[n2];
        for (int i = 0; i < n1; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> a2[i];
        }
        for (int i = n2 - 1; i >= 0; i--)
        {
            if (a2[i] < a1[n1 - 1])
            {
                int temp = a2[i];
                a2[i] = a1[n1 - 1];
                a1[n1 - 1] = temp;
                int index = n1 - 1;
                while (index > 0)
                {
                    if (a1[index - 1] > temp)
                    {
                        a1[index] = a1[index - 1];
                    }
                    else
                    {
                        a1[index] = temp;
                        break;
                    }
                    index--;
                }
                if (index == 0)
                    a1[0] = temp;
            }
        }
        for (int i = 0; i < n1; i++)
        {
            cout << a1[i] << " ";
        }
        for (int i = 0; i < n2; i++)
        {
            cout << a2[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
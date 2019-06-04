#include <iostream>
using namespace std;

void spiralPrint(int a[][1000], int m, int n)
{
    int i, k = 0, l = 0;

    while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
            cout << a[k][i] << " ";
        }
        k++;

        for (i = k; i < m; ++i)
        {
            cout << a[i][n - 1] << " ";
        }
        n--;

        if (k < m)
        {
            for (i = n - 1; i >= l; --i)
            {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }

        if (l < n)
        {
            for (i = m - 1; i >= k; --i)
            {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }
}

int main()
{
    int input[1500][1000];
    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> input[i][j];
        }
    }
    spiralPrint(input, row, col);
}
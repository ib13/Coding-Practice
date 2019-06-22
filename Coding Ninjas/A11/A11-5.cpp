#include <iostream>
using namespace std;

int count(int S[], int m, int n)
{
    int i, j, x, y;

    // We need n+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (n = 0)
    int table[n + 1][m];

    // Fill the enteries for 0
    // value case (n = 0)
    for (i = 0; i < m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;

            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    return count(denominations, numDenominations, value);
}

int main()
{

    int numDenominations;
    cin >> numDenominations;
    int *denominations = new int[numDenominations];
    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }
    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);
}

#include <iostream>
using namespace std;
bool checkPlacement(int **chessboard, int n, int row, int col)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (chessboard[row][i] == 1)
            return false;
        if (chessboard[i][col] == 1)
            return false;
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (chessboard[i][j])
            return false;
    }

    for (i = row, j = col; j < n && i >= 0; i--, j++)
    {
        if (chessboard[i][j])
            return false;
    }

    return true;
}

void placeNQueensHelper(int **chessboard, int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << chessboard[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (checkPlacement(chessboard, n, row, j))
        {
            chessboard[row][j] = 1;
            placeNQueensHelper(chessboard, n, row + 1);
            chessboard[row][j] = 0;
        }
    }
}

void placeNQueens(int n)
{
    int **chessboard = new int *[n];
    for (int i = 0; i < n; i++)
    {
        chessboard[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            chessboard[i][j] = 0;
        }
    }
    placeNQueensHelper(chessboard, n, 0);
}

int main()
{

    int n;
    cin >> n;
    placeNQueens(n);
}

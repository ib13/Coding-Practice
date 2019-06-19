#include <iostream>
using namespace std;

bool checkSudoku(int board[][9], int x, int y, int num)
{
    if (board[x][y] != 0)
        return true;

    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == num)
            return false;
        if (board[x][i] == num)
            return false;
    }
    int tx = x / 3;
    int ty = y / 3;
    for (int i = tx * 3; i < tx * 3 + 3; i++)
    {
        for (int j = ty * 3; j < ty * 3 + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

bool sudokuSolverHelper(int board[][9])
{
    int x = 0, y = 0;
    int zeroexist = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0 && !zeroexist)
            {
                x = i;
                y = j;
                zeroexist = 1;
            }
        }
    }
    if (!zeroexist)
        return true;

    if (x == 8 && y == 8)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (checkSudoku(board, x, y, i))
            {
                board[x][y] = i;
                return true;
            }
        }
        return false;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (checkSudoku(board, x, y, i))
        {
            board[x][y] = i;
            if (sudokuSolverHelper(board))
                return true;
            board[x][y] = 0;
        }
    }
    return false;
}
bool sudokuSolver(int board[][9])
{
    return sudokuSolverHelper(board);
}

int main()
{

    int n = 9;
    int board[9][9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (sudokuSolver(board))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}

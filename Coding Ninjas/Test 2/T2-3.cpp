#include <iostream>
#include <string>
using namespace std;

void printinc(int n, string s)
{
    if (n == 0)
    {
        cout << s << " ";
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        char c = '0' + i;
        if (s == "")
            printinc(n - 1, s + c);
        else
        {
            if (i > s[s.length() - 1] - '0')
            {
                printinc(n - 1, s + c);
            }
        }
    }
}

void printIncreasingNumbers(int n)
{
    printinc(n, "");
}

int main()
{
    int n;
    cin >> n;
    printIncreasingNumbers(n);
}

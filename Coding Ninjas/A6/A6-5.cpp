#include <iostream>
#include <string>
using namespace std;

void print(int num, string output)
{
    if (num <= 0)
    {
        cout << output << endl;
        return;
    }
    string keys[] = {"",
                     "",
                     "abc",
                     "def",
                     "ghi",
                     "jkl",
                     "mno",
                     "pqrs",
                     "tuv",
                     "wxyz"};

    for (int i = 0; i < keys[num % 10].length(); i++)
    {
        print(num / 10, output + keys[num % 10][i]);
    }
}

void printKeypad(int num)
{
    print(num, "");
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

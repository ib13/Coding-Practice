#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[])
{
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

    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    int prevlen = keypad(num / 10, output);
    for (int i = 0; i < keys[num % 10].length() * prevlen; i++)
    {
        output[i] = output[i % prevlen];
    }
    int k = 0;
    for (int j = 0; j < keys[num % 10].length(); j++)
    {
        for (int i = 0; i < prevlen; i++)
        {
            output[k] = output[k] + keys[num % 10][j];
            k++;
        }
    }
    return keys[num % 10].length() * prevlen;
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}

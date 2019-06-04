#include <iostream>
using namespace std;

void reverseEachWord(char input[])
{
    int j = 0, k = -1;
    for (int i = 0; input[i] != '\0'; i++)
    {
        k++;
        if (input[i] == ' ')
        {
            k--;
            for (int l = j; l < ((j + k) / 2) + 1; l++)
            {
                char temp = input[l];
                input[l] = input[k + j - l];
                input[k + j - l] = temp;
            }
            k = k + 1;
            j = k + 1;
        }
    }
    for (int l = j; l < ((j + k) / 2) + 1; l++)
    {
        char temp = input[l];
        input[l] = input[k + j - l];
        input[k + j - l] = temp;
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseEachWord(input);
    cout << input << endl;
}

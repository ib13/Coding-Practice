#include <iostream>
using namespace std;

// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.

void stringCompression(char input[])
{
    int index = 0;
    char tempstr[1000];
    int count = 1;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == input[i + 1])
            count++;
        else
        {
            if (count > 1)
            {
                tempstr[index++] = input[i];
                tempstr[index++] = char(48 + count);
            }
            else
            {
                tempstr[index++] = input[i];
            }
            count = 1;
        }
    }
    tempstr[index] = '\0';
    // for (int i = 0; tempstr[i] != '\0'; i++)
    // {
    //     cout << tempstr[i];
    // }
    int i;
    for (i = 0; tempstr[i] != '\0'; i++)
    {
        input[i] = tempstr[i];
    }
    input[i] = '\0';
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    stringCompression(input);
    cout << input << endl;
}

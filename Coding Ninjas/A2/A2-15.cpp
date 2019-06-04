#include <string>
#include <iostream>
using namespace std;
void findLargestUniqueSubstring(char input[], char output[])
{
    int strlen = 0;
    int i = 0, j = 0;
    for (int k = 0; input[k] != '\0'; k++)
    {
        strlen++;
    }
    int maxlen = 1;
    int currlen = 0;
    string s = "" + input[0];
    int chararray[26] = {0};
    while (j < strlen)
    {
        int tempval = 0;
        for (int k = i; k < j; k++)
        {
            if (chararray[(input[j] - 'a')] == 1)
                tempval = 1;
        }

        if (tempval == 1)
        {
            chararray[(input[i] - 'a')] = 0;
            currlen--;
            i++;
        }
        else
        {
            chararray[(input[j] - 'a')] = 1;
            j++;
            currlen++;
        }
        if (currlen > maxlen)
        {
            s = "";
            for (int k = i; k < j; k++)
            {
                s += input[k];
            }
            cout << s << endl;
            maxlen = currlen;
        }
    }
    int ptr = 0;
    for (ptr = 0; ptr < s.size(); ptr++)
    {
        output[ptr] = s[ptr];
    }
    output[ptr] = '\0';
}

using namespace std;

int main()
{
    char input[1000], output[1000];
    cin.getline(input, 1000);
    findLargestUniqueSubstring(input, output);
    cout << output << endl;
}

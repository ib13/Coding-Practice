#include <iostream>
#include <string.h>
using namespace std;

void breakWords(char *S)
{
    string finalstr = "";
    string temp = "";
    for (int i = 0; S[i] != '\0'; i++)
    {
        if (S[i] != ' ')
        {
            temp += S[i];
        }
        else if (S[i] == ' ')
        {
            int len = temp.length();
            if (len % 2 == 1 || (len % 2 == 0 && len < 4))
            {
                finalstr += temp + " ";
            }
            else
            {
                finalstr += temp.substr(0, len / 2) + " " + temp.substr(len / 2) + " ";
            }
            temp = "";
        }
    }
    int len = temp.length();
    if (len % 2 == 1 || (len % 2 == 0 && len < 4))
    {
        finalstr += temp + " ";
    }
    else
    {
        finalstr += temp.substr(0, len / 2) + " " + temp.substr(len / 2) + " ";
    }

    for (int i = 0; i < finalstr.size() - 1; i++)
    {
        S[i] = finalstr[i];
    }
    S[finalstr.size() - 1] = '\0';
}

int main()
{
    char str[100000];
    cin.getline(str, 100000);
    breakWords(str);
    cout << str;
}

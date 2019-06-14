#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int getCodes(string input, string output[10000])
{
    if (input.length() == 1)
    {
        int intval3 = input[0]-'0';
        char charval3 = 'a'+intval3-1;
        output[0] = charval3;
        return 1;
    }
    if(input.length()<=0)
    {
        output[0]="";
        return 1;
    }
    int c1 = getCodes(input.substr(1), output);
    string arr1[c1];
    int intval1 = input[0]-'0';
    char charval1 = 'a'+intval1-1;
    for (int i = 0; i < c1; i++)
    {
        arr1[i] = charval1+output[i];
    }
    int c2 = getCodes(input.substr(2), output);
    string arr2[c2];
    int intval2 = (input[0]-'0')*10+input[1]-'0';
    if(intval2<=26)
    {
        char charval2 = 'a'+intval2-1;
        for (int i = 0; i < c2; i++)
        {
            arr2[i] = charval2+output[i];
        }
    }
    else
    {
        c2=0;
    }
    for (int i = 0; i < c1; i++)
    {
        output[i] = arr1[i];
    }
    for (int i = 0; i < c2; i++)
    {
        output[i+c1] = arr2[i];
    }
        return c1 + c2;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

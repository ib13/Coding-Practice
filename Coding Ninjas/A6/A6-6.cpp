#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int strtoint(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    int numval = s[0] - '0';
    return numval * pow(10, s.length() - 1) + strtoint(s.substr(1));
}

int stringToNumber(char input[])
{
    string s(input);
    return strtoint(s);
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

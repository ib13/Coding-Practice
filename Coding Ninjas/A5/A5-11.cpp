#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(char input[])
{
    string s(input);
    // cout << s << endl;
    if (s.length() <= 1)
        return true;
    for (int i = 1; i < s.length() - 1; i++)
    {
        input[i - 1] = s[i];
    }
    input[s.length() - 2] = '\0';
    bool ans = checkPalindrome(input);
    if (s[0] == s[s.length() - 1] && ans)
        return true;
    return false;
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

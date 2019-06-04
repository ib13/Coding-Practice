#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverseStringWordWise(char input[])
{
    stack<string> s;
    string str = "";
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            s.push(str);
            str = "";
        }
        else
            str += input[i];
    }
    string tempstr = "";
    s.push(str);
    while (!s.empty())
    {
        tempstr += s.top() + " ";
        s.pop();
    }
    for (int i = 0; input[i] != '\0'; i++)
    {
        input[i] = tempstr[i];
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}

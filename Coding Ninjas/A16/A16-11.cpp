#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int depthHelper(char str[], int len)
{
}
int depth(char str[])
{
    int len = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
        len++;
    return depthHelper(str, len);
}

int main()
{
    char *str = new char[100000];
    cin >> str;
    cout << depth(str);
    return 0;
}

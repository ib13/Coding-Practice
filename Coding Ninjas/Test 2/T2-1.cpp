#include <iostream>
using namespace std;

int strings(char input[], int k, char output[][100], int strlen, int &size, string s)
{
    if (k == 0)
    {
        for (int i = 0; i < s.length(); i++)
        {
            output[size][i] = s[i];
        }
        return ++size;
    }
    for (int i = 0; i < strlen; i++)
    {
        strings(input, k - 1, output, strlen, size, s + input[i]);
    }
    return size;
}

int allStrings(char input[], int k, char output[][100])
{
    int strlen = 0;
    for (int i = 0; input[i] != '\0'; i++)
        strlen++;
    int size = 0;
    return strings(input, k, output, strlen, size, "");
    return size;
}

int main()
{
    char a[100];
    char b[1000][100];
    cin >> a;
    int k;
    cin >> k;
    int size = allStrings(a, k, b);
    for (int i = 0; i < size; i++)
    {
        cout << b[i] << endl;
    }
}

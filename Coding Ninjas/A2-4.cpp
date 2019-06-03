#include <iostream>
using namespace std;

bool isPermutation(char input1[], char input2[])
{
    int arr1[26] = {0};
    int arr2[26] = {0};
    for (int i = 0; input1[i] != '\0'; i++)
    {
        arr1[input1[i] - 'a']++;
    }
    for (int i = 0; input2[i] != '\0'; i++)
    {
        arr2[input2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

int main()
{
    char input1[1000], input2[1000];
    cin.getline(input1, 1000);
    cin.getline(input2, 1000);
    if (isPermutation(input1, input2) == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}

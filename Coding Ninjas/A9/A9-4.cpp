#include <iostream>
#include <string>
using namespace std;

void printSubsetsOfArrayHelper(int input[], int size, string s)
{
    if (size == 0)
    {
        cout << s << endl;
        return;
    }
    string inpToStr = to_string(input[0]);
    printSubsetsOfArrayHelper(input + 1, size - 1, s + inpToStr + " ");
    printSubsetsOfArrayHelper(input + 1, size - 1, s);
}

void printSubsetsOfArray(int input[], int size)
{
    printSubsetsOfArrayHelper(input, size, "");
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}

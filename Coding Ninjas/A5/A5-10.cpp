#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double geometricSum(int k)
{
    if (k == 0)
        return 1;
    double ans = geometricSum(k - 1);
    return (1.0 / pow(2, k)) + ans;
}

int main()
{
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;
}

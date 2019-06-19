#include <iostream>
#include <climits>
using namespace std;

int countStepsTo1Helper(int n, int arr[])
{
  if (n <= 1)
    return 0;

  if (arr[n] > 0)
    return arr[n];

  int c1 = INT_MAX, c2 = INT_MAX, c3 = INT_MAX;
  c1 = countStepsTo1Helper(n - 1, arr);
  if (n % 2 == 0)
    c2 = countStepsTo1Helper(n / 2, arr);
  if (n % 3 == 0)
    c3 = countStepsTo1Helper(n / 3, arr);

  int minval = min(min(c1, c2), c3);
  arr[n] = 1 + minval;
  return 1 + minval;
}

int countStepsTo1(int n)
{
  int arr[n + 1] = {0};
  return countStepsTo1Helper(n, arr);
}

int main()
{
  int n;
  cin >> n;
  cout << countStepsTo1(n) << endl;
}

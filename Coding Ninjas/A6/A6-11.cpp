#include <iostream>
using namespace std;

long long ways(int N, char prev, char prev_prev)
{
    if (N == 1)
        return 1;
    if (prev == 'B' && prev_prev == 'W')
        return ways(N - 1, 'R', 'B');
    else if (prev == 'B' && prev_prev == 'R')
        return ways(N - 1, 'W', 'B');
    else if (prev == 'W' && prev_prev == 'R')
        return ways(N - 1, 'R', 'W') + ways(N - 1, 'B', 'W');
    else if (prev == 'R' && prev_prev == 'W')
        return ways(N - 1, 'W', 'R') + ways(N - 1, 'B', 'R');
    else if (prev == 'W' && prev_prev == 'B')
        return ways(N - 1, 'R', 'W') + ways(N - 1, 'B', 'W');
    else if (prev == 'R' && prev_prev == 'B')
        return ways(N - 1, 'W', 'R') + ways(N - 1, 'B', 'R');
}

long long find_Ways(int N)
{
    if (N == 1 || N == 2)
        return 2;
    return ways(N - 2, 'B', 'R') + ways(N - 2, 'B', 'W') + ways(N - 2, 'W', 'R') + ways(N - 2, 'R', 'W');
}

int main()
{
    int N;
    cin >> N;
    cout << find_Ways(N);
}

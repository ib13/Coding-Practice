#include<iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        int B[n];
        int remainder[n];
        for (int i = 0; i < n; ++i) {
            cin>>A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin>>B[i];
        }
        for (int i = 0; i < n; ++i) {
            remainder[i]=A[i]%B[i];
        }
        int min_B=INT_MAX;
        for (int i = 0; i < n; ++i) {
            min_B=min(min_B,B[i]);
        }
        int min_opr=INT_MAX;
        int opr=0;
        for (int i = 0; i < min_B; ++i) {
            opr=0;
            for (int j = 0; j < n; ++j) {
                opr+=B[i]-remainder[i]);
            }
        }
    }
    return 0;
}
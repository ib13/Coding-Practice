#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int A[n];
        for (int i = 0; i < n; ++i) {
            cin>>A[i];
        }
        sort(A,A+n);
        int it=0;
        while(A[it]<=k) {
            it++;
        }
        int num;
        while(it<n-1) {
            num = (A[it] - k);
            A[it] = k;
            A[it + 1] -= num;
            it++;
        }
        int sum=0;
        for (int i = 0; i < n; ++i) {
            sum+=A[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}


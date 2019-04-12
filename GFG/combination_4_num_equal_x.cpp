//https://practice.geeksforgeeks.org/problems/four-elements/0
#include <iostream>
#include <algorithm>
using namespace std;

int find_combination(int A[],int n,int x)
{
    int sum=0;
    for(int i1=0;i1<n;i1++)
    {
        for(int i2=i1+1;i2<n;i2++)
        {
            int l = i2 + 1;
            int r = n-1;
            while (l < r)
            {
                if (A[i1] + A[i2] + A[l] + A[r] == x)
                    return 1;
                else if (A[i1] + A[i2] + A[l] + A[r] < x)
                    l++;
                else
                    r--;
            }
        }
    }
    return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        int x;
        for(int i=0;i<n;i++)
            cin>>A[i];
        cin>>x;
        sort(A,A+n);
        cout<<find_combination(A,n,x)<<endl;
    }
    return 0;
}


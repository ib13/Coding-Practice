//https://www.hackerrank.com/contests/rookierank-4/challenges/winning-hand-of-cards
#include <bits/stdc++.h>
using namespace std;


long int winningHands(long int m,long int x, vector <long int> a,long int n) 
{
    long int j,k,l;
    long int t[n];
    long int i;
    long int pro=1;
    long int count=0;
    for(i=0;i<pow(2,n);i++)
    {
        pro=1;
        k=n-1;
        l=i;
        while(k>=0)
        {
            t[k]=l%2;
            l=l/2;
            k--;
        }

        for(j=0;j<n;j++)
        {
            if(t[j]==1)
                pro=pro*a[j];
        }
        if(pro%m==x)
            count++;

    }
    return count;
}

int main() {
    long int n;
    long int m;
    long int x;
    cin >> n >> m >> x;
    vector<long int> a(n);
    for(long int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    long int result = winningHands(m,x,a,n);
    cout << result << endl;
    return 0;
}

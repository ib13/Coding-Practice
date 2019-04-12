//https://www.hackerrank.com/contests/rookierank-4/challenges/winning-hand-of-cards
#include <bits/stdc++.h>
using namespace std;
int *dec_to_bin(int n,int m)
{
    int A[n];
    int i=n-1;
    while(i>=0)
    {
        A[i]=m%2;
        m=m/2;
        i--;
    }
    return A;

}

int winningHands(int m, int x, vector <int> a,int n) 
{
    int i,j;
    int *ptr;
    int t[n];
    int pro=1,count=0;
    for(i=0;i<pow(2,n);i++)
    {
        pro=1;
        ptr=dec_to_bin(n,i); 
        for(j=0;j<n;j++)
        {
            t[j]=*ptr;
            ptr++;                        
        }
        for(j=0;j<n;j++)
        {
            if(t[j]==0)
                pro=pro*a[j];
        }
        if(pro%m==x)
            count++;
        // for(j=0;j<n;j++)
        //     cout<<t[j];
        // cout<<endl;
    }
    return count;
}

int main() {
    int n;
    int m;
    int x;
    cin >> n >> m >> x;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = winningHands(m,x,a,n);
    cout << result << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n>>m;
        int A[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }
        int r_s=0,r_l=n,c_s=0,c_l=m;
        while(r_s<r_l && c_s<c_l)
        {
            for (int i = c_s; i < c_l; i++)
            {
                cout<<A[r_s][i]<<" ";
            }
            r_s++;
            for (int i = r_s; i < r_l; i++)
            {
                cout<<A[i][c_l-1]<<" ";
            }
            c_l--;
            if(r_s<r_l)
            {
                for (int i = c_l-1; i>=c_s; i--)
                {
                    cout<<A[r_l-1][i]<<" ";
                }
                r_l--;
            }
            if(c_s<c_l)
            {
                for (int i = r_l-1; i >= r_s; i--)
                {
                    cout<<A[i][c_s]<<" ";
                }
                c_s++;
            }
        }
        cout<<endl;
    }
    return 0;
}
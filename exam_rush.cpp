//https://www.hackerrank.com/contests/rookierank-4/challenges/exam-rush
#include <bits/stdc++.h>

using namespace std;

int examRush(vector <int> tm, int t) {
    sort(tm.begin(),tm.end());
    int i=0,count=0;
    // for(i=0;i<tm.size();i++)
    //     cout<<tm[i];
    while(tm[i]<=t && t>=0)
    {
        count++;
        t-=tm[i];
        i++;
    }
    return count;
}

int main() {
    int n;
    int t;
    cin >> n >> t;
    vector<int> tm(n);
    for(int tm_i = 0; tm_i < n; tm_i++){
       cin >> tm[tm_i];
    }
    int result = examRush(tm, t);
    cout << result << endl;
    return 0;
}

//https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values/0
// Another Approach : https://ide.geeksforgeeks.org/A67sbd2Dr7
#include <iostream>
#include <set>
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
        for (int i = 0; i < n; ++i) {
            cin>>A[i];
        }
        set<int> s;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if(A[i]!=A[j] && abs(A[i])==abs(A[j]))
                   s.insert(abs(A[i]));
            }
        }
        if(s.empty())
            cout<<"0";
        for (auto it=s.begin();it!=s.end();it++){
            cout<<-1*(*it)<<" "<<*it<<" ";
        }
        cout<<endl;
    }
}


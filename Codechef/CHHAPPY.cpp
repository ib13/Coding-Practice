//Solved
#include<iostream>
#include <set>
#include <vector>
#include<map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
        int flag=0;
        map<int,vector<int>> m;
        for (int i = 0; i < n; ++i) {
            m[A[i]].push_back(i+1);
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(flag==1)
                break;
            if(it->second.size()>1)
            {
                int count=0;
                for (int i = 0; i < (it->second).size(); ++i) {
                    if(m[(it->second)[i]].size()>0)
                        count++;
                }
                if(count>=2)
                    flag=1;
            }
        }

        if(flag==1)
            cout<<"Truly Happy"<<endl;
        else
            cout<<"Poor Chef"<<endl;
    }
    return 0;
}


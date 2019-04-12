//Use sum formula
#include<iostream>
#include<map>
#include<vector>
#include <algorithm>

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
        long n,k,x;
        cin>>n>>k>>x;
//        k=min(k,20000);
        long num;
//        map<long,int> m1;
        vector<long> v1;
        long long sum=0;
        for(long i=0;i<k;i++)
        {
            cin>>num;
            v1.push_back(num);
//            m1[num]=1;
            sum+=num;
        }
        sort(v1.begin(),v1.end());
        long big=x+v1[0];
        long temp=n-k;
        long n1=v1.size()-1;
        while(temp>0)
        {
            if(v1[n1]<big)
            {
                sum+=big;
                temp--;
                big--;
            }
            else if(v1[n1]>=big)
            {
                n1--;
                big--;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}

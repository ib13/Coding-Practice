//https://practice.geeksforgeeks.org/problems/check-if-array-contains-contiguous-integers-with-duplicates-allowed/0
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
        int num;
        set<int> s;
        for (int i = 0; i < n; ++i)
        {
            cin>>num;
            s.insert(num);
        }
        auto temp=s.begin();
        temp++;
        int flag=0;
        for (auto it = s.begin(); it!=(--s.end()); it++)
        {
            if(abs((*temp)-(*it))!=1)
                flag=1;
            temp++;

        }
        if(flag==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

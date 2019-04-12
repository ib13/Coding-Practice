#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    multiset<int> s;
    int num,n;
    cin>>n;
    multiset<int>:: iterator it;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        s.insert(num);
        it=s.begin();
        if(s.size()%2==0)
        {
            for(int j=0;j<(i/2);j++)
            {
                it++;
            }
            int a=*it;
            it++;
            cout<<(a+(*it))/2;
        }
        else
        {
            for(int j=0;j<(i/2);j++)
            {
                it++;
            }
            cout<<*it;
        }
        cout<<"\n";
    }
    return 0;
}


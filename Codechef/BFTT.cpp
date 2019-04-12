#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int alt;
        int count=0;
        while(1)
        {
            count=0;
            n++;
            alt=n;
            while(alt>0)
            {
                if((alt%10)==3)
                    count++;
                alt=alt/10;
            }
            if(count>=3)
            {
                cout<<n<<"\n";
                break;
            }
        }
    }
}
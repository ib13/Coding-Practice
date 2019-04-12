//Solved
#include<iostream>
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
        int x=1;
        int y=2;
        for (int i = 1; i < n; ++i)
        {
            if(i%2==0)
            {
                x=x*2+1;
                y=y*2;
            }
            else
            {
                x=x*2-1;
                y=y*2;
            }
        }
        cout<<x<<" "<<y<<" ";
    }
    return 0;
}

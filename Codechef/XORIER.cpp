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
        int A[n];
        for(int i=0;i<n;i++)
            cin>>A[i];
        sort(A,A+n);
        int count=0;
        int even=0,odd=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]%2==0)
                even++;
            else
                odd++;
        }

//        for(int i=0;i<n;i++)
//        {
//            for(int j=i+1;j<n;j++)
//            {
//                int x=A[i]^A[j];
//                if(x<=3)
//                {}
//                else if(x%2==0)
//                {
//                    count++;
//                }
//            }
//        }
        count=((n*(n-1))/2)-(even*odd);
        vector<int>ev;
        vector<int>ov;
        for(int i=0;i<n;i++)
        {
            if(A[i]%2==0)
                ev.push_back(A[i]);
            else
                ov.push_back(A[i]);
        }
        for(int i=0;i<ev.size()-1;i++)
        {
            if((ev[i]^ev[i+1])<=3)
            {
//                cout<<ev[i]<<" ";
                count--;
            }


        }
        for(int i=0;i<ov.size()-1;i++)
        {
            if((ov[i]^ov[i+1])<=3)
            {
//                cout<<ov[i]<<" ";
                count--;
            }
        }

        cout<<count<<endl;
    }
    return 0;
}


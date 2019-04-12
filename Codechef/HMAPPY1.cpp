//Unsolved
#include<iostream>
using namespace std;

void trivial_solution(int n,int q,int k,int A[],string str)
{
    for (int i = 0; i < q; ++i) {
        if(str[i]=='!')
        {
            int temp=A[n-1];
            for (int j = n-1; j > 0; --j) {
                A[j]=A[j-1];
            }
            A[0]=temp;
//                for (int j = 0; j < n; ++j) {
//                    cout<<A[j];
//                }
//                cout<<endl;
        }
        if(str[i]=='?')
        {
            int count=0;
            int maxcount=0;
            for (int j = 0; j < n; ++j) {
                if(A[j]==1)
                    count++;
                else
                    count=0;
                maxcount=max(maxcount,count);
            }
            cout<<min(maxcount,k)<<endl;
        }
    }
}

void optimized_solution(int n,int q,int k,int A[],string str)
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
//    cin>>t;
    while(t--)
    {
        int n,q,k;
        cin>>n>>q>>k;
        int A[n];
        string str;
        for (int i = 0; i < n; ++i) {
            cin>>A[i];
        }
        cin>>str;
        trivial_solution(n,q,k,A,str);
    }
    return 0;
}

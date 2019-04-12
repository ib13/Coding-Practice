//https://practice.geeksforgeeks.org/problems/closest-palindrome/0
//Time limit exceed
#include <cmath>
#include <iostream>

using namespace std;

bool palindrome(int num)
{
//    cout<<"Entered";
    int num_copy=num;
    int length=0;
    while(num_copy>0)
    {
        num_copy=num_copy/10;
        length++;
    }
    int A[length];
    num_copy=num;
    for(int i=length-1;i>=0;i--)
    {
        A[i]=num_copy%10;
        num_copy=num_copy/10;
    }
    int i=0;
    int j=length-1;
    while(i<j)
    {
        if(A[i]!=A[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int n_copy=n;
        int length=0;
        while(n_copy>0)
        {
            n_copy=n_copy/10;
            length++;
        }
        int A[length];
        n_copy=n;
        for(int i=length-1;i>=0;i--)
        {
            A[i]=n_copy%10;
            n_copy=n_copy/10;
        }
        int B[length];
        if(length%2==0)
        {
            for(int i=0;i<length/2;i++)
            {
                B[i]=A[i];
            }
            for(int i=length/2;i<length;i++)
            {
                B[i]=A[length-i-1];
            }
        }
        else
        {
            for(int i=0;i<length/2;i++)
            {
                B[i]=A[i];
            }
            B[length/2]=A[length/2];
            for(int i=length/2+1;i<length;i++)
            {
                B[i]=A[length-i-1];
            }
        }
//        for(int i=0;i<length;i++)
//        {
//            cout<<B[i];
//        }
        int m=0;
        for(int i=0;i<length;i++)
        {
            m=m + (B[i] * (int)pow(10, (length - i - 1)));
        }
        // cout<<m;
        if (m<n)
        {
//            cout<<"Entered";
            for(int i=n;i<n+(n-m);i++)
            {
                if(palindrome(i))
                {
                    m=i;
                    break;
                }
            }
        }
        else if (m>n)
        {
            for(int i=n;i>=n-(m-n);i--)
            {
                if(palindrome(i))
                {
                    m=i;
                    break;
                }
            }
        }
        cout<<m;
        cout<<endl;
    }
}
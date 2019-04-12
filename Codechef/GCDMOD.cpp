//      https://discuss.codechef.com/questions/133450/how-i-solved-gcdmod
#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

long long prod(long long a, long long b, long long mod = MOD)
{
    long long res = 0;

    while(b)
    {
        if(b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;

        b >>= 1;
    }

    return res;
}

long long bpow(long long a, long long b, long long mod = MOD)
{
    long long res = 1;

    while(b)
    {
        if(b & 1)
            res = prod(res, a, mod);
        a = prod(a, a, mod);

        b >>= 1;
    }

    return res;
}

void solve()
{
    long long a, b, n;

    cin >> a >> b >> n;

    if(a == b)
    {
        cout << (bpow(a, n) + bpow(b, n)) % MOD << '\n';
    }else
    {
        long long d = (bpow(a, n, a - b) + bpow(b, n, a - b)) % (a - b);

        cout << __gcd(d, a - b) << '\n';
    }
}

int main()
{
    int t;
    cin >> t;

    while(t --> 0)
        solve();

    return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//#define lli long long int
//#define mod 1000000007
//
//lli GCD(lli a,lli b)
//{
//    lli m;
//    if(a>b)
//        m=b;
//    else
//        m=a;
//    for(lli i=m;i>0;i--)
//    {
//        if(a%i==0 && b%i==0)
//            return i;
//    }
//    return a;
//}
//
//lli find_power(lli num,lli n)
//{
//    lli result=1;
//    for(int i=0;i<n;i++)
//    {
//        result=((result%mod)*(num%mod))%mod;
//    }
//    return result;
//}
//
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        lli A,B,N;
//        cin>>A>>B>>N;
//        if(A==B)
//            cout<<(find_power(A,N)+find_power(B,N))%mod;
//        else
//        cout<<(__gcd(find_power(A,N)+find_power(B,N),abs(A-B)))%mod<<"\n";
//    }
//}
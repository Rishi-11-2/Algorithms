#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
long long binpow(long long a,long long b,long long mod)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b=b>>1;
    }
    return res;
}
void solve()
{
    long long p=(long long)(1e9)+7; // must be a prime number!
    long long g=getRandomNumber(1,(int)(1e6)); // mutually agreed upon by Alice and Bob

    long long a=4; // alice's private key

    long long b=3; // bob's private key

    long long x=binpow(g,a,p); // secret key generated for ALice

    long long y=binpow(g,b,p);  // secret key generated for bob


    long long rx=binpow(y,a,p);  // retrieved secret key for alice

    long long ry=binpow(x,b,p); // retrieved secret key for bob

    cout<<"Retrieved Secret Key for Alice is-> "<<rx<<endl;
    cout<<"Retrieved Secret Key for Bob is-> "<<rx<<endl;
}
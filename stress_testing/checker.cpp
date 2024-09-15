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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
int solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
int solve()
{
    ifstream fin("input_file",ifstream::in);
    ifstream ans("myAnswer",ifstream::in);
    ifstream cor("correctAnswer",ifstream::in);
    long long n;

    fin>>n;

    long long arr[n];
    for(long long i=0;i<n;i++)
    fin>>arr[i];
    
    int bruteAnswer,optimalAnswer;

    ans>>optimalAnswer;

    cor>>bruteAnswer;

    if(optimalAnswer!=bruteAnswer)
    {
        cout<<"Wrong Answer!!"<<endl;
        return -1;
    }
    else
    {
        cout<<"Testcase Passes!!"<<endl;
    }
    return 0;
}
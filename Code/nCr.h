#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
vector<long long> fact(N, 0);
vector<long long> inv(N, 0);
const long long mod = 1000000007;

long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
void compute(int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
    }
    for (int i = 0; i <= n; i++)
    {
        // cout << fact[i] << endl;
        inv[i] = power(fact[i], mod - 2, mod);
        // cout << inv[i] << endl;
    }
}
long long nCr(int n, int r)
{
    return (fact[n] % mod * inv[n - r] % mod * inv[r] % mod) % mod;
}
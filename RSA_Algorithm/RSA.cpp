//https://brilliant.org/wiki/rsa-encryption/
class RSA{
    public:
    string s;
    long long e;
    long long d;
    long long mod;
    RSA(string &a)
    {
        s=a;
        build();
    }
    long long extended_gcd(long long a,long long b,long long &x,long long &y)
    {
        if(b==0)
        {
            x=1;
            y=0;
            return a;
        }
        long long x1;
        long long y1;
        long long g=extended_gcd(b,a%b,x1,y1);
        x=y1;
        y=x1-(a/b)*y1;
        return g;
    }
    long long mod_inverse(long long a,long long mod)
    {
        long long x,y;
        long long g=extended_gcd(a,mod,x,y);
        long long ans=(x%mod+mod)%mod;
        return ans;
    }
    long long binpow(long long a,long long b,long long mod)
    {
        long long res=1;
        a=a%mod;
        while(b>0)
        {
            if(b&(1LL))
            {
                res=(res%mod*a%mod)%mod;
                // debug(res,a);
            }
            a=(a%mod*a%mod)%mod;
            b=b>>1LL;
        }
        return res;
    }
    void build()
    {
        long long p=999999733;
        long long q=2;
        long long phi=(p-1)*(q-1);
        long long n=p*q;
        mod=n;
        e=(1LL<<16)+1;// also chosen as 3 in some cases
        d=mod_inverse(e,phi);
    }

    long long encrypt(long long num)
    {
        return binpow(num,e,mod);
    }
    long long decrypt(long long num)
    {
        return binpow(num,d,mod);
    }
};

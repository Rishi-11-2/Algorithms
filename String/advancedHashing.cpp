const long long mod1=(long long)(1e9+7);
const long long mod2=(long long)(1e9+1);
const long long mod3=(long long)(1e15+5);
const long long p1=uniform_int_distribution<long long>(0,mod1-1)(rng);
const long long p2=uniform_int_distribution<long long>(0,mod2-1)(rng);
const long long p3=uniform_int_distribution<long long>(0,mod3-1)(rng);
struct Hash{

    long long *pref1;
    // vector<long long>hash;
    long long *base_pow1;
    long long *base_pow2;
    long long *pref2;
    string s;
    long long n;
    Hash(const string &a)
    {
        s=a;
        n=s.length();
        pref1=(long long*)(malloc((n+1)*sizeof(long long)));
        pref2=(long long*)(malloc((n+1)*sizeof(long long)));
        base_pow1=(long long*)(malloc((n+1)*sizeof(long long)));
        base_pow2=(long long*)(malloc((n+1)*sizeof(long long)));
        base_pow1[0]=1;
        base_pow2[0]=1;
        pref1[0]=1;
        pref2[0]=1;
        for(long long i=1;i<=n;i++)
        {
            base_pow1[i]=(p1*base_pow1[i-1])%mod1;
            base_pow2[i]=(p2*base_pow2[i-1])%mod2;
            pref1[i]=((pref1[i-1]*p1)%mod1+s[i-1]+997)%mod1;
            pref2[i]=((pref2[i-1]*p2)%mod2+s[i-1]+997)%mod2;
        }
    }

    long long get_hash(long long l,long long r)
    {
        long long h1=pref1[r+1]-(pref1[l]*base_pow1[r-l+1])%mod1;
        long long h2=pref2[r+1]-(pref2[l]*base_pow2[r-l+1])%mod2;
        if(h1<0)
        h1+=mod1;
        
        if(h2<0)
        h2+=mod2;
        long long h3=(h1*p1)%mod3;
        h3=(h3+h2)%mod3;
        return h3;
    }

};
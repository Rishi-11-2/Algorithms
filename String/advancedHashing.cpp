const long long mod1=(long long)(1e9+7);
const long long mod2=(long long)(1e9+1);
const long long mod3=(long long)(1e15+5);
const long long p1=uniform_int_distribution<long long>(0,mod1-1)(rng);
const long long p2=uniform_int_distribution<long long>(0,mod2-1)(rng);
const long long p3=999119999;
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



    /*  pref[r+1]=( p^(r+1) + a[0]*p^(r) + a[1]*p^(r-1) + a[2]*p^(r-2) + ..+ a[l-1]*p^((r+1)-(l-1+1))+a[l]*p^((r+1)-(l+1))  .. a[r-1]*p + a[r] )
        pref[l]=( p^l + a[0]*p^(l-1) + a[1]*p^(l-2) + a[2]*p^(l-3) + ...a[l-2]*p +  a[l-1])
        p^(r-l+1)*pref[l] = ( p^(r+1)+ a[0]*p^(r) + a[1]*p^(r-1) +.... + a[l-1]*p^(r-l+1) )
        pref[r+1]-pref[l]=a[l]*p^(r-l)+ a[l+1]*p^(r-l-1)+.... + a[r-1]*p + a[r]
    */
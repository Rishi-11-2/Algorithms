class Set_Hash{
    private:
    const long long mod1=999999937;
    const long long mod2=999999929;
    const long long k1=(long long)(1e7)+1;
    const long long k2=(long long)(1e5)+3;
    const long long h1=37;
    const long long h2=41;
    long long binpow(long long a,long long b,long long mod)
    {
        long long res=1;
        while(b>0)
        {
            if(b&(1LL))
            {
                res=((res)*(a))%mod;
            }
            a=(a%mod*a%mod)%mod;
            b>>=1LL;
        }
        return res;
    }
    public:
    long long n;
    vector<long long>arr;
    vector<long long>hash1,hash2;
    Set_Hash(vector<long long>&v)
    {
        n=(long long)v.size();
        arr=v;
        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        build();
    }
    void build()
    {
        for(long long i=1;i<=n;i++)
        {
            hash1[i]=binpow((arr[i-1]+k1),h1,mod1);
            hash1[i]=(hash1[i]+hash1[i-1])%mod1;
            hash2[i]=binpow((arr[i-1]+k2),h2,mod2);
            hash2[i]=(hash2[i]+hash2[i-1])%mod2;
        }
    }

    pair<long long,long long>getHash(long long l,long long r)
    {
        // 1 based indexing
        long long ans1=hash1[r];
        long long ans2=hash2[r];
        ans1-=hash1[l-1];
        ans2-=hash2[l-1];

        ans1=(ans1%mod1+mod1)%mod1;
        ans2=(ans2%mod2+mod2)%mod2;

        return make_pair(ans1,ans2);
    }
};
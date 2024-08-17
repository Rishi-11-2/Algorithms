class Hash{
    private:
    const long long mod1=(long long)(1e9)+7;
    const long long mod2=(long long)(1e9)+1;
    const long long mod3=(long long)(1e15)+5;
    
    const long long p1=1001;
    const long long p2=1003;
    
    const long long p3=99911;
    
    public:
    vector<long long>pref1;
    vector<long long>pref2;
    vector<long long>base_pow1;
    vector<long long>base_pow2;    
    string s;
    long long n;
    
    Hash(const string &a)
    {
        s=a;
        n=s.length()+10;
        pref1.assign(n+1,0);
        pref2.assign(n+1,0);
        base_pow1.assign(n+1,0);
        base_pow2.assign(n+1,0);
        build();
    }
    void build()
    {
        base_pow1[0]=1;
        
        base_pow2[0]=1;
        pref1[0]=1;
        pref2[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            base_pow1[i]=(base_pow1[i-1]*p1)%mod1;
            base_pow2[i]=(base_pow2[i-1]*p2)%mod2;
            
            pref1[i]=((pref1[i-1]*p1)%mod1+s[i-1]+997)%mod1;
            
            pref2[i]=((pref2[i-1]*p2)%mod2+s[i-1]+997)%mod2;
        }
        
    }
    
    long long getHash(int l,int r)
    {
        long long h1=pref1[r+1];
        
        h1-=(pref1[l]*base_pow1[r-l+1])%mod1;
        h1=(h1%mod1+mod1)%mod1;
        
        long long h2=pref2[r+1];
        
        h2-=(pref2[l]*base_pow2[r-l+1])%mod2;
        
        h2=(h2%mod2+mod2)%mod2;
        
        long long h3=((h1*p3)%mod3+h2)%mod3;
        
        return h3;
    }
};


    /*  pref[r+1]=( p^(r+1) + a[0]*p^(r) + a[1]*p^(r-1) + a[2]*p^(r-2) + ..+ a[l-1]*p^((r+1)-(l-1+1))+a[l]*p^((r+1)-(l+1))  .. a[r-1]*p + a[r] )
        pref[l]=( p^l + a[0]*p^(l-1) + a[1]*p^(l-2) + a[2]*p^(l-3) + ...a[l-2]*p +  a[l-1])
        p^(r-l+1)*pref[l] = ( p^(r+1)+ a[0]*p^(r) + a[1]*p^(r-1) +.... + a[l-1]*p^(r-l+1) )
        pref[r+1]-pref[l]=a[l]*p^(r-l)+ a[l+1]*p^(r-l-1)+.... + a[r-1]*p + a[r]
    */
  long long binpow(long long a,long long  b,long long mod)
  {
     long long res=1;
     while(b>0)
      {
        if(b&1)
        {
           res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b=b>>1LL;
      }
  return res;
  }
  long long inverse(long long n,long long mod)
   {
      return binpow(n,mod-2,mod);
   }
  class Hashing{
    public:
       string s;
       long long n;
       long long primes;
       vector<long long> hashPrimes = {1000000009, 100000007};
       const long long base = 1001;
       vector<vector<long long>> hashValues;
       vector<vector<long long>> powersOfBase;
       vector<vector<long long>> inversePowersOfBase;
       Hashing(string a){
            primes = (long long)(hashPrimes.size());
            hashValues.resize(primes);
            powersOfBase.resize(primes);
            inversePowersOfBase.resize(primes);
            s = a;
            n = s.length();
            for(long long i = 0; i < primes; i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(long long j = 1; j <= n; j++){
                 powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = inverse(powersOfBase[i][n], hashPrimes[i]);
           for(long long j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = ((inversePowersOfBase[i][j + 1]%hashPrimes[i])*(base%hashPrimes[i]))%hashPrimes[i];
           }
       }
       for(long long i = 0; i < primes; i++) {
           hashValues[i].resize(n);
           for(long long j = 0; j < n; j++){
              long long val=(s[j]-'a'+1LL);
               hashValues[i][j] = (val%hashPrimes[i] * powersOfBase[i][j]%hashPrimes[i]) % hashPrimes[i];
               hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
       }
   }
    vector<long long> substringHash(long long l, long long r){
        vector<long long> hash(primes);
        for(long long i = 0; i < primes; i++){
           long long val1 = hashValues[i][r];
           long long val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
           hash[i] = ((val1-val2+hashPrimes[i])%hashPrimes[i]*inversePowersOfBase[i][l]%hashPrimes[i])%hashPrimes[i];
        }
     return hash;
    }
  };
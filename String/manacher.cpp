class Manacher{

    public:

    string t;
    vector<int>p;

    Manacher(string &s)
    {
        for(char c:s)
        {
            t+=string("#",1)+c;
        }
        t+=string("#",1);

        build(t);
    }

    void build(string &s)
    {
        int n=s.length();
        p.assign(n,1);
        int l=1;
        int r=1;
        for(int i=0;i<n;i++)
        {
            if((l+r)-i>=0)
            {
                p[i]=max(0,min(r-i,p[r+l-i]));
            }

            while((i+p[i])<n && (i-p[i])>=0 && s[i+p[i]]==s[i-p[i]])
            {
                p[i]++;
            }
            if((i+p[i])>r)
            {
                l=i-p[i];
                r=i+p[i];
            }
        }
    }

    int findLongest(int i,int odd)
    {
        int pos=2*i+1+(!odd);
        return p[pos];
    }

    bool isPalindrome(int l,int r)
    {
        int len=r-l+1;
        int center=(r+l)/2;
        int odd=((l%2) == (r%2));
        return (len<=findLongest(center,odd));
    }
};
class LazySegmentTree{

    public:
    vector<long long>tree;
    vector<long long>lazy;
    vector<long long>arr;
    long long n;
    LazySegmentTree(long long nn,vector<long long>&a)
    {
        n=nn;
        tree.resize(4*n);
        lazy.resize(4*n);
        lazy.assign(4*n,0);
        arr=a;
        build(0,n-1,0);
    }
    
    void push(long long ss,long long se,long long si)
    {
        if(lazy[si]==0)
        return;
        tree[si]+=lazy[si]*(se-ss+1);
        if(ss!=se)
        {
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }

    void build(long long ss,long long se,long long si)
    {
        if(ss==se)
        {
            tree[si]=arr[ss];
            return;
        }
        long long mid=(ss+se)/2;
        build(ss,mid,2*si+1);

        build(mid+1,se,2*si+2);

        tree[si]=tree[2*si+1]+tree[2*si+2];
    }

    void update(long long ss,long long se,long long si,long long l,long long r,long long val)
    {
        push(ss,se,si);

        if(se<l || ss>r)
        {
            return;
        }

        if(ss>=l && se<=r)
        {
            lazy[si]=val;
            push(ss,se,si);
            return;
        }

        long long mid=(ss+se)/2;

        update(ss,mid,2*si+1,l,r,val);
        update(mid+1,se,2*si+2,l,r,val);

        tree[si]=tree[2*si+1]+tree[2*si+2];
    }

    long long query(long long ss,long long se,long long si,long long l,long long r)
    {
        push(ss,se,si);
        if(ss>r || se<l)
        return 0;
        
        if(ss>=l && se<=r)
        {
            return tree[si];
        }

        long long mid=(ss+se)/2;
        return query(ss,mid,2*si+1,l,r)+query(mid+1,se,2*si+2,l,r);
    }
    void make_update(long long l,long long r,long long val)
    {
        update(0,n-1,0,l,r,val);
    }
    long long make_query(long long l,long long r)
    {
        return query(0,n-1,0,l,r);
    }
};
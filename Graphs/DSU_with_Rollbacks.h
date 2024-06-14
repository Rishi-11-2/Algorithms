struct node{
    long long u,pu,size_u,v,size_v,pv,n_cc;
    node(long long a,long long b,long long c,long long d,long long e,long long f,long long g)
    {
        u=a;
        pu=b;
        size_u=c;
        v=d;
        pv=e;
        size_v=f;
        n_cc=g;
    }
};
class DSU{

    public:
    vector<long long>size;
    vector<long long>parent;
    vector<node>history;
    long long cc;
    DSU(long long n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        cc=n;
        for(long long i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
        }
    }
    long long findUlp(long long node)
    {
        if(parent[node]==node)
        return node;

        return findUlp(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUlp(u);
        long long ulp_v=findUlp(v);

        if(ulp_u==ulp_v)
        {
            node x(-1,-1,-1,-1,-1,-1,-1);
            history.push_back(x);
            return;
        }
        
        node x(ulp_u,ulp_u,size[ulp_u],ulp_v,ulp_v,size[ulp_v],cc);
        history.push_back(x);
        cc--;
        if(size[ulp_u]>size[ulp_v])
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        else{
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }

    void rollback(long long idx)
    {
        while((long long)history.size()>idx)
        {
            auto it=history.back();
            history.pop_back();
            if(it.u==-1)
            continue;
            long long u=it.u;
            long long pu=it.pu;
            long long size_u=it.size_u;
            long long v=it.v;
            long long pv=it.pv;
            long long size_v=it.size_v;

            cc=it.n_cc;
            size[u]=size_u;
            size[v]=size_v;
            parent[u]=pu;
            parent[v]=pv;
        }
    }


};
class SegmentTree{
    public:
    vector<vector<int>>tree;
    vector<int >arr;
    int  n;
    SegmentTree(vector<int >&v)
    {
        n=(int )v.size();
        arr=v;
        int  s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
        tree.resize(s);
        build(0,n-1,0);
    }
    void build(int  ss,int  se,int  si)
    {
        if(ss==se)
        {
            tree[si].push_back(arr[se]);
            return ;
        }
        int  mid=(ss+se)/2;
        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);
        merge(tree[2 * si+1].begin(), 
        tree[2 *si+1].end(),
        tree[2 *si + 2].begin(), 
        tree[2 *si + 2].end(),
        back_inserter(tree[si]));
        
    }
    // find the number of elements strictly larger than x in the range [l,r]
    // for the number of elements larger than x in the range [l,r] us lower_bound
    int  query1(int  ss,int  se,int  si,int  l,int  r,int  x)
    {
        if(ss>r || se<l)
        return 0;
        
        if(ss>=l && se<=r)
        {
            int  ans=upper_bound(tree[si].begin(),tree[si].end(), x)-tree[si].begin();;
            int  sz=se-ss+1;
            ans=sz-ans;
            return ans;
        }

        int  mid=(ss+se)/2;
        return query1(ss,mid,2*si+1,l,r,x)+query1(mid+1,se,2*si+2,l,r,x);
    }
    int  query2(int  ss,int  se,int  si,int  l,int  r,int  x) // find the number of elements smaller than x in range [l,r] 
    // for elements strictly smaller than x in the range [l,r] use lower_bound
    {
        if(ss>r || se<l)
        return 0;
        
        if(ss>=l && se<=r)
        {
                int  ans=upper_bound(tree[si].begin(),tree[si].end(), x)-tree[si].begin();;            
                return ans;
        }

        int  mid=(ss+se)/2;
        return query2(ss,mid,2*si+1,l,r,x)+query2(mid+1,se,2*si+2,l,r,x);
    }
    int  make_query1(int  l,int  r,int  x)
    {
        return query1(0,n-1,0,l,r,x);
    }
    int  make_query2(int  l,int  r,int  x)
    {
        return query2(0,n-1,0,l,r,x);
    }

};
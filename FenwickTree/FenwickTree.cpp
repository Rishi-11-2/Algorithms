class FenwickTree{

    public:
    vector<int>bit;
    int n;
    vector<int>arr;
    FenwickTree(vector<int>&a)
    {
        n=(int)(a.size())+1;
        bit.assign(n+1,0);
        arr=a;
        build();
    }

    void build()
    {
        for(int i=0;i<n;i++)
        {
            update(i,arr[i]);
        }
    }

    void update(int i,int x)
    {
        i++;
        while(i<n)
        {
            bit[i]+=x;
            i+=(i&-i);// finding the lowest one bit 
        }
    }

    int sum(int i)// finds sum in  the range (0,i)
    {
        int s=0;
        i++;
        while(i>0)
        {
            s+=bit[i];
            i-=(i&-i); // finding the lowest one bit 
        }
        return s;
    }
    int range_sum(int l,int r)
    {
        return sum(r)-sum(l-1);
    }
};
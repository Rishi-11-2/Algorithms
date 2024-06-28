#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
        solve();
}
struct Point{
    double x,y;
    Point(double a,double b):x(a),y(b){}

    bool operator == (const Point &t)const{
        return t.x==x && y==t.y;
    }
};

int orientation( const Point &a, const Point &b,const Point &c)
{
    /*
    Line Segment P : a->b
    Line Segment Q : a->c
    */
    int px=b.x-a.x; // a1
    int py=b.y-a.y; // a2

    int qx=c.x-a.x; // b1
    int qy=c.y-a.y; // b2

    int o= px*qy- py*qx;

    if(o>0)
    return 1; // for clockwise
    else if(o<0)
    return -1 ;  // for anticlockwise
    return 0; 
}
bool collinear(const Point &a,const Point &b ,const Point &c)
{
    int o=orientation(a,b,c);

    return (o==0);
}
bool f(const Point &a ,const Point &b,const Point &c,bool include_colinear)
{
    int o=orientation(a,b,c);

    if(o<0)
    return true;
    
    if(o>0)
    return false;
    if(o==0 && include_colinear)
    return false;

    return true;
    
}
// convex hull using graham's scan
void solve()
{
    int n;
    cin>>n;

    vector<Point>points;

    for(int i=0;i<n;i++)
    {
        double x,y;
        cin>>x>>y;
        Point a(x,y);

        points.push_back(a);
    }

    bool include_colinear=false;
    Point origin=*min_element(all(points),[](Point a, Point b){
        return make_pair(a.y,a.x)<make_pair(b.y,b.x);
    });


    sort(all(points),[&origin](const Point&a,const Point &b){
        int o=orientation(origin,a,b);

        if(o==0)
        return ((a.x-origin.x)*(a.x-origin.x)+ (a.y-origin.y)*(a.y-origin.y)) < ((b.x-origin.x)*(b.x-origin.x)+(b.y-origin.y)*(b.y-origin.y));
        return o>0;
    });



    // debug("hi");

    // for(auto it:points)
    // {
    //     cout<<it.x<<" "<<it.y<<endl;
    // }
    if(include_colinear)
    {
        int i=(points.size())-1;

        while(i>=0 && collinear(origin,points[i],points.back()))
        {
            i--;
        }
        reverse(points.begin()+i+1,points.end()); 
    }

    vector<Point>res;

    for(int i=0;i<n;i++)
    {
        int m=(int)res.size();
        while(m>1 && f(res[m-2],res[m-1],points[i],include_colinear))
        {
            res.pop_back();
            m=(int)(res.size());
        }
        res.push_back(points[i]);
    }

    for(auto it:res)
    {
        cout<<it.x<<" "<<it.y<<endl;
    }
}
/* Priyansh Agarwal*/
#pragma GCC optimize("O3,unroll-loops")
 
#include<bits/stdc++.h>

// import libraries
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;

// using namespace
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void solve(){
    
    pbds A;
    
    vector<int> arr = {1, 2, 3, 4, 5, -1, -1, -2};
    int n = 8, k = 5;
    
    vector<int> ans(n - k + 1);
    
    // first window
    for(int i = 0; i < k; i++){ // O(k)
        A.insert({arr[i], i});
    }
    
    pair<int, int> median = *A.find_by_order(k / 2);
    ans[0] = median.first;
    int count = 1;
    for(int right = k; right < n; right++){ // O(n)
        // insert current element
        
        A.insert({arr[right], right});
        
        pair<int, int> toRemove = {arr[right - k], right - k};
        A.erase(toRemove);
        
        median = *A.find_by_order(k / 2);
        ans[count] = median.first;
        count++;
    }
    for(auto i : ans){
        cout << i << " ";
    }
}
 
int main() {
#ifdef Priyansh31dec
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Priyansh31dec
    cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
}
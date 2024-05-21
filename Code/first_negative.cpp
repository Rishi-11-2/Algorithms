/* Priyansh Agarwal*/
#pragma GCC optimize("O3,unroll-loops")
 
#include<bits/stdc++.h>
 
using namespace std;
using namespace chrono;

void solve(){
    
    vector<int> arr = {-1, -2, 4, 5, -3, 0, 2};
    int n = 7, k = 3;
    
    vector<int> ans(n - k + 1);
    
    set<int> negatives;
    
    // first window
    for(int i = 0; i < k; i++){ // O(k)
        if(arr[i] < 0){
            negatives.insert(i); // O(logk)
        }
    }
    
    // {}
    
    ans[0] = *negatives.begin();
    int count = 1;
    
    for(int right = k; right < n; right++){ // O(n)
        // insert current element
        
        // O(logk)
        if(arr[right] < 0){
            negatives.insert(right);
        }
        
        // remove last element
        if(arr[right - k] < 0){
            negatives.erase(right - k);
        }
        
        ans[count] = *negatives.begin();
        count++;
    }
    
    // O(n*logk)
    
    for(auto i : ans){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
int main() {
    solve();
}
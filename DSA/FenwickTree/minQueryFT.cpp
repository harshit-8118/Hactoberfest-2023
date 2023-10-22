#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE    
// #include "Algo/debug.h"   
// #else
// #define fix(x)
// #endif

class fenwickTree{
    public:
    vector<int> bit; int n;
    fenwickTree(int n){
        this->n = n;
        bit.assign(n, INT_MAX);
    }
    fenwickTree(vector<int> &a): fenwickTree(a.size()){
        for (int i = 0; i < a.size(); i++)
            update(i, a[i]);        
    }
    void update(int idx, int val){
        for(; idx < n; idx = (idx | (idx+1)))
            bit[idx] = min(bit[idx], val);
    }
    int getMin(int r){
        int res = INT_MAX;
        while(r >= 0){
            res = min(res, bit[r]);
            r = (r & (r+1))-1;
        }return res;
    }
};

int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     #include "Algo/config.h"
// #endif

int n; cin>>n; 
vector<int> arr(n);
for(auto &x: arr) cin>>x;
fix(arr);
fenwickTree ft(arr);
fix(ft.bit);
int q,r ; cin>>q;
while(q--){
    cin>>r;
    cout<<ft.getMin(r)<<endl;
}

return 0;
}
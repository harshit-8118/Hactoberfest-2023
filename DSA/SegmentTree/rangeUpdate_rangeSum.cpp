#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE     // #include "C://Users//hhars//OneDrive//Documents//CPP Practice//Algo//config.h"
// #include "Algo/debug.h"   // include definitions
// #else
// #define fix(x)
// #endif

vector<int> t, lazy, arr;  
int build(int i, int tl, int tr){
    if(tl == tr) return t[i] = arr[tl];
    else{
        int tm = (tl + tr)/2;
        return t[i] = build(i*2, tl, tm) + build(i*2+1, tm+1, tr);
    }
}
int range_update(int i, int tl, int tr, int l, int r, int val){
    if(tl > r || tr < l) return t[i];
    if(lazy[i] != 0){
        t[i] += (tr - tl + 1) * lazy[i];
        if(tl != tr){
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        } lazy[i] = 0;
    }
    if(tl >= l and tr <= r){
        t[i] += (tr - tl + 1) * val;
        if(tl != tr){ lazy[i*2] += val; lazy[i*2+1] += val;}
        return t[i];
    }
    int tm = (tl + tr)/2;
    return t[i] = range_update(i*2, tl, tm, l, r, val) + range_update(i*2+1, tm+1, tr, l, r, val);
}

int range_query(int i, int tl, int tr, int l, int r){
    if(tl > r || tr < l) return 0;
    if(lazy[i] != 0){
        t[i] += (tr - tl + 1) * lazy[i];
        if(tl != tr){
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        } lazy[i] = 0;
    }
    if(tl >= l and tr <= r){
        return t[i];
    }
    int tm = (tl + tr)/2;
    return range_query(2*i, tl, tm, l, r) + range_query(i*2+1, tm+1, tr, l, r);
}

int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     #include "Algo/config.h"
// #endif

int n; cin>>n;
t = lazy = vector<int>(n*4);
arr = vector<int>(n);
for(auto &x: arr) cin>>x;
build(1, 0, n-1);

// fix(t);
// range_update(1, 0, n-1, 2, 4, 4);
// fix(lazy);
// range_update(1, 0, n-1, 3, 6, 2);
// fix(t);
// fix(lazy);

int q, l, r, val,x;
cin>>q;
while(q--){
    cin>>x;
    if(x == 1){
        cin>>l>>r;
        int ans = range_query(1, 0, n-1, l, r);
        cout<<ans<<endl;
    }else{
        cin>>l>>r>>val;
        range_update(1, 0, n-1, l, r, val);
    }
}

return 0;
}
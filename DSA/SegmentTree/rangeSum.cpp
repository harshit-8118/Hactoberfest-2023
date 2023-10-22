#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE
// #include "..\Algo\debug.h"   // include definitions
// #else
// #define //fix(x)
// #endif

int n;
vector<int> arr;
vector<int> t;

int operation(int a, int b){
    return a + b;
}
void buildST(int v, int tl, int tr){
    if(tl == tr){
        t[v] = arr[tl];
    }else{
        int tm = (tl + tr) / 2;
        buildST(v*2, tl, tm);
        buildST(v*2+1, tm+1, tr);
        t[v] = operation(t[v*2], t[v*2+1]);
    }
}

int get_query(int v, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }if(tl == l and tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return operation(get_query(v*2, tl, tm, l, min(tm, r)), get_query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int update(int v, int tl, int tr, int pos, int nval){
    if(tl == tr){
        t[v] = nval;
    }else{
        int tm = (tl + tr) / 2;
        if(tm >= pos)
        update(v*2, tl, tm, pos, nval);
        else
        update(v*2+1, tm+1, tr, pos, nval);
        t[v] = operation(t[v*2], t[v*2+1]);
    }
}

int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     #include "..\Algo\config.h"
// #endif

int pos, nval, q, l, r;
cin>>n;
arr = vector<int>(n);
t = vector<int>(4*n);
for(auto &x : arr){
    cin>>x;
}
buildST(1, 0, n-1);
cin>>q;
while(q--){
    cin>>l>>r;
    int ans = get_query(1, 0, n-1, l, r);
    cout<<ans<<endl;
}
cin>>pos>>nval;
arr[pos] = nval;
update(1, 0, n-1, pos, nval);
// can further search for queries

return 0;
}
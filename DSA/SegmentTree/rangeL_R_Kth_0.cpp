#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE     
// #include "C://Users//hhars//OneDrive//Documents//CPP Practice//Algo/debug.h"   // include definitions
// #else
// #define fix(x)
// #endif

int n;
vector<int> arr;
vector<int> t;

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = (arr[tl] == 0);
    }else{
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int get_query(int v, int tl, int tr, int kth_0){
    if(t[v] < kth_0){
        return -1;
    }if(tl == tr){
        return tl;
    }
    int tm = (tl + tr)/2;
    if(t[v*2] >= kth_0){
        return get_query(v*2, tl, tm, kth_0);
    }else{
        return get_query(v*2+1, tm+1, tr, kth_0 - t[v*2]);
    }
}

int getNumof0inLR(int v, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }if(tl == tr){
        return t[v];
    }
    int tm = (tl + tr)/2;
    return getNumof0inLR(v*2, tl, tm, l, min(r, tm)) + getNumof0inLR(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int nval){
    if(tl == tr){
        t[v] = (nval == 0);
    }else{
        int tm = (tl + tr) / 2;
        if(tm >= pos){
            update(v*2, tl, tm, pos, nval);
        }else{
            update(v*2+1, tm+1, tr, pos, nval);
        }
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     #include "C://Users//hhars//OneDrive//Documents//CPP Practice//Algo/config.h"   // include definitions
// #endif

cin>>n;
arr = vector<int>(n);
t = vector<int>(4*n);

for(auto &x: arr){ cin>>x; }

int pos, nval, kth, q, x, l, r;
build(1, 0, n-1);
cin>>q;
while(q > 0){
    cin>>x;
    if(x == 1){
        cin>>pos>>nval;
        update(1, 0, n-1, pos, nval);
        arr[pos] = nval;
        // fix(arr);
    }else if(x == 2){
        cin>>kth;       // take care of kth == 0
        int ans = get_query(1, 0, n-1, kth);
        cout<<"=> "<<ans<<endl;
    }else{
        cin>>l>>r;
        int ans = getNumof0inLR(1, 0, n-1, l, r);
        cout<<"=> "<<ans<<endl;
    }
    q--;
}

return 0;
}
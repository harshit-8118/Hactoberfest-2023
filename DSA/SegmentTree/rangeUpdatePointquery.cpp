#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE     // #include "C://Users//hhars//OneDrive//Documents//CPP Practice//Algo//config.h"
// #include "Algo/debug.h"   // include definitions
// #else
// #define fix(x)
// #endif

vector<int> arr;
class segmentTree{
  public: 
  vector<int> t;
  segmentTree(int n){
    t.resize(4*n);
  }
  template<class T> T operation(T a, T b){ return a + b; } 
  template<class T>  void build(T v, T tl, T tr){
    if(tl == tr){
      t[v] = arr[tl];      return;
    }T tm = (tl + tr)/2;
    build(v*2, tl, tm);     build(v*2+1, tm+1, tr);
    t[v] = 0;
  }
  template<class T>  void update(T v, T tl, T tr, T l, T r, T val){
    if(l > r) return;
    if(tl == l and tr == r){
      t[v] += val; return;
    }T tm = (tl + tr)/2;
    update(v*2, tl, tm, l, min(r, tm), val);
    update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
  }
  template<class T>  T get_query(T v, T tl, T tr, T pos){
    if(tl == tr)      return t[v];
    T tm = (tl + tr)/2;
    if(tm >= pos)
      return t[v] + get_query(v*2, tl, tm, pos);
    else
      return t[v] + get_query(v*2+1, tm+1, tr, pos);
  }
};


int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     #include "Algo/config.h"
// #endif

int n;cin>>n;
segmentTree obj(n);
arr = vector<int>(n);
for(auto &x: arr) cin>>x;
obj.build(1, 0, n-1);

int q, l, r, type, val;
while(q--){
  cin>>type;
  if(type == 1){ 
    cin>>l>>r>>val; r--;
    obj.update(1, 0, n-1, l, r, val);
  }
  else{
    cin>>r;
    int val = obj.get_query(1, 0, n-1, r);
    cout<<val<<" ";
  }
}


return 0;
}
#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE     // #include "C://Users//hhars//OneDrive//Documents//CPP Practice//Algo//config.h"
// #include "Algo/debug.h"   // include definitions
// #else
// #define fix(x)
// #endif

vector<multiset<int>> t;
vector<int> arr;
void build(int i, int tl, int tr){
  if(tl == tr) t[i].insert(arr[tl]);
  else{
    int tm = (tl + tr)/2;
    build(i*2, tl, tm);
    build(i*2+1, tm+1, tr);
    t[i].insert(t[i*2].begin(), t[i*2].end());
    t[i].insert(t[i*2+1].begin(), t[i*2+1].end());
  }
}
void update(int i, int tl, int tr, int p, int val){
  t[i].erase(t[i].find(arr[p]));
  t[i].insert(val);
  if(tl != tr){
    int tm = (tl + tr)/2;
    if(tm >= p)
    update(i*2, tl, tm, p, val);
    else
    update(i*2+1, tm+1, tr, p, val);
  }else{
    arr[p] = val;
  }
}
int query(int i, int tl, int tr, int l, int r, int x){
  if(l > r) return 1e9;
  if(l == tl and r == tr){
    auto p = lower_bound(t[i].begin(), t[i].end(), x);
    if(p != t[i].end()){
      return *p;
    }return 1e9;
  }
  int tm = (tl + tr)/2;
  return min(query(i*2, tl, tm, l, min(r, tm), x), query(i*2+1, tm+1, tr, max(l, tm+1), r, x));
}

int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     #include "Algo/config.h"
// #endif

int n; cin>>n;
arr = vector<int> (n);
t = vector<multiset<int>> (n*4);
for(auto &x: arr) cin>>x;
build(1, 0, n-1);
// fix(t);

int q;cin>>q;
int l,r;
while(q--){
  int x;
  cin>>l>>r>>x;
  int ans = query(1, 0, n-1, l, r, x);
  if(ans == 1e9){
    cout<<-1<<endl;
  }else
  cout<<query(1, 0, n-1, l, r, x)<<endl;
}
update(1, 0, n-1, 3, 1);
update(1, 0, n-1, 4, 2);
cin>>q;
while(q--){
  int x;
  cin>>l>>r>>x;
  int ans = query(1, 0, n-1, l, r, x);
  if(ans == 1e9){
    cout<<-1<<endl;
  }else
  cout<<query(1, 0, n-1, l, r, x)<<endl;
}
return 0;
}
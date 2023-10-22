#include<bits/stdc++.h>
using namespace std;
#define int long long int

pair<int,int> NthFibonacci(int n){
    if(n == 0){
        return {0, 1};
    }
    auto p = NthFibonacci(n>>1);
    int c = p.first * (2*p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if(n&1){
        return {d, c + d};
    }
    else
        return {c, d};
}
int fib(int n){
    return NthFibonacci(n).first;
}

void solve(){
    int a = 7;
    cin>>a;
    // will valid till 90th fibonacci number
    cout<<fib(a)<<endl;
}

signed main(){

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

int tt = 1;     cin>>tt;
while(tt--){
  solve();
}

return 0;
}
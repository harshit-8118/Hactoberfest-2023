#include<bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;

u64 modPow(u64 a, u64 b, u64 p){
   u64 ans = 1;
   while(b != 0){
      if((b&1)){
            ans =  (u128)a * ans %p;
      }
      a = (u128)a * a %p;
      b >>= 1;
   }
   return ans%p;
}

bool FermatsLittle(u64 p, int iter = 5){
    if(p <= 4){
        return p == 2 || p == 3;
    }
    for(int i = 0; i < iter; i++){
        int a = 2 + rand() % (p-3);
        if(modPow(a, p-1, p) != 1){
            return false;
        }
    }
    return true;
}

int main(){

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

int tt; cin>>tt;
while(tt--){
  u64 n;
  cin>>n;
  if(FermatsLittle(n)){
    cout<<"YES"<<endl;
  }else
    cout<<"NO"<<endl;
}

return 0;
}
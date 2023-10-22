// Harshit Shukla
#include<bits/stdc++.h>
using namespace std;

int returnLIS(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    multiset<int> lis;
    for(auto x: v){
        lis.insert(x);
        auto it = lis.upper_bound(x);
        if(it != lis.end()){
            lis.erase(it);
        }
    }
    return lis.size();
}

int main(){

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

int tt; cin>>tt;
while(tt--){
  cout<<returnLIS()<<endl;
}

return 0;
}
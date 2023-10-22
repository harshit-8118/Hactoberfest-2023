// Harshit Shukla
#include<bits/stdc++.h>
using namespace std;

int returnLIS(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    vector<int> lis;
    for(auto x: v){
        auto it = upper_bound(lis.begin(), lis.end(), x);
        if(it == lis.end()){
            lis.push_back(x);
        }
        else{
            lis[it - lis.begin()] = x;
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
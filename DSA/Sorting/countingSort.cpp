#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &v){
    int n = v.size();
    int mx = *max_element(v.begin(), v.end());
    vector<int> count(mx + 1), output(n);
    for(auto x: v){
        count[x]++;
    }
    for(auto i = 1; i <= mx; i++){
        count[i] += count[i-1];
    }
    for(auto i = 0; i < n; i++){
        output[count[v[i]] - 1] = v[i];
        count[v[i]]--;
    }
    v = output;
}

int32_t main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

int n; cin>>n;
vector<int> v(n);

for(auto &x: v) cin>>x;
countingSort(v);

for(auto x: v){
    cout<<x<<" ";
}

return 0;
}
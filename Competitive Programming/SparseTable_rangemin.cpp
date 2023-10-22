#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sparse;
vector<int> arr;
int sz, N;

// can use algo for range max query also.
// sparse table takes nlog(n) time pre computation.

void buildSparseTable(){
    sparse = vector<vector<int>> (sz+1, vector<int>(N));
    sparse[0] = arr;
    for(int i = 1; i <= sz; i++){
        for(int j = 0; j + (1 << i) <= N; j++){
            sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j + (1 << (i-1))]);
            // sparse[i][j] = max(sparse[i-1][j], sparse[i-1][j + (1 << (i-1))]);
        }
    }
}

int rangeMinQuery(int l, int r){
    int lg = log2(r -l + 1);
    return min(sparse[lg][l], sparse[lg][r - (1 << lg) + 1]);
    // return max(sparse[lg][l], sparse[lg][r - (1 << lg) + 1]);
}
int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

    cin>>N;
    sz = log2(N);
    arr = vector<int>(N);
    for(auto &x: arr){
        cin>>x;
    }
    buildSparseTable();
    int q, l, r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        int val = rangeMinQuery(l, r);
        cout<<val<<endl;
    }

return 0;
}
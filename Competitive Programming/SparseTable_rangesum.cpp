// Harshit-8118
#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> sparse;
vector<int> v;
int N, sz;
void buildSparseTable(){
    sparse = vector<vector<int>> (sz+1, vector<int> (N));
    sparse[0] = v;
    for(int i = 1; i <= sz; i++){
        for(int j = 0; j + (1 << i) <= N; j++){
            sparse[i][j] = sparse[i-1][j] + sparse[i-1][j + (1 << (i-1))];
        }
    }
}

int rangeSum(int l, int r){
    int sum = 0;
    int i = sz;
    while(i >= 0){
        if(l + (1 << i) <= r + 1){
            sum += sparse[i][l];
            l += (1<<i);
        } i--;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

    cin>>N;
    sz = log2(N);
    v = vector<int>(N);
    for(int i = 0; i< N; i++){ cin>>v[i]; }
    buildSparseTable();
    int q, l, r; 
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<rangeSum(l, r)<<endl;
    }
  return 0;
}
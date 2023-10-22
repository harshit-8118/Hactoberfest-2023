#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE     // #include "C://Users//hhars//OneDrive//Documents//CPP Practice//Algo//config.h"
// #include "Algo/debug.h"   // include definitions
// #else
// #define // fix(x)
// #endif

class fenwickTree{
    public:
    vector<vector<int>> bit;
    int m, n;
    fenwickTree(int m, int n){
        this->n = n; this->m = m;
        bit.resize(m+1, vector<int>(n+1, 0));
    }
    int move(int a){ return (a & -a); }
    fenwickTree(vector<vector<int>> &a): fenwickTree(a.size(), a[0].size()){
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                update(i+1, j+1, a[i][j]);
    }
    void update(int x, int y, int val){
        for(; x <= m; x += move(x))
            for(int y1 = y; y1 <= n; y1 += move(y1))
                bit[x][y1] += val;
    }
    int sum(int x, int y){        
        int s = 0;
        for( ; x > 0; x -= move(x))   
            for(int y1 = y; y1 > 0; y1 -= move(y1))
                s += bit[x][y1];
        return s;
    }
    int sum(int x1, int y1, int x2, int y2){
        return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
    }
};

int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     #include "Algo/config.h"
// #endif

int n, m;
cin>>m>>n;
vector<vector<int>> mat(m, vector<int>(n));
for(auto &x: mat)
    for(auto &y: x)
        cin>>y;

// fix(mat);
fenwickTree ft(mat);
// fix(ft.bit);

int q;cin>>q;
int x1, y1, x2, y2;
while(q--){
    int type, val; cin>>type;
    if(type == 1){
        cin>>x1>>y1>>val;
        ft.update(x1, y1, val - mat[x1-1][y1-1]);
        mat[x1-1][y1-1] = val;
        // fix(ft.bit);
    }
    else{
        cin>>x1>>y1>>x2>>y2;
        cout<<ft.sum(x1, y1, x2, y2)<<endl;
    }
}

return 0;
}
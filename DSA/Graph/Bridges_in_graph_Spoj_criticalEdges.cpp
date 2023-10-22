#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>
#define vv32 vector<v32>
#define pb emplace_back
#define ppi pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for (int i = s; i < e; i++)
#define forb(i, e, s) for (int i = e; i >= s; i--)

priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
v32 tin, low, vis;
vv32 adj,
    int timer = 0;
void dfs(int s, int p){
    vis[s] = 1;
    tin[s] = low[s] = timer++;
    for (auto x : adj[s]){
        if (x == p)
            continue;
        if (vis[x])
            low[s] = min(low[s], tin[x]);
        else{
            dfs(x, s);
            low[s] = min(low[s], low[x]);
            if (low[x] > tin[s])
                pq.push({min(x, s), max(x, s)});
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    timer = 0;
    low.assign(n + 1, -1);
    tin.assign(n + 1, -1);
    vis.assign(n + 1, 0);
    g.resize(n + 1);
    while (m--){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(g, 1, -1);
    if (pq.size() == 0){
        cout << "Sin bloqueos" << endl;
        return;
    }
    cout << pq.size() << nline;
    while (pq.size()){
        auto x = pq.top();
        pq.pop();
        cout << x.fi << " " << x.se << nline;
    }
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt = 1;
    cin >> tt;
    int t = 1;
    while (tt--){
        cout << "Caso #" << t++ << endl;
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>
#define vv32 vector<vector<int>>
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for(int i = s; i < e; i++)
#define forb(i, e, s) for(int i = e; i >= s; i--)

int timer = 0;
vv32 g;
v32 low, tin, vis;
unordered_set<int> h;
void dfs(int s, int p = -1){
    low[s] = tin[s] = timer++;
    vis[s] = 1;
    int children = 0;
    for (auto x : g[s]){
        if (x == p)
            continue;
        if (vis[x])
            low[s] = min(low[s], tin[x]);
        else{
            dfs(x, s);
            low[s] = min(low[s], low[x]);
            if (low[x] >= tin[s] and p != -1)
                h.insert(s);
            children++;
        }
    }
    if (p == -1 and children > 1)
        h.insert(s);
}
void solve(int n, int m)
{
    g.resize(n + 1);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    vis.assign(n + 1, 0);
    timer = 0;
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    cout << h.size() << endl;
    h.clear();
    g.clear();
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int _, __;
    while (1)
    {
        cin >> _ >> __;
        if (_ == 0 and __ == 0)
            break;
        solve(_, __);
    }

    return 0;
}
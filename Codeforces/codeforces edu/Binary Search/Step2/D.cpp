//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define forf(i, s, e) for (int i = s; i < e; i++)

struct node{
    ll t, y, z;
};

ll inflated(node emp, ll ts)
{
    ll res = 0;
    res += emp.z * (ts / (emp.t * emp.z + emp.y));
    ll rem = ts % (emp.t * emp.z + emp.y);
    res += (rem / (emp.z * emp.t) >= 1) ? emp.z : (rem / emp.t);
    return res;
}
bool goodTimeSlot(ll ts, int m, vector<node> &assistants)
{
    ll Tballoons = 0;
    for (auto &x : assistants)
        Tballoons += inflated(x, ts);
    return Tballoons >= m;
}
void Solution()
{
    ll m, n;
    cin >> m >> n;
    vector<node> assistants(n);
    for (auto &x : assistants)
        cin >> x.t >> x.z >> x.y;

    int tl = 0, tr = 1e7 + 1;
    while (tl < tr){
        ll timeslot = (tl + tr) / 2;
        if (goodTimeSlot(timeslot, m, assistants))
            tr = timeslot;
        else
            tl = timeslot + 1;
    }
    cout << tr << nline;
    forf(i, 0, n){
        ll bursted = inflated(assistants[i], tr);
        cout << min(m, bursted) << " ";
        m -= min(bursted, m);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt = 1;
    while (tt--){
        Solution();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
class Solution
{
public:
    ll checkInversion(vector<ll> &v, ll s, ll e)
    {
        ll cnt = 0;
        if (s < e)
        {
            ll m = (s + e) / 2;
            cnt += checkInversion(v, s, m);
            cnt += checkInversion(v, m + 1, e);
            cnt += merge(v, s, m, e);
        }
        return cnt;
    }
    ll merge(vector<ll> &v, ll s, ll m, ll e)
    {
        ll n1 = m - s + 1, n2 = e - m;
        vector<ll> left(n1), right(n2);
        for (ll i = 0; i < n1; i++)
        {
            left[i] = v[s + i];
        }
        for (ll i = 0; i < n2; i++)
        {
            right[i] = v[m + 1 + i];
        }
        ll i = 0, j = 0, k = s, res = 0;
        while (i < n1 and j < n2)
        {
            if (left[i] <= right[j])
            {
                v[k] = left[i++];
            }
            else
            {
                res += (n1 - i);
                v[k] = right[j++];
            }
            k++;
        }
        while (i < n1)
        {
            v[k++] = left[i++];
        }
        while (j < n2)
        {
            v[k++] = right[j++];
        }
        return res;
    }
    ll countInversion(vector<ll> &v)
    {
        return checkInversion(v, 0, ll(v.size() - 1));
    }
};

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution st;
    vector<ll> v;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    cout << st.countInversion(v) << endl;

    return 0;
}
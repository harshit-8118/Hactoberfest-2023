//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;

    ll s = 0, e = 1e12;
    while (s + 1 < e){
        ll mid = (s + e) / 2;
        ll sum = 0;
        for (auto &x : v)
            sum += min(x, mid);
        if (sum >= mid * k)
            s = mid;
        else
            e = mid;
    }

    cout << s;

    return 0;
}
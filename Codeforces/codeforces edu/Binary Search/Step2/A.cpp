//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll w, h, n;
    cin >> w >> h >> n;
    ll s = 1, e = n * max(h, w);
    ll ans;
    while (s <= e)
    {
        ll length = s + (e - s) / 2;
        if (length >= w)
        {
            ll a = length / w;
            ll b = n / a + (n % a != 0);
            if (b * h <= length)
            {
                ans = length;
                e = length - 1;
            }
            else
                s = length + 1;
        }
        else
        {
            s = length + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
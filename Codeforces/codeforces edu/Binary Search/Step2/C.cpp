//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    int temp = min(x, y);
    y = max(x, y);
    x = temp;

    ll s = 0, e = 2e9 + 1;
    ll val, copys;
    while (s + 1 < e)
    {
        ll mid = (s + e) / 2;
        if (mid < x)
        {
            s = mid;
            continue;
        }
        val = mid - x;
        copys = val / x + val / y + 1;
        if (copys >= n)
        {
            e = mid;
        }
        else
        {
            s = mid;
        }
    }
    cout << e << nline;

    return 0;
}
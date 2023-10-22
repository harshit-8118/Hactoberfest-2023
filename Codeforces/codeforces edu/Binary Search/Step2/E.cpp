//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double c;
    cin >> c;
    double s = 0, e = 1e6;
    int q = 100;
    while (q--)
    {
        double mid = (s + e) / 2;
        double val = mid * mid + sqrt(mid);
        if (val > c)
            e = mid;
        else
            s = mid;
    }
    cout << fixed << setprecision(10);
    cout << e;
    return 0;
}
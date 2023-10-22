//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

int arr[10001];
int fn(double m, int n)
{
    int partition = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] >= m)
            partition += arr[i] / m;
    return partition;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int iter = 50;
    double s = 0, e = 1e7 + 1;
    while (iter--)
    {
        double mid = (s + e) / 2;
        cout << fixed << setprecision(10);
        int val = fn(mid, n);
        if (val >= k)
            s = mid;
        else
            e = mid;
    }
    cout << s << endl;

    return 0;
}
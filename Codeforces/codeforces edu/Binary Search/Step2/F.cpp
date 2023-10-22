//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> perm;
bool good(int m)
{
    unordered_set<int> h;
    for (int i = 0; i < m; i++)
        h.insert(perm[i] - 1);
    int j = 0, i = 0;
    while (i < t.length())
    {
        if (j < p.length() and t[i] == p[j] and h.count(i) == 0)
            j++;
        i++;
    }
    h.clear();
    return j == p.length();
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> p;
    perm.resize(t.length());
    for (auto &x : perm)
        cin >> x;
    int s = 0, e = t.length() - p.length() + 1;
    while (s + 1 < e)
    {
        int mid = (s + e) / 2;
        if (good(mid))
            s = mid;
        else
            e = mid;
    }
    cout << s;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void mergesort(vector<int> &v, int s, int e)
    {
        if (s < e)
        {
            int m = (s + e) / 2;
            mergesort(v, s, m);
            mergesort(v, m + 1, e);
            merge(v, s, m, e);
        }
    }
    void merge(vector<int> &v, int s, int m, int e)
    {
        int n1 = m - s + 1, n2 = e - m;
        vector<int> left(n1), right(n2);
        for (int i = 0; i < n1; i++)
        {
            left[i] = v[s + i];
        }
        for (int i = 0; i < n2; i++)
        {
            right[i] = v[m + 1 + i];
        }
        int i = 0, j = 0, k = s;
        while (i < n1 and j < n2)
        {
            if (left[i] <= right[j])
            {
                v[k] = left[i++];
            }
            else
            {
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
    }
    void sort(vector<int> &v)
    {
        mergesort(v, 0, int(v.size() - 1));
    }
};

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution st;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    st.sort(v);
    for (auto x : v)
        cout << x << " ";

    return 0;
}
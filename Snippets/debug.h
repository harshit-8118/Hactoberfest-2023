#define fix(x) cerr<<#x<<" ";_print_(x);cerr<<endl;

#define ll long long int
#define ull unsigned long long
#define lld long double
#define nline "\n"
#define sz(x) (x).size()
#define inf INT_MAX         // 1e18 + 7
#define Mod 1000000007      // 998244353
#define pi 3.141592653589793238462
#define fi first
#define se second
#define v32 vector<int>     //  #define v64 vector<ll>
#define vv32 vector<v32>    //  #define vv64 vector<v64>
#define ppi pair<int,int>   //  #define ppl pair<ll,ll>
#define vp32 vector<ppi>    //  #define vp64 vector<ppl>
#define mp32 map<int,int>   //  #define mp64 map<ll, ll>
template<class T> using pqmax = priority_queue<T>;
template<class T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
#define pb emplace_back
#define mpr make_pair
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for(int i = s; i < e; i++)
#define forb(i, e, s) for(int i = e; i >= s; i--)

void _print_(int x) { cerr << x; }
void _print_(ll x) { cerr << x; }
void _print_(ull x) { cerr << x; }
void _print_(double x) { cerr << x; }
void _print_(lld x) { cerr << x; }
void _print_(char x) { cerr << x; }
void _print_(string x) { cerr << x; }

template <class T, class V>
void _print_(pair<T, V> p);
template <class T>
void _print_(vector<T> v);
template <class T, size_t sz>
void _print_(array<T, sz> v);
template <class T>
void _print_(deque<T> v);
template <class T>
void _print_(set<T> s);
template <class T>
void _print_(unordered_set<T> s);
template <class T>
void _print_(multiset<T> m);
template <class T, class V>
void _print_(map<T, V> m);
template <class T, class V>
void _print_(unordered_map<T, V> m);
template <class T>
void _print_(priority_queue<T, vector<T>, greater<T>> pq);
template <class T>
void _print_(priority_queue<T> pq);

template <class T, class V>
void _print_(pair<T, V> p)
{
    cerr << "{";
    _print_(p.fi);
    cerr << ", ";
    _print_(p.se);
    cerr << "}";
}
template <class T>
void _print_(vector<T> v)
{
    cerr << "[ ";
    for (T x : v)
    {
        _print_(x);
        cerr << ' ';
    }
    cerr << "]";
}
template <class T, size_t sz>
void _print_(array<T, sz> v)
{
    cerr << "[ ";
    for (T x : v)
    {
        _print_(x);
        cerr << ' ';
    }
    cerr << "]";
}
template <class T>
void _print_(deque<T> v)
{
    cerr << "[ ";
    for (T x : v)
    {
        _print_(x);
        cerr << ' ';
    }
    cerr << "]";
}
template <class T>
void _print_(set<T> s)
{
    cerr << "[ ";
    for (T x : s)
    {
        _print_(x);
        cerr << ' ';
    }
    cerr << "]";
}
template <class T>
void _print_(unordered_set<T> h)
{
    cerr << "[ ";
    for (T x : h)
    {
        _print_(x);
        cerr << ' ';
    }
    cerr << "]";
}
template <class T>
void _print_(multiset<T> m)
{
    cerr << "[ ";
    for (T x : m)
    {
        _print_(x);
        cerr << ' ';
    }
    cerr << "]";
}
template <class T, class V>
void _print_(map<T, V> m)
{
    cerr << "[ ";
    for (auto x : m)
    {
        _print_(x);
        cerr << ' ';
    }
    cerr << "]";
}
template <class T, class V>
void _print_(unordered_map<T, V> m)
{
    cerr << "[ ";
    for (auto x : m)
    {
        _print_(x);
        cerr << ' ';
    }
    cerr << "]";
}
template <class T>
void _print_(priority_queue<T, vector<T>, greater<T>> pq)
{
    while (pq.size())
    {
        _print_(pq.top());
        cerr << ' ';
        pq.pop();
    }
}
template <class T>
void _print_(priority_queue<T> pq)
{
    while (pq.size())
    {
        _print_(pq.top());
        cerr << ' ';
        pq.pop();
    }
}

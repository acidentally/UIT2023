/*
Good luck for those who are trying your best
May the most glorious victory come
File name: Dver2.cpp
Code by : acident / lckintrovert
Created since : 14/09/2023 ~~ 14:39:04
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
typedef pair<pi, int>       ppi;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;

struct Edge {
    int u, v, w;
    Edge() = default;
    Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
    bool operator < (const Edge &e) {
        return w < e.w;
    }
};
vi p, sz;
int n;
void init() {
    p.resize(n + 10); sz.resize(n + 10);
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}
int find(int k) {
    if(k == p[k]) return k;
    return p[k] = find(p[k]);
}
void connect(int u, int v) {
    u = find(u); v = find(v);
    if(u < v) swap(u, v);
    p[u] = v;
    sz[v] += sz[u];
}

vector<Edge> edges;
vi preSum, weight;
int q, u, v, w;
int l, r, curAns;
inline void solve() {
    cin >> n >> q;
    init();
    for(int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        edges.pb(Edge(u, v, w));
    }
    sort(all(edges));
    preSum.pb(0);
    weight.pb(0);
    for(auto s : edges) {
        u = s.u; v = s.v; w = s.w;
        u = find(u); v = find(v);
        preSum.pb(sz[u] * sz[v]);
        connect(u, v);
        weight.pb(w);
    }
    for(int i = 1; i < preSum.size(); i++) {
        preSum[i] += preSum[i - 1];
    }
    while(q--) {
        cin >> l >> r;
        int left = lower_bound(all(weight), l) - weight.begin() - 1;
        int right = upper_bound(all(weight), r) - weight.begin() - 1;
        // cerr << left << ' ' << right << endl;
        cout << preSum[right] - preSum[left] << ' ';
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("costquery.INP", "r", stdin);
    freopen("costquery.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/
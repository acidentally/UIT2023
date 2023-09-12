/*
Good luck for those who are trying your best
May the most glorious victory come
File name: D.cpp
Code by : acident / lckintrovert
Created since : 12/09/2023 ~~ 10:16:25
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
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
template<class T1> T1 abs(T1 a) {return max(a, -a);}
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
 
struct DSU {
    vi p;
    DSU() : p(maxn) {}
    void createDSU(int l) {
        for(int i = 1; i <= l; i++) p[i] = i;
    }
    int find(int v) {
        if(v == p[v]) return v;
        return p[v] = find(p[v]);
    }
    void connect(int u, int v) {
        u = find(u); v = find(v);
        p[u] = v;
    }
} g1;

int n, k, q, u, v, x;
vector<pi> a;
int val[maxn] = {};
void solve() {
    cin >> n >> k >> q;
    g1.createDSU(n + 10);
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x >= k) a.pb(mp(x, i));
    }
    int tplt = n - 1;
    n = a.size();
    for(int i = 0; i < n && tplt; i++) {
        for(int j = i + 1; j < n && tplt; j++) {
            if(g1.find(a[i].se) == g1.find(a[j].se)) continue;
            if(__gcd(a[i].fi, a[j].fi) >= k) {g1.connect(a[i].se, a[j].se); tplt--;}
        }
    }
    while(q--) {
        cin >> u >> v;
        if(tplt == 0) {
            cout << "Y";
            continue;
        }
        if(g1.find(u) == g1.find(v)) cout << "Y";
        else cout << "N";
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("gcd-graph.INP", "r", stdin);
    freopen("gcd-graph.OUT", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/
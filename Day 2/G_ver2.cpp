/*
Good luck for those who are trying your best
May the most glorious victory come
File name: G_ver2.cpp
Code by : acident / lckintrovert
Created since : 15/09/2023 ~~ 21:14:09
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
typedef unsigned long long  ull;
int const mod       =       1e9 + 7;
int const maxn      =       2e5 + 10;
int const INF       =       1e18;

//DSU------------------------
vi p;
int find(int k) {
    if(k == p[k]) return k;
    return p[k] = find(p[k]);
}
void connect(int u, int v) {
    u = find(u); v = find(v);
    p[u] = v;
}
//End of DSU ----------------

//Graph Edge-----------------
struct Edge {
    int u, v, w, idx;
    Edge() = default;
    Edge(int u_, int v_, int w_, int i_) : u(u_), v(v_), w(w_), idx(i_) {}
    bool operator < (const Edge &e) {
        return w < e.w;
    }
};
vector<Edge> e;
//End of Graph Edge ---------
int n, m, u, v, idx, START;
unsigned long long w, mulConst;
vi couting;
vector<pi> a[maxn] = {};
bool dfs(int k, int i = -1, int p = -1) {
    for(auto s : a[k]) {
        if(s.fi == p) continue;
        if(s.fi == START) {
            couting.pb(i);
            return 1;
        }
        if(dfs(s.fi, s.se, k)) {
            couting.pb(i);
            return 1;
        }
        if(!couting.empty()) return 1;
    }
    return 0;
}

inline void solve() {
    cin >> n >> m >> mulConst;
    p.resize(n + 10);
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        e.pb(Edge(u, v, w, i));
    }    
    sort(all(e));
    for(auto ed : e) {
        // cerr << ed.u << ' ' << ed.v << ' ' << ed.w << endl;
        u = find(ed.u); v = find(ed.v);
        if(u != v) {
            connect(ed.u, ed.v);
            a[ed.u].pb(mp(ed.v, ed.idx));
            a[ed.v].pb(mp(ed.u, ed.idx));
        }
        else {
            START = ed.u;
            w = ed.w; 
            a[ed.u].pb({ed.v, ed.idx});
            a[ed.v].pb({ed.u, ed.idx});
            dfs(ed.u, ed.idx);
            reverse(all(couting));
            cout << (ull)(w * w + mulConst * (ull)couting.size()) << endl;
            cout << START << ' ' << couting.size() << endl;
            for(auto s : couting) cout << s << ' ';
            exit(0);
        }
    }
    cout << "Poor girl";
    
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("ginger.INP", "r", stdin);
    freopen("ginger.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}
/*A place to scribble thoughts

*/
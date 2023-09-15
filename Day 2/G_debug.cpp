/*
Good luck for those who are trying your best
May the most glorious victory come
File name: G_debug.cpp
Code by : acident / lckintrovert
Created since : 15/09/2023 ~~ 22:59:46
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
int const mod       =       1e9 + 7;
int const maxn      =       2e5 + 10;
int const INF       =       1e18;

struct Edge {
    int u, v, w, i;
    Edge() = default;
    Edge(int u_, int v_, int w_, int i_) : u(u_), v(v_), w(w_), i(i_) {}
    operator < (const Edge &e) {
        return w < e.w;
    }
};
vector<Edge> e;

vi p;
int find(int k) {
    if(k == p[k]) return k;
    return p[k] = find(p[k]);
}
void connect(int u, int v) {
    u = find(u); v = find(v);
    p[u] = v;
}
//End of Edge and DSU;



int n, m, u, v, w, mulConst, START;
bool checkEdge[maxn] = {}, found = 0;
vi couting;
vector<pi> a[maxn] = {};
void dfs(int k, int type) {
    // cerr << k << ' ';
    if(k == START) {
        couting.pb(type);
        found = 1;
        return;
    }
    for(auto s : a[k]) {
        if(checkEdge[s.se]) continue;
        checkEdge[s.se] = 1;
        dfs(s.fi, s.se);
        if(found) {
            couting.pb(type);
            return;
        }
    }
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
    for(auto s : e) {
        u = find(s.u); v = find(s.v);
        a[s.u].pb(mp(s.v, s.i));
        a[s.v].pb(mp(s.u, s.i));
        if(u == v) {
            START = s.u;
            for(auto thing : a[START]) {
                checkEdge[thing.se] = 1;
                dfs(thing.fi, thing.se);
                checkEdge[thing.se] = 0;
                if(found) break;
            }
            // couting.pb(w);
            cout << s.w * s.w + mulConst * couting.size() << endl;
            cout << START << ' ' << couting.size() << endl;
            for(auto thing : couting) cout << thing << ' ';
            exit(0);
        }
        connect(u, v);
    }
    cout << "Poor girl";
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/
/*
Good luck for those who are trying your best
May the most glorious victory come
File name: Ever2.cpp
Code by : acident / lckintrovert
Created since : 14/09/2023 ~~ 11:31:51
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
int const maxn      =       1e5 + 10;
int const INF       =       1e18;

struct Edge {
    int u, v, w;
    Edge() = default;
    Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
    bool operator < (const Edge &e) const {
        return w < e.w;
    }
};

vector<Edge> edges;
Edge cur;
vector<pi> a[maxn] = {};
int n, q, u, v, w, l, r;
int cnt, temp = 0, absNot, curW;
void dfs(int k, int p = -1) {
    for(auto s : a[k]) {
        if(s.se >= curW || s.fi == absNot || s.fi == p) continue;
        cnt++;
        dfs(s.fi, k);
    }
}
inline void solve() {
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        edges.pb(Edge(u, v, w));
        a[u].pb(mp(v, w));
        a[v].pb(mp(u, w));
    }
    sort(all(edges));
    cerr << endl;
    while(q--) {
        cin >> l >> r;
        int ans = 0;
        // cerr << l << ' ' << r << endl;
        for(auto s : edges) {
            if(s.w > r) break;
            if(s.w >= l) {
                cnt = 1; absNot = s.v; curW = s.w;
                dfs(s.u);
                temp = cnt;
                cnt = 1; absNot = s.u;
                dfs(s.v);
                ans += temp * cnt;
            }
        }
        cout << ans << ' ';
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/
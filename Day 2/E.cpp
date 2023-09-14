/*
Good luck for those who are trying your best
May the most glorious victory come
File name: E.cpp
Code by : acident / lckintrovert
Created since : 14/09/2023 ~~ 10:59:55
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
int n, q, u, v, w;
int l, r, ans1, ans2;
vi e[maxn] = {}, temp;
bool vis[maxn] = {};
int cur = 0;
void dfs(int k, int p = -1) {
    vis[k] = 1;
    for(auto s : e[k]) {
        if(s == p) continue;
        cur++;
        dfs(s, k);
    }
}
inline void solve() {
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        edges.pb(Edge(u, v, w));
    }
    sort(all(edges));
    while(q--) {
        cin >> l >> r;
        ans1 = ans2 = 0;

        for(int i = 1; i <= n; i++) e[i].clear();
        for(auto s : edges) {
            if(s.w > r) break;
            e[s.u].pb(s.v);
            e[s.v].pb(s.u);
        }
        memset(vis, 0, sizeof(vis));
        temp.clear();
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                cur = 1;
                dfs(i);
                temp.pb(cur);
            }
        }
        cur = 0;
        for(int i = 0; i < temp.size(); i++) {
            cur += temp[i];
            ans1 += temp[i] * temp[i];
        }
        ans1 = (cur * cur - ans1) / 2;
        for(int i = 1; i <= n; i++) e[i].clear();
        for(auto s : edges) {
            if(s.w >= l) break;
            e[s.u].pb(s.v);
            e[s.v].pb(s.u);
        }

        memset(vis, 0, sizeof(vis));
        temp.clear();
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                cur = 1;
                dfs(i);
                temp.pb(cur);
            }
        }
        cur = 0;
        for(int i = 0; i < temp.size(); i++){
            ans2 += temp[i] * temp[i];
            cur += temp[i];
        }
        ans2 = (cur * cur - ans2) / 2;
        cout << ans2 - ans1 << ' ';
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
a1 a2 .... an
ai * aj với mọi ij
(a1 + a2 + a3 + ... + an)^2 = a1^2 + a2^2 + ... + an^2 + 2(tổng)
*/
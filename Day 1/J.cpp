/*
Good luck for those who are trying your best
May the most glorious victory come
File name: J.cpp
Code by : acident / lckintrovert
Created since : 17/09/2023 ~~ 14:07:53
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
    bool operator < (const Edge &e) const {return w < e.w;}
};
vector<Edge> e;

//DSU time 
int p[maxn] = {};
int find(int k) {
    if(k == p[k]) return k;
    return p[k] = find(p[k]);
}
void connect(int u, int v) {
    u = find(u); v = find(v);
    p[u] = v;
}
// End of DSU
void Dijkstra(void) {
}

int n, m, u, v, c, s, t;
inline void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--) {
        cin >> u >> v;
        connect(u, v);
    }
    cin >> s >> t;
    int s_ = find(s), t_ = find(t);
    if(s_ != t_) {
        cout << -1;
        return;
    }
    Dijkstra();
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("dijkstra.INP", "r", stdin);
    freopen("dijkstra.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/
/*
Good luck for those who are trying your best
May the most glorious victory come
File name: C.cpp
Code by : acident / lckintrovert
Created since : 12/09/2023 ~~ 16:42:32
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
// #define int                 long long
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
int const maxn      =       5e4 + 50;
int const INF       =       (1ll << 30) - 1;

struct Edge {
    int u, v, w;
    Edge(int f = 0, int t = 0, int c = 0) : u(f), v(t), w(c) {}
    void input() {
        cin >> u >> v >> w;
    }
    bool operator < (const Edge &e) {
        return w < e.w;
    }
} e[maxn];

vi a[maxn];
int vertex, paths;
bool checked[maxn];
int low[maxn], ids[maxn];
int id = 0, tplt = 0;
stack<int> st;
void dfs(int u) {
    low[u] = ids[u] = ++id;
    st.push(u);
    for(auto v : a[u]) {
        if(!checked[v]) {
            if(ids[v] == 0) {
                dfs(v);
                minimize(low[u], low[v]);
            } else minimize(low[u], ids[v]);
        }
    }
    if(low[u] == ids[u]) {
        if(++tplt > 1) throw -1;
        while(1) {
            int v = st.top(); st.pop();
            checked[v] = true;
            if (u == v) break;
        }
    }
}

bool ask(int l, int r) {
    if (l > r) return 0;
    memset(ids, 0, (vertex + 1) * 10);
    memset(checked, false, (vertex + 1) * 10);
    memset(low, 0, (vertex + 1) * 10);

    for(int i = 1; i <= vertex; i++) a[i].clear();
    id = tplt = 0;
    
    while (!st.empty()) st.pop();
    for(int i = l; i <= r; i++) a[e[i].u].push_back(e[i].v);
    for(int i = 1; i <= vertex; i++) {
        if (ids[i] == 0) {
            try {
                dfs(i);
            } catch (int x) {
                return 0;
            }
        }
    }
    return (tplt == 1);
}

void solve() {
    cin >> vertex >> paths;
    for(int i = 1; i <= paths; i++) e[i].input();
    sort(e + 1, e + paths + 1);
    int res = INF, r = 1;
    for(int l = 1; l <= paths; l++) {
        while (r <= paths && !ask(l, r)) r++;
        if (r > paths) break;
        minimize(res, e[r].w - e[l].w);
    }
    cout << (res < INF ? res : -1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef ONLINE_JUDGE
    freopen("scc.inp", "r", stdin);
    freopen("scc.out", "w", stdout);
    #endif 
    solve();
}
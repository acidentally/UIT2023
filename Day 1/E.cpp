/*
Good luck for those who are trying your best
May the most glorious victory come
File name: E.cpp
Code by : acident / lckintrovert
Created since : 13/09/2023 ~~ 08:11:59
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
int const mod       =       998244353;
int const maxn      =       2e5 + 10;
int const INF       =       1e18;
 
int n, m, ans = 0;
int C[5][maxn] = {};
vi a[maxn] = {}, query[maxn] = {};
void init() {
    for(int u = 1; u <= n; u++) {
        if(a[u].size() < 4) continue;
        for(auto v : a[u]) {
            if(a[v].size() < 3) continue;
            if(a[u].size() > a[v].size() || (a[u].size() == a[v].size() && u > v)) {
                query[u].pb(v);
            }
        }
    }
    for(int i = 0; i <= n; i++) {
        C[0][i] = 1;
        if(i == 0) continue;
        C[1][i] = i;
        if(i >= 2) C[2][i] = (i * (i - 1) / 2) % mod;
        if(i >= 3) C[3][i] = (i * (i - 1) / 2 * (i - 2) / 3) % mod;
    }
}
bool check[maxn] = {};
int intersec, u_sat, v_sat;
void compute() {
    for(int u = 1; u <= n; u++) {
        for(auto it : a[u]) check[it] = true;

        for(auto v : query[u]) {
            intersec = 0;
            for(auto v_ : a[v]) if(check[v_]) intersec++;
            u_sat = a[u].size() - intersec - 1;
            v_sat = a[v].size() - intersec - 1;

            int times = 2;
            while(times--) {
                for(int x = 0; x < 4; x++) {
                    for(int y = 0; y < 3; y++) {
                        if((x + y <= intersec) && (3 - x <= u_sat) && (2 - y <= v_sat)) {
                            (ans += (1ll * C[3 - x][u_sat] % mod * C[2 - y][v_sat] % mod) *
                                   (C[y][intersec] % mod * C[x][intersec - y] % mod) % mod) %= mod;
                        }
                    }
                }
                swap(u_sat, v_sat);
            }
        }

        for(auto v : a[u]) check[v] = false;
    }
}
int u, v;
void solve() {
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    init();
    compute();
    cout << (ans % mod) << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("men-graph.INP", "r", stdin);
    freopen("men-graph.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/
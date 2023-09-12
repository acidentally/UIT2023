/*
Good luck for those who are trying your best
May the most glorious victory come
File name: D.cpp
Code by : acident / lckintrovert
Created since : 12/09/2023 ~~ 12:43:15
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
int const N         =       1e7 + 5;
 
//DSU--------------
int p[maxn] = {};
int find(int k) {
    if(k == p[k]) return k;
    return p[k] = find(p[k]);
}
void connect(int u, int v) {
    u = find(u); v = find(v);
    p[u] = v;
}
//DSU--------------
int n, k, q, x;
vi a[N + 1] = {};
bool check[N + 1] = {};
int u, v;
void solve() {
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        cin >> x;
        a[x].pb(i);
    }
    for(int i = k + 1; i < N; i++) {
        if(check[i]) continue;
        int idx = -1;   
        for(int j = i; j < N; j += i) {
            check[j] = true;
            for(auto s : a[j]) {
                if(idx < 0) idx = s;
                else connect(idx, s);
            }
        }
    }
    while(q--) {
        cin >> u >> v;
        if(find(u) != find(v)) cout << "N";
        else cout << "Y";
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
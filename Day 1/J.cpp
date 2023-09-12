/*
Good luck for those who are trying your best
May the most glorious victory come
File name: J.cpp
Code by : acident / lckintrovert
Created since : 12/09/2023 ~~ 14:03:51
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
typedef pair<string, int>   psi;
int const mod       =       998244353;
int const maxn      =       1e5 + 10;
int const N         =       150010;
 
int n, m, u, v, c, s, t;
int d[maxn] = {};
vector<pi> a[maxn] = {};
bool vis[maxn] = {};
void Dijkstra1() {
    priority_queue<pi, vector<pi>, greater<pi> > q;
    for(int i = 1; i <= n; i++) d[i] = (1ll << 60);
    d[s] = 0;
    q.push(mp(0, s));
    int du, dv;
    while(!q.empty()) {
        du = q.top().fi, u = q.top().se;
        q.pop();
        vis[u] = 1;
        if(du != d[u]) continue;
        for(auto s : a[u]) {
            dv = s.fi, v = s.se;
            if(dv + du < d[v]) {
                vis[v] = true;
                d[v] = du + dv;
                q.push(mp(d[v], v));
            }
        }
    }
}
void solve1() {
    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> c;
        a[u].pb(mp((int)(1ll << c), v));
        a[v].pb(mp((int)(1ll << c), u));
    }
    cin >> s >> t;
    Dijkstra1();
    if(d[t] == (1ll << 60)) cout << -1;
    else cout << (d[t] % 998244353);
}
int sqr(int k) {
    return ((k * k) % mod);
}
int divPow(int k) {
    if(k == 0) return 1;
    if(k == 1) return 2;
    if(k & 1) return ((sqr(divPow(k >> 1)) << 1) % mod);
    return (sqr(divPow(k >> 1)) % mod); 
}
void solve3() {
    cin >> n >> m;
    map<pi, int> mapp;
    while(m--) {
        cin >> u >> v >> c;
        mapp[mp(u, v)] = c;
        mapp[mp(v, u)] = c;
        a[u].pb(mp(c, v));
        a[v].pb(mp(c, u));
    }
    cin >> s >> t;
    priority_queue<pi, vector<pi>, greater<pi> > q;
    int trace[maxn] = {};
    for(int i = 1; i <= n; i++) d[i] = 210;
    d[s] = 0;
    q.push(mp(0, s));
    int du, dv;
    while(!q.empty()) {
        du = q.top().fi; u = q.top().se;
        q.pop();
        if(du != d[u]) continue;
        for(auto s : a[u]) {
            v = s.se; dv = s.fi;
            if(max(dv, du) < d[v]) {
                d[v] = max(dv, du);
                trace[v] = u;
                q.push(mp(d[v], v));
            }
        }
    }
    stack<int> ans;
	while(trace[t] != 0) {
		ans.push(t);
		t = trace[t];
	}
	ans.push(t);
    s = -1; int res = 0;
	while(!ans.empty()) {
        if(s < 0) {
            s = ans.top();
            ans.pop();
            continue;
        }
        (res += divPow(mapp[mp(s, ans.top())])) %= mod;
		s = ans.top();
		ans.pop();
	}
    cout << res;
    return;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("dijkstra.INP", "r", stdin);
    freopen("dijkstra.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    int subtask; cin >> subtask;
    // if(subtask == 1) solve1();
    if(subtask == 3) {} solve3();
}

/*A place to scribble thoughts

*/
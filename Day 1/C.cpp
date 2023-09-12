/*
Good luck for those who are trying your best
May the most glorious victory come
File name: C.cpp
Code by : acident / lckintrovert
Created since : 12/09/2023 ~~ 09:24:19
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
int const maxn      =       5e3 + 10;
int const INF       =       1e18;
 
int n, m;
int u, v, w;
vector<pi> a[maxn] = {};
int low[maxn] = {}, ids[maxn] = {}, id = 0;
stack<int> st;
bool onStack[maxn] = {};
void dfs(int k, int p = -1) {
    low[k] = ids[k] = ++id;
    onStack[k] = 1;
    st.push(k);
    for(auto s : a[k]) {
        if(s.fi == p) continue;
        dfs(s.se);
    }
}
void solve() {
    cin >> n >> m;
    int minw = INF, maxw = 0;
    while(m--) {
        cin >> u >> v >> w;
        a[u].pb(mp(v, w));
        a[v].pb(mp(u, w));
        minimize(minw, w);
        maximize(maxw, w);
    }
    dfs(1);
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/
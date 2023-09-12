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
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
int const N         =       150010;
 
int n, m, u, v, c, s, t;
string str;
psi a[maxn] = {};
string d[maxn] = {};
void Dijkstra() {
    priority_queue<psi, vector<psi>, greater<psi> > q;
    for(int i = 0; i < N; i++) str[i] = '1';
}
void solve() {
    cin >> n >> m;
    str.resize(N);
    while(m--) {
        cin >> u >> v >> c;
        str[c] = 1;
        a[u].pb({s, v});
        a[v].pb({s, u});
    }
    cin >> s >> t;
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
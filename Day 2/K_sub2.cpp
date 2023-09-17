/*
Good luck for those who are trying your best
May the most glorious victory come
File name: K_sub2.cpp
Code by : acident / lckintrovert
Created since : 17/09/2023 ~~ 07:35:49
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
int const maxn      =       3e5 + 10;

int n, k;
int p[maxn] = {}, sz[maxn] = {}, edge[maxn] = {};
int find(int k) {
    if(k == p[k]) return k;
    return p[k] = find(p[k]);
}
void connect(int u, int v) {
    u = find(u); 
    v = find(v);
    if(u != v) {
        p[u] = v;
        sz[v] += sz[u];
        edge[v] += edge[u] + 1;
    }
    else {
        edge[u]++;
    }
}
int u, v;
inline void solve() {
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        p[i] = i; sz[i] = 1; edge[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        int u_ = find(u);
        int v_ = find(v);
        if(edge[u_] < sz[u_] || edge[v_] < sz[v_]) {
            cout << "Yes" << endl;
        } else cout << "No" << endl;
        connect(u, v);
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("ladice.INP", "r", stdin);
    freopen("ladice.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/
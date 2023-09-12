/*
Good luck for those who are trying your best
May the most glorious victory come
File name: B.cpp
Code by : acident / lckintrovert
Created since : 12/09/2023 ~~ 09:13:52
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
int const maxn      =       500;
int const INF       =       1e18;
 
int n, m, u, v;
bool a[55][55] = {};
void solve() {
    cin >> n >> m;
    if(m == 0) {
        cout << 3;
        return;
    }
    while(m--) {
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    int ans = 3;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || !a[i][j]) continue;
            for(int k = 1; k <= n; k++) {
                int cur = 2;
                if(k == i || k == j) continue;
                if(a[i][k]) cur--;
                if(a[k][j]) cur--;
                minimize(ans, cur);
                if(ans == 0) {
                    cout << 0;
                    exit(0);
                }
            }
        }
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("triangle-graph.INP", "r", stdin);
    // freopen("triangle-graph.OUT", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/
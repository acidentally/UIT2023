/*
Good luck for those who are trying your best
May the most glorious victory come
File name: C.cpp
Code by : acident / lckintrovert
Created since : 14/09/2023 ~~ 10:03:50
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
int const maxn      =       1e4 + 10;
int const INF       =       1e9;

int r, c, n, x, y;
int ans = 0;
vector<pi> a;
inline void solve() {
    cin >> r >> c >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;  
        a.pb(mp(x, y));
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++) {
            int cur = INF;
            for(auto s : a) {
                minimize(cur, abs(i - s.fi) + abs(j - s.se));
            }
            maximize(ans, cur);
        }
    }
    cout << ans + 1;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("nazi.INP", "r", stdin);
    freopen("nazi.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/
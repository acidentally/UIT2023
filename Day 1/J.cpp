/*
Good luck for those who are trying your best
May the most glorious victory come
File name: J.cpp
Code by : acident / lckintrovert
Created since : 13/09/2023 ~~ 20:47:52
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

//Computing 2^c % mod
int sqr(int k) {
    return ((k * k) % mod);
}
int divMod(int c) {
    if(c == 0) return 1;
    if(c == 1) return 2;
    if(c & 1) return ((c * sqr(divMod(c >> 1))) % mod);
    return (sqr(divMod(c >> 1)) % mod);
}
//End of code

//Finding the shortest path
// uint d[maxn][2500] = {};
inline void Dijkstra(void) {

}

int n, m, u, v, c;
void solve(void) {
    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> c;
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef xONLINE_JUDGE
    freopen("dijkstra.INP", "r", stdin);
    freopen("dijkstra.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/
/*
Good luck for those who are trying your best
May the most glorious victory come
File name: K.cpp
Code by : acident / lckintrovert
Created since : 16/09/2023 ~~ 09:27:57
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
int const INF       =       1e18;

int n, l, u, v;
int curHolding[maxn] = {};
pi nxt[maxn] = {};
bool check(int curIn, int vase, int expectedIn = 0) {
    if(curHolding[vase] == 0) {
        curHolding[vase] = expectedIn;
        return 1;
    }
    int nextVase = nxt[curIn].fi == vase ? nxt[curIn].se : nxt[curIn].fi;
    curHolding[vase] = expectedIn;
    return check(curHolding[nextVase], nextVase, curIn);
}

inline void solve() {
    cin >> n >> l;
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        cin >> u >> v;
        nxt[i] = mp(u, v);
        if(curHolding[u] == 0) {
            curHolding[u] = i;
            cout << "Yes" << endl;
            continue;
        }
        if(curHolding[v] == 0) {
            curHolding[v] = i;
            cout << "Yes" << endl;
            continue;
        }
        if(check(curHolding[u], u) && curHolding[u] == 0) {
            curHolding[u] = i;
            cout << "Yes" << endl;
            continue;
        }
        if(check(curHolding[v], v) && curHolding[v] == 0) {
            curHolding[v] = i;
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;

    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // #ifdef ONLINE_JUDGE
    // freopen("ladice.INP", "r", stdin);
    // freopen("ladice.OUT", "w", stdout);
    // #endif //ONLINE JUDGE
    freopen("trau.IN", "r", stdin);
    solve();
}

/*A place to scribble thoughts

*/
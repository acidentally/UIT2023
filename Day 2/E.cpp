/*
Good luck for those who are trying your best
May the most glorious victory come
File name: E.cpp
Code by : acident / lckintrovert
Created since : 14/09/2023 ~~ 16:16:02
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
int const maxn      =       700;
int const INF       =       1e18;

struct make {
    int i, a, b;
    make() = default;
    make(int i_, int a_, int b_) : i(i_), a(a_), b(b_) {}
};

bool check[210][650][650] = {};
make TRACE[210][650][650];
#define ok(i, a, b)         check[i][a][b]
#define trace(i, a, b)      TRACE[i][a][b]

int n;
int v[maxn] = {};
char couting[maxn] = {};
inline void solve() {
    if(n == 0) return;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    ok(0, 0, 0) = 1;
    for(int i = 1; i <= n; i++) {
        for(int a = 0; a <= 600; a++) {
            for(int b = 0; b <= 600; b++) {
                if(ok(i - 1, a, b)) {
                    ok(i, a, b) = true;
                    ok(i, a ^ v[i], b) = true;
                    ok(i, a, b ^ v[i]) = true;

                    trace(i, a, b) = make(i - 1, a, b);
                    trace(i, a ^ v[i], b) = make(i - 1, a, b);
                    trace(i, a, b ^ v[i]) = make(i - 1, a, b);
                }
            }
        }
    }
    int sum = 0, ans = 0;
    make ending;
    for(int i = 1; i <= n; i++) sum ^= v[i];
    for(int a = 0; a <= 600; a++) for(int b = 0; b <= 600; b++) {
        if(ok(n, a, b)) {
            if(maximize(ans, a + b + sum ^ a ^ b)) {
                ending = make(n, a, b);
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("chemistry.INP", "r", stdin);
    freopen("chemistry.OUT", "w", stdout);
    #endif //ONLINE JUDGE

    int subtask; cin >> subtask;
    solve();
}

/*A place to scribble thoughts

*/
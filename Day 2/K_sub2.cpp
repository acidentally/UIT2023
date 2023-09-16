/*
Good luck for those who are trying your best
May the most glorious victory come
File name: K_sub2.cpp
Code by : acident / lckintrovert
Created since : 16/09/2023 ~~ 09:37:30
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
int const maxn      =       1e2 + 10;
int const INF       =       1e18;

mt19937_64 rng(time(0));

inline void solve() {
    string ans[100] = {}, s;
    int l = 35;
    // int n = rand() % maxn;
    int n = 40;
    cout << n << ' ' << l << endl;
    for(int i = 1; i <= n; i++){
        int l1 = rng() % l;
        int l2 = rng() % l;
        while(l2 == l1) l2 = rng() % l;
        cout << l1 + 1 << ' ' << l2 + 1 << endl;
    }
    // for(int i = 1; i <= 97; i++) {
    //     cin >> ans[i];
    // }
    // for(int i = 1; i <= 97; i++) {
    //     cin >> s;
    //     if(ans[i] != s) cout << "WA ON TEST " << i << endl;
    // }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // #ifdef ONLINE_JUDGE
    // freopen("trau.IN", "r", stdin);
    freopen("trau.IN", "w", stdout);
    // #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/
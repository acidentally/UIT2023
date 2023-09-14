/*
Good luck for those who are trying your best
May the most glorious victory come
File name: A.cpp
Code by : acident / lckintrovert
Created since : 14/09/2023 ~~ 09:10:37
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

int const mod       =       1e9 + 7;

int sqr(int k) {
    return (k * k) % mod;
}
int divPow(int a, int k) {
    if(k == 0) return 1;
    if(k == 1) return a % mod;
    if(k & 1) return ((a * sqr(divPow(a, k >> 1))) % mod);
    return (sqr(divPow(a, k >> 1)) % mod); 
}
int n, m, ans = 1, cur = 1;
inline void solve() {
    cin >> n >> m;
    if(n > m) swap(m, n);
    for(int i = 2; i < n; i++) {
        (cur *= i) %= mod;
        ans = (((ans * cur) % mod) * cur) % mod;
    }
    cur = (cur * n) % mod;
    ans *= divPow(cur, m - n + 1);
    cout << (ans % mod);

}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("matrix.INP", "r", stdin);
    freopen("matrix.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/
/*
Good luck for those who are trying your best
May the most glorious victory come
File name: I.cpp
Code by : acident / lckintrovert
Created since : 12/09/2023 ~~ 09:41:26
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
int const maxn      =       1e6 + 10;
int const INF       =       1e13;
 
int r, c;
void solve() {
    cin >> r >> c;
    int dp[r + 10][c + 10] = {}, a[r + 10][c + 10] = {};
    int sum = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        dp[i][c + 1] = INF;
    }
    if(r == 1) {
        cout << sum;
        return;
    }
    if(r == 2) {
        int ans = 0, res = INF;
        for(int i = 1; i <= c; i++) {
            ans += min(a[1][i], a[2][i]);
            minimize(res, max(a[1][i], a[2][i]));
        }
        cout << ans + res;
        return;
    }
    if(r * c <= 16) {
        
    }
    for(int j = 1; j <= c + 1; j++) dp[r + 1][j] = INF;
    dp[r][c] = a[r][c];
    for(int i = r; i >= 1; i--) {
        for(int j = c; j >= 1; j--) {
            if(i == r && j == c) continue;
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + a[i][j];
        }
    }
    cout << dp[1][1];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("boardgame.INP", "r", stdin);
    // freopen("boardgame.OUT", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/
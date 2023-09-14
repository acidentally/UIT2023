/*
Good luck for those who are trying your best
May the most glorious victory come
File name: I.cpp
Code by : acident / lckintrovert
Created since : 14/09/2023 ~~ 14:04:35
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

typedef vector<int>           vi;
typedef vector<vi>            vvi;
typedef pair<int, int>        pi;
typedef pair<int, pi>         pii;
typedef vector<bool>          vb;
typedef vector<vb>            vvb;
int const mod       =       1e9 + 7;
int const maxn      =       500;
int const INF       =       1e18;

int n;
char x;
vvb b(maxn, vb(maxn, 0));
vvb manip1(vvb a, bool c, int row) {
    for(int i = 1; i <= n; i++) a[row][i] = c;
    return a;
}
vvb manip2(vvb a, bool c) {
    for(int i = 1; i <= n; i++) {
        a[n >> 1][i] = c;
        a[(n >> 1)+ 1][i] = 1 - c;
    }
    return a;
}
bool checkGraph(vvb a) {
    for(int col = 1; col <= n; col++) {
        int cnt = 1;
        for(int j = 2; j <= n; j++) {
            if(a[j][col] != a[j - 1][col]) cnt = 1;
            else cnt++;
            if(cnt == (n >> 1) + 1) return 0;
        }
    }
    return 1;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;
            b[i][j] = (x == 'W');
        }
    }
    if(checkGraph(b)) {
        cout << 0;
        return;
    }
    for(int i = 0; i < 2; i++) {
        for(int row = 1; row <= n; row++) {
            if(checkGraph(manip1(b, i, row))) {
                cout << 1;
                return;
            }
        }
    }
    cout << 2;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("greedy-is-wrong.INP", "r", stdin);
    freopen("greedy-is-wrong.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/
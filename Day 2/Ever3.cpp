/*
Good luck for those who are trying your best
May the most glorious victory come
File name: Ever3.cpp
Code by : acident / lckintrovert
Created since : 15/09/2023 ~~ 10:57:07
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
int const maxn      =       202;
int const MAX       =       1024;

bool dp[202][MAX][MAX];
int n, A, B, C, sum, ifA, ifB, ifC, cntA, cntB, cntC;
bool better(int x, int y, int z) {
    if(x + y + z != A + B + C) return (x + y + z > A + B + C);
    return ((x > 0) + (y > 0) + (z > 0) > (A > 0) + (B > 0) + (C > 0));
}
inline void solve() {
    sum = A = B = 0;
    vi v;
    vector<char> couting;
    v.pb(0);
    for(int i = 1; i <= n; i++){
        cin >> C;
        v.pb(C);
        sum ^= C;
    }
    C = sum;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int a = 0; a < MAX; a++) {
            for(int b = 0; b < MAX; b++) {
                if(dp[i - 1][a][b]) {
                    dp[i][a][b] = 1;
                    dp[i][a ^ v[i]][b] = 1;
                    dp[i][a][b ^ v[i]] = 1;
                    if(better(a, b, sum ^ a ^ b)) {
                        A = a; B = b; C = sum ^ a ^ b;
                    }
                }
            }
        }
    }
    cntA = cntB = cntC = 0;
    for(int i = n; i >= 1; i--) {
        ifA = (dp[i - 1][A ^ v[i]][B] ? cntA : MAX);
        ifB = (dp[i - 1][A][B ^ v[i]] ? cntB : MAX);
        ifC = (dp[i - 1][A][B] ? cntC : MAX);
        if(ifA <= ifB && ifA <= ifC) {
            couting.pb('P');
            A ^= v[i];
            cntA++;
        }
        else if(ifB <= ifC) {
            couting.pb('V');
            B ^= v[i];
            cntB++;
        }
        else {
            couting.pb('H');
            C ^= v[i];
            cntC++;
        }
    }
    reverse(all(couting));
    for(auto s : couting) cout << s;
    cout << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("chemistry.INP", "r", stdin);
    freopen("chemistry.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    cin >> n;
    while(cin >> n) solve();
}

/*A place to scribble thoughts

*/
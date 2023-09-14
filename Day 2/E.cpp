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
int const maxn      =       1024;
int const INF       =       300;

bitset<1024> ok[202][1024] = {};

int n, v[202] = {}, A, B, C, curA, curB, curC, sum = 0, ifA, ifB, ifC;
char couting[202] = {};

inline bool better(int x, int y, int z) {
    if(x + y + z == A + B + C) 
    return (((x > 0) + (y > 0) + (z > 0)) > ((A > 0) + (B > 0) + (C > 0)));
    return (x + y + z > A + B + C);
}
inline void solve() {
    if(n == 0) exit(0);
    A = 0, B = 0;
    curA = 0, curB = 0, curC = 0;
    sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        sum ^= v[i];
    }
    memset(ok, 0, sizeof(ok));
    C = sum;
    ok[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int a = 0; a < 1024; a++) {
            for(int b = 0; b < 1024; b++) {
                if(ok[i - 1][a][b]) {
                    ok[i][a][b] = true;
                    ok[i][a ^ v[i]][b] = true;
                    ok[i][a][b ^ v[i]] = true;
                    if(better(a, b, sum ^ a ^ b)) {
                        A = a; B = b; C = sum ^ a ^ b;
                    }
                }
            }
        }
    }
    for(int i = n; i >= 1; i--) {
        ifA = ((ok[i - 1][A ^ v[i]][B]) ? curA : INF);
        ifB = ((ok[i - 1][A][B ^ v[i]]) ? curB : INF);
        ifC = ((ok[i - 1][A][B]) ? curC : INF);

        if(ifA <= ifB && ifA <= ifC) {curA++; A ^= v[i]; couting[i] = 'P';}
        else if(ifB <= ifC) {curB++; B ^= v[i]; couting[i] = 'V';}
        else {curC++; couting[i] = 'H';};
    }
    
    int i = 1;
    while(i <= n) cout << couting[i++];
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
    while(cin >> n) {
        if(n == 0) exit(0);
        solve();
    }
}

/*A place to scribble thoughts

*/
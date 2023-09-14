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

int const maxn      =       1024;
typedef vector<int>         vi;

bool ok[202][1024][1024] = {};

int n, A, B, C, curA, curB, curC, sum = 0, ifA, ifB, ifC, x;
vector<char> couting;
vi v;
inline bool better(int x, int y, int z) {
    if(x + y + z == A + B + C) 
    return (((x > 0) + (y > 0) + (z > 0)) > ((A > 0) + (B > 0) + (C > 0)));
    return (x + y + z > A + B + C);
}
void solve() {
    A = 0; B = 0; curA = 0; curB = 0; curC = 0; sum = 0;
    v.clear();
    v.pb(0);
    for(short i = 1; i <= n; i++) {
        cin >> x;
        v.pb(x);
        sum ^= v[i];
    }

    memset(ok, 0, sizeof(ok));
    C = sum;
    ok[0][0][0] = 1;

    for(short i = 1; i <= n; i++) {
        for(short a = 0; a < maxn; a++) {
            for(short b = 0; b < maxn; b++) {
                if(ok[i - 1][a][b]) {
                    ok[i][a][b] = 1;
                    ok[i][a ^ v[i]][b] = 1;
                    ok[i][a][b ^ v[i]] = 1;
                    if(better(a, b, sum ^ a ^ b)) {
                        A = a; 
                        B = b; 
                        C = sum ^ A ^ B;
                    }
                }
            }
        }
    }
    couting.clear();
    for(int i = n; i >= 1; i--) {
        ifA = ((ok[i - 1][A ^ v[i]][B]) ? curA : maxn);
        ifB = ((ok[i - 1][A][B ^ v[i]]) ? curB : maxn);
        ifC = ((ok[i - 1][A][B]) ? curC : maxn);

        if(ifA <= ifB && ifA <= ifC) {curA++; A ^= v[i]; couting.pb('P');}
        else if(ifB <= ifC) {curB++; B ^= v[i]; couting.pb('V');}
        else {curC++; couting.pb('H');};
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
    while(cin >> n) {
        solve();
    }
}

/*A place to scribble thoughts

*/
/*
Good luck for those who are trying your best
May the most glorious victory come
File name: H.cpp
Code by : acident / lckintrovert
Created since : 13/09/2023 ~~ 14:55:32
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
int const INF       =       1e18;
 
int n, x;
inline void solve() {
    cin >> n;
    stack<pi> st;
    vi a(n + 10);
    int cnt = 1;
    bool b = 1;
    int l = 0;
    for(int i = 1; i <= n; i++) {
        while(!st.empty() && st.top().se == i) {
            a[st.top().fi] = cnt++;
            st.pop();
        }
        cin >> x;
        if(x == -1) x = i + 1;
        if(x <= i || (!st.empty() && x > st.top().se)) b = 0;
        st.push(mp(i, x));
    }
    if(!b) {
        cout << "No" << endl;
        return;
    }
    while(!st.empty()) {
        a[st.top().fi] = cnt++;
        st.pop();
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("recover.INP", "r", stdin);
    freopen("recover.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    int theta, tau; 
    cin >> theta >> tau;
    while(tau--) solve();
}

/*A place to scribble thoughts

*/
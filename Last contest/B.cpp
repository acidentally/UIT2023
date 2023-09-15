/*
Good luck for those who are trying your best
May the most glorious victory come
File name: B.cpp
Code by : acident / lckintrovert
Created since : 15/09/2023 ~~ 15:20:19
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

string a[8], trash;
map<char, int> m;
int compute(string s) {
    if(s[0] == 'A') return (1 + m[s[1]]);
    return ((int)(s[0] - '0') + (m[s[1]]));
}

int ans1, ans2;
void solve() {
    cin >> a[1] >> a[2] >> a[3];
    cin >> trash >> a[4] >> a[5] >> a[6];
    vi b, c;
    for(int i = 1; i <= 3; i++) {
        c.pb(compute(a[i]));
    }
    for(int i = 4; i <= 6; i++) {
        b.pb(compute(a[i]));
    }
    sort(all(c), greater<int>());
    sort(all(b), greater<int>());
    ans1 = 0, ans2 = 0;
    for(auto i : c) ans1 += i;
    for(auto i : b) ans2 += i;
    ans1 %= 10; if(ans1 == 0) ans1 = 10;
    ans2 %= 10; if(ans2 == 0) ans2 = 10;

    if(ans1 > ans2) {
        cout << "Yes ";
        return;
    }
    if(ans1 < ans2) {
        cout << "No ";
        return;
    }
    if(c[0] < b[0]) {
        cout << "No "; return;
    }
    else {
        cout << "Yes "; return;
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("3cay.INP", "r", stdin);
    freopen("3cay.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    m['R'] = 80;
    m['C'] = 60;
    m['P'] = 40;
    m['N'] = 20;
    int tc; cin >> tc;
    while(tc--) solve();
}

/*A place to scribble thoughts

*/
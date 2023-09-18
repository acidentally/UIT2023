/*
Good luck for those who are trying your best
May the most glorious victory come
File name: chuacuulc.cpp
Code by : acident / lckintrovert
Created since : 18/09/2023 ~~ 13:15:46
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
typedef pair<int, set< int, greater<int> > > pis;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;

class Compare {
public:
    bool operator() (pis s1, pis s2) {
        if(s1.se.empty()) return 0;
        if(s2.se.empty()) return 1;
        return *s1.se.begin() < *s2.se.begin();
    }
};
priority_queue< pis, vector<pis>, Compare> pq;

inline void solve() {
    set<int, greater<int> > s1 = set<int, greater<int> > ({1, 3, 4});
    set<int, greater<int> > s2 = set<int, greater<int> > ({5});
    pq.push(mp(5, s1));
    pq.push(mp(0, s2));
    while(!pq.empty()) {
        cout << pq.top().fi << ' ';
        pq.pop();
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/